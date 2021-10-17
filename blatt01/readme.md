## Limits kennen: Datentypen, Wertebereiche (1P)  
Schreiben Sie ein C-Programm, welches die größtmögliche unsigned int Zahl auf Ihrem System berechnet.

Verwenden Sie hierzu nicht die Kenntnis der systemintern verwendeten Bytes (sizeof, …). Nutzen Sie auch nicht die Konstanten/Makros/Funktionen aus limits.h oder float.h oder anderen Headerdateien!

## Schleifen, Umgang mit Funktionen aus der Standard-Bibliothek (1P)  
Schreiben Sie ein C-Programm, welches für alle Winkelwerte zwischen 0 und 360 Grad in 10-Grad-Schritten den Sinus berechnet und auf drei Stellen nach dem Komma genau ausgibt. Geben Sie jeweils auch den Winkel mit aus, beispielsweise
~~~
Winkel:  0 Grad => Sinus-Funktionswert: 0.000
Winkel: 10 Grad => Sinus-Funktionswert: 0.174
...
Winkel: 90 Grad => Sinus-Funktionswert: 1.000
...
~~~
Schreiben Sie zwei Varianten des Programms: Nutzen Sie einmal eine for- und einmal eine while-Schleife.

Wo finden Sie die Sinus-Funktion? Wie teilen Sie das dem Compiler (und Ihrer IDE) mit?

Welchen Datentyp nutzen Sie sinnvollerweise für die Iteration? Welchen Datentyp erhält die Sinus-Funktion als Eingabe? Nutzt die Sinus-Funktion als Eingabe Grad oder Bogenmaß (Radian)?

## Ein- und Ausgabe, Schleifen (2P)  
Schreiben Sie ein C-Programm, welches für die Eingabe einer positiven ganzen Zahl n folgende Ausgaben produziert. Nutzen Sie dazu __scanf()__ und __printf()__ aus __stdio.h.__ Nutzen Sie unterschiedliche Schleifenkonstrukte!

1. Ausgabe:
    ~~~
    ***...***
    ~~~
    (n Sterne in einer Reihe)  
    <br>
2. Ausgabe:
    ~~~
    *
    **
    ***
    ...
    ***...***
    ~~~
    (linksbündige Pyramide, beginnend mit einem Stern, je Zeile ein Stern mehr, in Zeile dann Reihe mit Sternen)  
    <br>
3. Ausgabe:
    ~~~
        *
       ***
       ...
    ***...***
    ~~~
    (zentrierte Pyramide, beginnend mit einem Stern, in Zeile entsprechend Sterne, letzte Reihe mit Sternen; muss ungerade sein!)  

## Bit-Operationen (1P)
Schreiben Sie eine C-Funktion, welche eine Zahl zwischen 0 und 255 übergeben bekommt und prüft, ob in dieser Zahl ein bestimmtes Bit gesetzt ist. Die Nummer des Bits wird dabei ebenfalls als Funktionsparameter übergeben. Anschließend soll das Bit gesetzt werden (Wert 1) und danach gelöscht (Wert 0) werden. Das Ergebnis der ursprünglichen Prüfung soll als Wahrheitswert zurückgeliefert werden.

Geben Sie nach jeder Operation/Prüfung das Ergebnis aus.

Das zu betrachtende Bit und die Zahl können im Hauptprogramm fest codiert werden. Sie können natürlich auch beide Zahlen im Hauptprogramm als Tastatureingabe einlesen.  
## Casts: Implizite und explizite Typumwandlungen (1P)
Geben Sie alle unnötigen bzw. unsinnigen Typumwandlungen (casts) in folgendem Codefragment an.  
~~~
double x;
x = (float)7/4;                 x = (double)(7/4);
x = (double)(7/(float)4);       x = (double)7/4;
x = (double)(7/4.0);            x = (double)7.0f/4;
~~~

## Zoo (4P)  
Schreiben Sie ein Programm in `ANSI-C` für eine einfache Verwaltung für Zootiere.

1. (0.5P) Erstellen Sie einen Aufzählungstyp `viech`, der die Tierarten `MAMMAL, FISH, BIRD, AMPHIBIAN und REPTILES` umfasst.

2. (0.5P) Definieren Sie einen neuen Datentypen `animal`, der folgende Informationen enthält:
   * `species` (vom Enum-Typ `viech`)
   * `name` (Char-Array fester Länge)
   * `age` (positive ganze Zahl)
   * `food_weight` (reelle Zahl, einfache Genauigkeit)  
<br>
3. (0.5P) Definieren Sie ein globales Feld zoo, welches 10 Tiere umfassen kann und welches Sie mit mindestens 4 verschiedenen Tieren initialisieren.  
<br>
Definieren (und nutzen) Sie für die Länge des Arrays die (Präprozessor-) Konstante `ANIMALCOUNT`.  
<br>
Das Feld zoo ist eine globale Variable. Wird diese automatisch initialisiert? Welche Werte stehen dann da drin? Wie erkennt man fehlende Tiere, also leere Array-Plätze?

4. (1P) Definieren Sie eine parameterlose Funktion `calculate_average_age()`, die zu dem globalen Feld `zoo` aus dem vorigen Aufgabenteil das Durchschnittsalter über alle Tiere berechnet und als Ergebnis zurück liefert.

5. (1P) Definieren Sie eine weitere parameterlose Funktion `more_food()`, die für alle Tiere im globalen Feld zoo die Futterration erhöht: Vögel bekommen 1%, Säugetiere 10%, Fische 4%, Amphibien 2% und Reptilien 0% mehr Futter.  
<br>
Verwenden Sie für diese Funktion keine `if-` oder `switch`-Anweisung! Überlegen Sie, was Sie mit dem im ersten Teil definierten Aufzählungstyp anstellen können :-)

6. (0.5P) Definieren Sie eine Funktion `print_animal()`, mit der Sie ein (per Funktionsparameter übergebenes) Tier vernünftig formatiert (etwa tabellarisch) auf der Konsole ausgeben können. Nutzen Sie dazu die Funktion printf() aus `stdio.h`.  
<br>
Schreiben Sie eine parameterlose Funktion `print_zoo()`, die das globale Feld zoo unter Zuhilfenahme der Funktion `print_animal()` ausgibt.

Die neu definierten Typen sollen sich wie eingebaute Typen verwenden lassen, beispielsweise bei der Deklaration von Variablen: `viech x;` bzw. `animal y;` …

Verwenden Sie in dieser Aufgabe noch keine Pointer bzw. dynamische Speicherverwaltung! Der Stoff der beiden ersten Vorlesungen reicht zum Bearbeiten der Aufgabe.