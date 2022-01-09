// g++ -std=c++14 -o fbtHttpd server.cpp
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#include <vector>
#include <sstream>
#include <cstring>
#include <cstdio>          // perror()
#include <cstdlib>         // abort()

#include <iostream>
#include <string>

using namespace std;

#define DEBUG(x)    cout << "Debug: " << x << endl
#define PANIC(msg)  {perror(msg); abort();}
#define MAXBUF      1024
#define MYPORT      15151

string buildHeader(size_t len, string ext);
string readFile(FILE* file);
int mysend(int fd, const char *buf, size_t n, int flags);


int main(int argc, char* argv[]) {
    uint16_t port = 0;
    string path = "";
    if(argc == 3){
        path = string(argv[1]);
        port = stoi(string(argv[2]));
    }else{
        return EXIT_FAILURE;
    }

    // Socket aufmachen
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    // mehrere Clients koennen Port teilen, Serveradresse direkt wiederverwendbar
    // vgl. `man 2 setsockopt`
    int y = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &y, sizeof(int));

    // IP und Port
    sockaddr_in srv;
    memset(&srv, 0, sizeof(srv));
    srv.sin_family = AF_INET;
    srv.sin_addr.s_addr = htonl(INADDR_LOOPBACK);  // 127.0.0.1
    srv.sin_port = htons(port);                  // Port 15151

    // Socket an Namen binden
    bind(fd, (const struct sockaddr *) &srv, sizeof(srv));

    // Anzahl der Verbindungen
    listen(fd, 5);

    int n = -1;
    string req;
    char buf[MAXBUF];
    int in_fd;
    for (;;) { // Server-Schleife
        // Verbindung annehmen und blockieren, bis Verbindung
        in_fd = accept(fd, NULL, NULL); // Adresse vom Komm.-Partner interessiert mich nicht

        for (;;) { // Kommunikation mit Client
            memset(buf, 0, MAXBUF);
            n = -1;
            n = recv(in_fd, buf, MAXBUF, 0);
            if (n == 0) {
                close(in_fd);  // nur den Client-Socket schliessen
                break; // raus aus der Komm.-Schleife mit Client, naechste Verbindung akzeptieren
            }

            req = (string) buf;

            //Empfangene Nachricht in zeilen aufteilen
            vector<string> result;
            stringstream reqstream(req);
            while(reqstream.good()){
                string substr;
                getline(reqstream, substr);
                result.push_back(substr);
            }

            //Erste zeile in bestandteile aufteilen
            vector<string> parsedFirstLine;
            stringstream linestream(result.at(0));
            while(linestream.good()){
                string substr;
                getline(linestream, substr, ' ');
                parsedFirstLine.push_back(substr);
            }

            string msg = "req error";
            //gucken ob get request
            if(parsedFirstLine.at(0) == "GET"){
                string filepath;
                filepath += path;
                filepath += parsedFirstLine.at(1);

                if (FILE *file = fopen(filepath.c_str(), "r")) {
                    string content = readFile(file);
                    string ext = filepath.substr(filepath.find_last_of('.'), filepath.length());
                    msg.clear();
                    msg += buildHeader(content.length(), ext);
                    msg += content;
                    mysend(in_fd, msg.c_str(), msg.length(), 0);
                    fclose(file);
                } else {
                    msg.clear();
                    msg += "Fehler 404 (Not Found)";
                    mysend(in_fd, msg.c_str(), msg.length(), 0);
                } 
            }else{
                msg.clear();
                msg = (string) buf;
                mysend(in_fd, msg.c_str(), msg.length(), 0);
            }
        }
    }

    // Sockets schliessen
    close(fd);

    return EXIT_SUCCESS;
}

string buildHeader(size_t len, string ext){
    string res;
    string type = "application/octet-stream";

    if(ext == ".html"){
        type = "text/html";
    }
    if(ext == ".txt" || ext == ".h" || ext == ".c" || ext == ".cpp"){
        type = "text/plain";
    }
    if(ext == ".pdf"){
        type = "application/pdf";
    }
    if(ext == ".png"){
        type = "image/png";
    }
    if(ext == ".jpg"){
        type = "image/jpeg";
    }
    if(ext == ".css"){
        type = "text/css";
    }

    res += "HTTP/1.1 200 OK\n";
    res += "Connection: close\n";
    res += "Content-Language: de\n";
    res += "Content-Length: ";
    res += to_string(len);
    res += "\n";
    res += "Content-Type: ";
    res += type;
    res += "\n\n";

    return res;
}

string readFile(FILE* file){
    string content;
    char line[500];
    while(fgets(line, 500, file) != NULL){
        //puts(line);
        content.append(string(line));
    }
    return content;
}

int mysend(int fd, const char *buf, size_t n, int flags){
    ssize_t bytesWritten = -1;
    while(n > 0){
        bytesWritten = send(fd, buf, n, flags);
        if(bytesWritten == -1){
            return -1;
        }
        n -= bytesWritten;
        buf += bytesWritten;
    }
    return 0;
}