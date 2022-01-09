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

int echoServer(uint16_t port);
int detectGet(string path, uint16_t port);
int detectContentType(string path, uint16_t port);
string buildHeader(size_t len, string type);
string readFile(FILE* file);


int main(int argc, char* argv[]) {
    uint16_t port = 0;
    string path = "";
    if(argc == 3){
        path = string(argv[1]);
        port = stoi(string(argv[2]));
        DEBUG("path: " << path);
        DEBUG("port: " << port);
    }else{
        DEBUG("wrong argument count");
        return EXIT_FAILURE;
    }

    detectContentType(path,port);
    //detectGet(path,port);
    //echoServer(port);

    return EXIT_SUCCESS;
}

string buildHeader(size_t len, string type){
    string res;

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

int detectContentType(string path, uint16_t port){
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
    DEBUG("Server: auf " << inet_ntoa(srv.sin_addr) << ":" << port);

    // Anzahl der Verbindungen
    listen(fd, 5);

    int n = -1;
    string req;
    char buf[MAXBUF];
    int in_fd;
    for (;;) { // Server-Schleife
        // Verbindung annehmen und blockieren, bis Verbindung
        DEBUG("\n\nServer: Warte auf Verbindung");
        in_fd = accept(fd, NULL, NULL); // Adresse vom Komm.-Partner interessiert mich nicht

        DEBUG("Server: Verbindung etabliert");
        for (;;) { // Kommunikation mit Client
            DEBUG("Server: lese Daten");
            memset(buf, 0, MAXBUF);
            n = -1;
            n = recv(in_fd, buf, MAXBUF, 0);
            DEBUG("Server: n=" << n << " Bytes empfangen");
            if (n == 0) {
                // Besser mit errno pruefen!
                DEBUG("Server: n==0 => SOCKET CLOSED ON REMOTE END?!");
                close(in_fd);  // nur den Client-Socket schliessen
                break; // raus aus der Komm.-Schleife mit Client, naechste Verbindung akzeptieren
            }
            DEBUG("Server: Empfangene Botschaft: " << buf << "<<<\n\n");

            req = (string) buf;

            vector<string> result;
            stringstream reqstream(req);
            while(reqstream.good()){
                string substr;
                getline(reqstream, substr);
                result.push_back(substr);
            }


            vector<string> parsedFirstLine;
            stringstream linestream(result.at(0));
            while(linestream.good()){
                string substr;
                getline(linestream, substr, ' ');
                parsedFirstLine.push_back(substr);
            }

            string msg = "req error";
            if(parsedFirstLine.at(0) == "GET"){
                DEBUG("get req detected");
                string filepath;
                filepath += path;
                filepath += parsedFirstLine.at(1);

                if (FILE *file = fopen(filepath.c_str(), "r")) {
                    //fseek(file, 0L, SEEK_END);
                    //size_t filesize = ftell(file);
                    //rewind(file);
                    string content = readFile(file);
                    string ext = filepath.substr(filepath.find_last_of('.'), filepath.length());
                    msg.clear();
                    msg += buildHeader(content.length(), ext);
                    n = -1;
                    n = send(in_fd, msg.c_str(), msg.length(), 0);
                    n = -1;
                    n = send(in_fd, content.c_str(), content.length(), 0);
                    fclose(file);
                } else {
                    DEBUG("file not found");
                }  
            }
            

            
            //DEBUG("Server: n=" << n << " Bytes gesendet");
            //DEBUG("Server: Laenge der Antwort: " << msg.length());
            //DEBUG("Server: Gesendete Antwort: \n>>>" << msg << "<<<");
        }
    }

    // Sockets schliessen
    DEBUG("Server: schliesse Server-Socket");
    close(fd);
}

int detectGet(string path, uint16_t port){
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
    DEBUG("Server: auf " << inet_ntoa(srv.sin_addr) << ":" << port);

    // Anzahl der Verbindungen
    listen(fd, 5);

    int n = -1;
    string req;
    char buf[MAXBUF];
    int in_fd;
    for (;;) { // Server-Schleife
        // Verbindung annehmen und blockieren, bis Verbindung
        DEBUG("\n\nServer: Warte auf Verbindung");
        in_fd = accept(fd, NULL, NULL); // Adresse vom Komm.-Partner interessiert mich nicht

        DEBUG("Server: Verbindung etabliert");
        for (;;) { // Kommunikation mit Client
            DEBUG("Server: lese Daten");
            memset(buf, 0, MAXBUF);
            n = -1;
            n = recv(in_fd, buf, MAXBUF, 0);
            DEBUG("Server: n=" << n << " Bytes empfangen");
            if (n == 0) {
                // Besser mit errno pruefen!
                DEBUG("Server: n==0 => SOCKET CLOSED ON REMOTE END?!");
                close(in_fd);  // nur den Client-Socket schliessen
                break; // raus aus der Komm.-Schleife mit Client, naechste Verbindung akzeptieren
            }
            DEBUG("Server: Empfangene Botschaft: " << buf << "<<<\n\n");

            req = (string) buf;

            vector<string> result;
            stringstream reqstream(req);
            while(reqstream.good()){
                string substr;
                getline(reqstream, substr);
                result.push_back(substr);
            }


            vector<string> parsedFirstLine;
            stringstream linestream(result.at(0));
            while(linestream.good()){
                string substr;
                getline(linestream, substr, ' ');
                parsedFirstLine.push_back(substr);
            }

            string msg = "req error";
            if(parsedFirstLine.at(0) == "GET"){
                DEBUG("get req detected");
                string content;
                content += "<div>\n";
                content += path;
                content += parsedFirstLine.at(1);
                content += "\n</div>\n";
                msg.clear();
                msg += buildHeader(content.length(), "text/html");
                //msg += content;
                n = -1;
                n = send(in_fd, msg.c_str(), msg.length(), 0);
                n = -1;
                n = send(in_fd, content.c_str(), content.length(), 0);
            }
            

            
            //DEBUG("Server: n=" << n << " Bytes gesendet");
            //DEBUG("Server: Laenge der Antwort: " << msg.length());
            //DEBUG("Server: Gesendete Antwort: \n>>>" << msg << "<<<");
        }
    }

    // Sockets schliessen
    DEBUG("Server: schliesse Server-Socket");
    close(fd);
}

int echoServer(uint16_t port)
{
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
    DEBUG("Server: auf " << inet_ntoa(srv.sin_addr) << ":" << port);

    // Anzahl der Verbindungen
    listen(fd, 5);

    int n = -1;
    string msg;
    char buf[MAXBUF];
    int in_fd;
    for (;;) { // Server-Schleife
        // Verbindung annehmen und blockieren, bis Verbindung
        DEBUG("\n\nServer: Warte auf Verbindung");
        in_fd = accept(fd, NULL, NULL); // Adresse vom Komm.-Partner interessiert mich nicht

        DEBUG("Server: Verbindung etabliert");
        for (;;) { // Kommunikation mit Client
            DEBUG("Server: lese Daten");
            memset(buf, 0, MAXBUF);
            n = -1;
            n = recv(in_fd, buf, MAXBUF, 0);
            DEBUG("Server: n=" << n << " Bytes empfangen");
            if (n == 0) {
                // Besser mit errno pruefen!
                DEBUG("Server: n==0 => SOCKET CLOSED ON REMOTE END?!");
                close(in_fd);  // nur den Client-Socket schliessen
                break; // raus aus der Komm.-Schleife mit Client, naechste Verbindung akzeptieren
            }
            DEBUG("Server: Empfangene Botschaft: \n>>>" << buf << "<<<\n\n");

            msg = (string) buf;
            n = -1;
            n = send(in_fd, msg.c_str(), msg.length(), 0);
            DEBUG("Server: n=" << n << " Bytes gesendet");
            DEBUG("Server: Laenge der Antwort: " << msg.length());
            DEBUG("Server: Gesendete Antwort: \n>>>" << msg << "<<<");
        }
    }

    // Sockets schliessen
    DEBUG("Server: schliesse Server-Socket");
    close(fd);
}