# Blatt 05: Ringbuffer: Struct, Funktionspointer [C11] (F)

## Hinweise

Denken Sie daran, ein Lerntagebuch für dieses Blatt zu führen und mit der Lösung hochzuladen!

Halten Sie bitte die angegebenen Signaturen und Dateinamen ein. In der Bewertung werden wir u.a. eine eigene Testsuite nutzen, die auf den Signaturen und Ordnerstrukturen aufsetzt und die Funktionalitäten testet.

Die Header sollen in include/ringbuffer/ringbuffer.h formuliert werden, die Implementierung (ohne main()) in src/ringbuffer/ringbuffer.c. Außerdem muss das übliche Makefile abgegeben werden sowie eine Datei mit den Tests (Name/Ordner beliebig).

## Vorbereitung: Überblick Ringpuffer

Ein Ringpuffer ist eine spezielle Form der abstrakten Datenstruktur “Warteschlange” (Queue), die nur eine beschränkte Anzahl n von Elementen (Datensätzen) aufnehmen kann. Die Daten werden nach dem FIFO-Prinzip über die Funktion write() am Ende der Schlange eingefügt und mit der Funktion read() vom Anfang der Schlange entnommen. Ist der Puffer voll, wird bei write() das älteste Element entfernt und das neue Element auf dem frei gewordenen Platz eingefügt.

Der Puffer kann effizient durch ein dynamisches Array realisiert werden (dieses Array soll zur Laufzeit mit der Funktion init_buffer() auf dem Heap angelegt werden):

    Die Integer-Variable head zeigt auf den Anfang der Schlange (ältestes Element).
    Eine Variable count zählt, wie viele Elemente aktuell im Puffer gespeichert sind.
    Die Variable size speichert die Gesamtgröße des Puffers (Convenience-Funktionalität)
    Die Ringstruktur wird durch entsprechende Modulo-Operationen auf den Array-Indizes realisiert.

Definieren Sie einen Datentyp ring_buffer für den Ringpuffer mit folgender Struktur:

```c
struct ring_buffer {
    size_t size, count, head;
    void **elems;
    void (*free_callback)(void *p);
};
```

Der Pointer elems realisiert dabei das dynamische Array. Mit Hilfe des Funktionspointers free_callback kann man dem Ringpuffer eine Funktion angeben, mit der freizugebende Elemente aus dem Speicher entfernt werden (beispielsweise free(), falls die Elemente mit malloc() alloziert wurden)

## Aufgaben

### Initialisieren des Ringpuffers (1P)

Die Funktion ring_buffer *init_buffer(const size_t n, void (*f)(void *p)) soll mit Hilfe von malloc() einen neuen Ringpuffer anlegen sowie ein Array mit Platz für

void-Pointer allozieren und das Array in elems einhängen. Der Pointer auf die Callback-Funktion f wird in der Struktur im Pointer free_callback gespeichert.

Die Funktion free_callback() wird aufgerufen, um ein Element des Puffers freizugeben.

### Lesen des ersten Elements (1P)

Die Funktion void *read_buffer(ring_buffer *cb) soll das erste (älteste) Element aus dem Ringpuffer cb zurückliefern oder NULL, wenn der Puffer leer ist.

Falls ein Element gelesen wurde, steht der interne Startzeiger head anschließend auf dem nächsten Element, der count wird dekrementiert. Der gelesene Datensatz wird nicht freigegeben.

### Schreiben in den Ringpuffer (1P)

Die Funktion void write_buffer(ring_buffer *cb, void *data) soll den Datensatz data in den Puffer hängen.

Wenn der Puffer voll ist, soll der älteste Eintrag durch den neuen Datensatz ersetzt werden. Der ersetzte Datensatz soll mittels des Funktionspointers free_callback freigegeben werden.

### Freigeben des Puffers (1P)

Die Funktion int free_buffer(ring_buffer *cb) soll den Ringpuffer freigeben. Die Datensätze sollen dabei ebenfalls freigegeben werden (mittels des Funktionspointers free_callback).

Der Rückgabewert entspricht der Anzahl der ursprünglich gespeicherten Datensätze.

### Testfälle (1P)

Schreiben Sie eine Testsuite, in der Sie die implementierten Funktionalitäten ansprechen und sinnvoll testen: Ringpuffer anlegen, Daten eintragen und lesen, Ringpuffer löschen; sinnvolle free_callback()-Funktion definieren und mitgeben …

Schauen Sie sich dazu GoogleTest an. Das Framework ist bereits auf dem Raspi installiert.

Denken Sie daran, dass Ihr Makefile das Ausführen der Tests erlauben soll, bauen Sie also passende Targets ein.

Wann immer Sie das Gefühl haben, eine Debug-Ausgabe zu brauchen: Schreiben Sie stattdessen einfach einen Testfall.

Sie können die Tests auch in einem anderen Framework formulieren, dann muss Ihr Makefile ein Target aufweisen, welches das von Ihnen verwendete Framework lokal für den ausführenden User installiert.