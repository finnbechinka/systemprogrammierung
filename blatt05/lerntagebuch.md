---
title:  'Lerntagebuch zur Bearbeitung von Blatt 05'
author:
- Finn Bechinka (finn.bechinka@fh-bielefeld.de)
- Michel-Andre Witt (michel-andre.witt@fh-bielefeld.de)
...

# Aufgabe

<!--
Bitte hier die zu lösende Aufgabe kurz in eigenen Worten beschreiben.
-->

## Initialisieren des Ringpuffers (1P)

- Mit malloc einen neuen ringbuffer anlegen:
    - array mit platzt fuer n void pointer anlegen
    - array in elems einhaengen
    - function pointer f in free_callback speichern

## Lesen des ersten Elements (1P)

- das aelteste element (oder null wenn buffer leer) zurückgeben
    - wenn element gelesen, dann head inkrementieren und count dekrementieren
    - gelesene datensatzt nicht freigeben

## Schreiben in den Ringpuffer (1P)

- data in den buffer hängen
    - wenn buffer voll, dann aelteste element ersetzen und das ersetzten element mit free_callback freigeben

## Freigeben des Puffers (1P)

- ringbuffer und enthaltene elemente freigeben
- gibt anzahl der uhrspruenglichen elemente zurueck

# Ansatz und Modellierung

<!--
Bitte hier den Lösungsansatz kurz beschreiben:
-   Wie sollte die Aufgabe gelöst werden?
-   Welche Techniken wollten Sie einsetzen?
-   Wie sah Ihre Modellierung aus (UML-Diagramm)?
-   Worauf müssen Sie konkret achten?
-->

## Initialisieren des Ringpuffers (1P)

- mit malloc den benoetigten speichen fuer den buffer und das void pointer array allozieren
- free_callback zuweisen
- size = n
- head, count = 0

## Lesen des ersten Elements (1P)

- wenn count == 0 dann null zurueckgeben
- wenn count > 0 dann head element zurueckgeben
    - head auf das naechste element zeigen lassen
    - count dekrementieren

## Schreiben in den Ringpuffer (1P)

- wenn buffer nicht voll, dann element an die naechst freie stellen einhaengen
- wenn buffer voll, dann aelteste element freigeben und mit neuem ersetzten
    - head auf das naechste, jetzt aelteste, element setzten

## Freigeben des Puffers (1P)

- count auslesen
- mit free() den inhalt und den buffer selbst freigeben
- count zurueckgeben

# Umsetzung

<!--
Bitte hier die Umsetzung der Lösung kurz beschreiben:
-   Was haben Sie gemacht,
-   an welchem Datum haben sie es gemacht,
-   wie lange hat es gedauert,
-   was war das Ergebnis?
-->

## 21.11.2021

- Mit den Aufgaben vertraut gemacht 
- Aufgaben bis auf Tests fertig

## 22.11.2021

- fehler behoben
- makefile abgeaendert



# Postmortem

<!--
Bitte blicken Sie auf die Aufgabe, Ihren Lösungsansatz und die Umsetzung
kritisch zurück:
-   Was hat funktioniert, was nicht? Würden Sie noch einmal so vorgehen?
-   Welche Probleme sind bei der Umsetzung Ihres Lösungsansatzes aufgetreten?
-   Wie haben Sie die Probleme letztlich gelöst?
-->

Unser einziges Problem ist, dass wir uns nicht ganz sicher sind ob wir die Aufgaben richtrig verstanden haben aber da wir, auf grund von Projekten/Aufgaben in anderen Modulen, wenig zeit hatten haben wir die Testfaelle nicht mehr hinbekommen und koennen darum nicht ausprobieren ob wir die Aufgaben richtig geloest haben.  
Wir finden auch, da auf grund der vielen Vorgaben sehr wenig spielraum gelassen wird wie man die das gestellte Problem loesen kann sind die Aufgaben nicht klar genug.