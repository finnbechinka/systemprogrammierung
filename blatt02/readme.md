# Blatt 02: Segment-Anzeige, Make [ANSI-C] (F)


## Hinweise

Denken Sie daran, ein Lerntagebuch für dieses Blatt zu führen und mit der Lösung hochzuladen!

Die Vorgaben zu diesem Blatt finden Sie im Repo ```git@git03-ifm-min.ad.fh-bielefeld.de:cagix/sp-w21-vorgaben.git.```

## Datentypen (1P)

Definieren Sie in der Datei __ledanzeige/segmentanzeige.h__ folgende Strukturen:

1. Definieren Sie einen vorzeichenlosen Datentyp byte, der Werte von 0 bis 255 halten kann, also 8 Bit “breit” ist.

2. Definieren Sie einen Aufzählungstyp segment für die Segmente der Anzeige mit den Elementen SEG1 (Wert 0), SEG2 (Wert 1), SEG3 (Wert 2), SEG4 (Wert 3).

3. Definieren Sie einen Aufzählungstyp dot für den Dezimalpunkt der Anzeige mit den Elementen OFF (Wert 0) und ON (Wert 1).

4. Definieren Sie einen Aufzählungstyp brightness für die Helligkeit der Anzeige mit den Elementen DARK (Wert 0), MEDIUM (Wert 1) und BRIGHT (Wert 7).

Umgang mit Basisdatentypen und Strukturen


## Funktionen (2P)

Implementieren Sie in der Datei ledanzeige/segmentanzeige.c die Funktion void TM1637_write_byte(byte wr_data), mit der wie nachfolgend beschrieben ein Byte wr_data an die LED-Segmentanzeige übertragen wird.

Die Datenübertragung erfolgt bitweise seriell. Sie müssen zur Übertragung eines Bytes alle 8 Bits einzeln übertragen, beginnend “von rechts”, d.h. mit dem niedrigstwertigen Bit (least significant bit, LSB):

1. Setzen Sie den Clock-Pin auf LOW: Aufruf von digitalWrite(PIN_CLOCK, LOW)

2. Schreiben Sie das Bit auf den Daten-Pin: Aufruf von digitalWrite(PIN_DATA, LOW) (falls Sie den Wert 0 ausgeben wollen; für den Wert 1 ersetzen Sie LOW durch HIGH)

3. Setzen Sie den Clock-Pin auf HIGH: Aufruf von digitalWrite(PIN_CLOCK, HIGH)

Nach jedem Aufruf von digitalWrite() müssen Sie mit Hilfe von delayMicroseconds(DELAY_TIMER) kurz warten, damit sich die Spannung am Pin stabilisieren kann.

Nach dem Senden der 8 Bit wird die Datenübertragung mit dem Aufruf TM1637_ack() abgeschlossen.

Die Pins des genutzten Ports sind in der Vorgabe (ledanzeige/TM1637_intern.h) als Präprozessordirektiven (PIN_CLOCK und PIN_DATA) festgelegt. Sie können diese Literale in Ihrem Code wie Konstanten verwenden.

Die genannten Symbole finden Sie in den Headern ledanzeige/TM1637_intern.h und wiringPi.h.

Umgang mit Funktionen und Header-Dateien


## LED-Demo (1P)

Schreiben Sie ein Programm zur Demonstration der LED-Segmentanzeige-Funktionen: Lassen Sie beispielsweise mit zeitlichem Abstand bestimmte Zahlen anzeigen.

Nutzen Sie dazu void TM1637_display_number(float number) aus ledanzeige/TM1637.h.

Rufen Sie vor der Arbeit mit der LED-Segmentanzeige einmal die Vorgabefunktion TM1637_setup() auf. Damit wird die Kommunikation mit der LED-Segmentanzeige initialisiert.

Fügen Sie die Option -lwiringPi (“minus klein-el”) zu Ihren gcc-Optionen hinzu, damit die Bibliothek beim Linken berücksichtigt wird.

Kompilieren eines Programms, Einbinden von eigenen und Standard-Headern sowie Bibliotheken


## Make (1P)

Schreiben Sie ein Makefile für Ihr Programm entsprechend den Regeln für das Praktikum.