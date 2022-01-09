
Blatt 09: Webserver, Signale [C oder C++14] (P)

IFM 3.3 Systemprogrammierung

BC George, André Matutat, Carsten Gips (FH Bielefeld)

Abgabe ILIAS: Dienstag (11.01.2022) 10:00 Uhr, Vorstellung: Praktikum KW02

    Vorbereitung: Webserver
    Aufgaben

Vorbereitung: Webserver
Antworten auf GET-Requests im HTTP/1.1-Protokoll

Arbeiten Sie die Dokumentation zu einfachen GET-Requests im HTTP 1.1-Protokoll in der Doku durch: w3.org/Protocols/HTTP/AsImplemented.html.
Struktur des Aufgabenblattes

Auf diesem Blatt implementieren Sie schrittweise einen einfachen Webserver in C oder C++, der HTTP-Anfragen1 auf einem beim Start wählbaren Port port entgegennimmt und Dateien unterhalb eines festen Verzeichnisbaums www-path ausliefert.

Realisieren Sie den Webserver ohne Threads, d.h. eine Anfrage wird sofort bearbeitet, bevor eine neue Verbindung entgegengenommen wird. Der Server soll IPv4-Verbindungen bedienen.

Der Server wird wie folgt gestartet: fbtHttpd <www-path> <port>. Dabei soll der Server unter dem Port port erreichbar sein. Das Wurzelverzeichnis für den Server soll der Ordner www-path sein, d.h. der Server darf nur Dateien unterhalb dieses Ordners ausliefern.

Die folgenden Teilaufgaben sollen schrittweise zur Lösung erweitert werden, müssen aber einzeln vorführbar sein. Implementieren Sie also die Teilaufgaben in separaten (Hilfs-) Funktionen/Klassen und geben Sie alle ab.

Sie brauchen auf diesem Blatt KEINE Threads!
Aufgaben
Kommunikation über TCP-Sockets (1P)

Erstellen Sie zunächst die Kommunikation mit TCP-Sockets. Der Server soll IPv4-Verbindungen bedienen und unter der Adresse 127.0.0.1 und dem beim Start angegebenen Port erreichbar sein. Er soll auf eingehende Verbindungen warten. Wenn sich ein Client verbunden hat und eine Botschaft gesendet hat, soll der Server diesem Client antworten und die Verbindung danach beenden. Anschließend wartet der Server auf eine neue Verbindung.

Implementieren Sie den Server zunächst als “Echo-Server”, d.h. alle empfangenen Botschaften werden direkt (unverändert) an den Client zurückgesendet. Sie können Ihren Server sehr einfach mit Telnet testen: Mittels telnet 127.0.0.1 <port> verbinden Sie sich und tippen eine Botschaft ein. Die Antwort des Servers muss Ihrer eingetippten Botschaft exakt entsprechen.

Kommunikation über TCP-IP-Sockets
Erkennen von GET-Requests (HTTP/1.1) (1P)

Eine Anfrage im Browser http://127.0.0.1:<PORT>/index.html kommt im Server etwa so an: GET /index.html HTTP/1.1. Eventuell folgen dieser ersten Zeile noch weitere Zeilen, die hier ignoriert werden sollen.

Der Pfad soll keine Leer- oder Sonderzeichen enthalten, Sie brauchen also kein URL-Encoding implementieren. Weitere Wörter, die eventuell dem Pfad folgen, müssen ignoriert werden. Der Pfad ist relativ und bezieht sich auf den beim Start des Servers angegebenen Verzeichnisbaum www-path.

Alle Zeilen sind mit \r\n2 terminiert. Der Request endet mit einer Leerzeile, d.h. nach zwei direkt aufeinanderfolgenden Zeilenenden muss der Server antworten.

Erweitern Sie den Echo-Server aus der vorigen Aufgabe um die Erkennung von GET-Requests für das HTTP/1.1-Protokoll3. Senden Sie bei einem erkannten GET-Request den absoluten Pfad der Anfrage als Antwort zurück.

Umgang mit dem HTTP-Protokoll: Erkennen von Requests
Antworten auf GET-Requests: Header und Content (1P)

Nach dem HTTP/1.1-Protokoll besteht eine Antwort auf einen GET-Request aus einem Header (im Beispiel Zeilen 1 bis 5) und, getrennt durch eine Leerzeile, den eigentlichen Daten, die Byte-weise gesendet werden (im Beispiel ab Zeile 7):4

    HTTP/1.1 200 OK
    Connection: close
    Content-Language: de
    Content-Length: <Laenge des Content in Byte>
    Content-Type: <Content Type>

    <Content (Byte-weise)>

Die Zeilen im Header sowie die Leerzeile sind wieder mit \r\n terminiert. Nach dem Versand des letzten Bytes wird die Verbindung zum Client geschlossen.

Implementieren Sie Methoden zum Generieren des Headers. Beachten Sie dabei, dass in den Header die Größe des Contents (in Byte) und der Typ des Contents mit eingehen. Erweitern Sie die Antwort auf GET-Requests aus der vorigen Aufgabe, indem Sie den Pfad in etwas HTML-Code verpacken. Der entsprechende Content-Type im Header ist dafür text/html.

Umgang mit dem HTTP-Protokoll: Antwort auf Requests
Ausliefern von Dateien (2P)

Erweitern Sie Ihren Server nun um das Ausliefern von Dateien. Erkennen Sie dabei folgende Dateitypen an den angegebenen Dateiendungen und senden Sie im Header Ihrer Antwort den passenden Content-Type:

    HTML (.html): text/html
    Text-Dateien (.txt, .h, .c, .c++): text/plain
    PDF (.pdf): application/pdf
    PNG (.png): image/png
    JPG (.jpg): image/jpeg
    CSS (.css): text/css
    Sonstige: application/octet-stream

Achten Sie darauf, dass Sie wirklich nur Dateien unterhalb von www-path ausliefern! Liefern Sie den Fehler 404 (Not Found) zurück, wenn eine nicht existierende Datei angefordert wurde.

Umgang mit dem HTTP-Protokoll: Versenden von Dateien
Automatische Anzeige von Verzeichnissen (2P)

Erweitern Sie den Server so, dass nicht nur Dateien ausgeliefert, sondern auch Verzeichnisse angezeigt werden.

    Falls im angefragten Verzeichnis eine index.html-Datei ist, soll diese an den Client ausgeliefert werden.

    Anderenfalls antwortet der Server mit einer dynamisch erstellten HTML-Datei, deren Inhalt der Ausgabe von ls -g in der Konsole entspricht.

    Die Datei- und Verzeichnisnamen sollen dabei als Link dargestellt werden, d.h. ein Klick auf einen Dateinamen liefert den Inhalt der Datei bzw. bei Keinen Verzeichnisnamen den Inhalt (wieder als HTML aufbereitet).

    Sollte das Verzeichnis nicht vorhanden sein, muss wieder mit dem Fehler 404 (Not Found) geantwortet werden.

Sie müssen hier mit stat(2) bzw. fstat(2) und readdir(3) (struct dirent) arbeiten. Sie können sich u.U. viel Arbeit sparen, indem Sie Streams geschickt einsetzen.

Umgang mit Datei- und Verzeichnismanipulation in C/C++
Prozesse und Daemonen (1P)

Lassen Sie den Webserver als UNIX-Daemon laufen.

Der Daemon darf sich nicht mehrfach starten lassen. Er darf bei erfolgreichem Start keine Ausgaben/Eingaben auf/von der Konsole machen.

Ergänzen Sie das run-Target in Ihrem Makefile: Dieses soll zusätzlich den Webserver als Daemon starten.

UNIX-Daemonen
Syslog (1P)

Der Daemon soll seine Aktivitäten im System-Log mit Hilfe von syslog(3) loggen.

Als Name soll für den Hauptprozess der String “Temperatur-Daemon” verwendet werden. Als “Facility” nutzen Sie LOG_USER und als Level LOG_INFO. Lassen Sie hinter dem Namen jeweils automatisch die PID des loggenden Prozesses ausgeben (dies erreichen Sie durch eine passende Option!).

Loggen Sie mindestens folgende Aktionen:

    Start des Daemons
    Empfang und Bearbeitung von Signalen (Signalnummer mit loggen!)
    Empfang und Bearbeitung von HTTP-GET-Requests (s.u.)
    Sämtliche auftretenden Fehler (statt fprintf() bzw. cerr << ...).

Das System-Log können Sie mit tail -f /var/log/syslog ansehen.

Falls die Datei unter /var/log/syslog auf Ihrer Distribution nicht zu finden ist, dann liegt es daran, dass einige Distributionen schon auf journald als neuen Logger umgestiegen sind – Raspbian gehört noch nicht dazu. Um sich den System-Log anzeigen zu lassen, nutzen Sie in diesem Fall journalctl5.

Loggen mit syslog, Selbststudium von man 3 syslog
Signale (1P)

Erweitern Sie Ihren Webserver um zwei Signalhandler:

    Mit dem Signal SIGHUP sollen der Webserver seinen Status (Arbeitsverzeichnis, beantwortete Anfragen, …) in das Syslog schreiben.

    Fügen Sie einen Signalhandler für SIGTERM hinzu, um das Programm zu beenden. Die Aktion soll ebenfalls im Syslog festgehalten werden.

Blockieren Sie während der Behandlung eines Signals die anderen behandelten Signale, d.h. alle anderen Signale, für die Sie Signalhandler registriert haben.

Umgang mit Signalen

HOME

    Betrachten Sie nur einfache GET-Requests und das HTTP 1.1-Protokoll.↩︎

    Achtung, manchmal leider auch nur mit \n!↩︎

    Die Protokollvariante steht als letztes Token in der ersten Zeile des Requests.↩︎

    Hinweis: Es gibt noch viele weitere Header-Zeilen/-Felder. Für dieses Blatt soll die gezeigte Minimalvariante reichen.↩︎

    wiki.archlinux.org/index.php/systemd#Journal↩︎

