
Blatt 08: Smartpointer [C++14] (F)

IFM 3.3 Systemprogrammierung

BC George, André Matutat, Carsten Gips (FH Bielefeld)

Abgabe ILIAS: Dienstag (04.01.2022) 10:00 Uhr (Lerntagebuch; keine Präsentation)

    Hinweise
    Smartpointer in C++

Hinweise

Denken Sie daran, ein Lerntagebuch für dieses Blatt zu führen und mit der Lösung hochzuladen!

Die Vorgaben zu diesem Blatt finden Sie im Repo git@git03-ifm-min.ad.fh-bielefeld.de:cagix/sp-w21-vorgaben.git.

Ziel dieser Fingerübung ist wieder, ein kleineres Stück Software so zu schreiben und zu dokumentieren, dass andere Personen sich damit in vertretbarer Zeit vertraut machen können und die Software in Betrieb nehmen können. Dies bedeutet, dass Ihr Lerntagebuch inhaltlich so umfangreich sein muss, dass man Ihr Vorgehen problemlos nachvollziehen und den Aufbau Ihrer Software (Design) verstehen kann. Ohne (ausreichendes) Lerntagebuch gibt es deshalb keine Punkte. Zusätzlich soll der Code so dokumentiert sein, dass man beim Lesen versteht, was eine Funktion oder Klasse o.ä. tun soll. Der Code soll auf dem Raspi ohne Warnungen kompilieren, es darf auch keine Abhängigkeiten von einem bestimmten Usernamen oder absoluten Pfaden geben. Das Makefile soll die Übersetzung ermöglichen und auch den Start der Software (vgl. “Makefile mit Standardtargets”). Die Testsuite aus den Vorgaben soll problemfrei durchlaufen.
Smartpointer in C++

In C++ können u.a. auch Operatoren überladen werden, die zum Umgang mit Pointern dienen. Dadurch lassen sich “Smartpointer” realisieren, die im Umgang den aus Java bekannten Referenzen ähneln und die die typischen Pointer-Probleme1 in C/C++ vermeiden können.

Ein Smartpointer soll entsprechend folgende Eigenschaften haben:

    Verwendung soll analog zu normalen Pointern sein (Operatoren * und -> überladen)
    Smartpointer sollen für beliebige Klassen nutzbar sein (Template-Klasse)
    Smartpointer haben niemals einen undefinierten Wert: entweder sie zeigen auf ein Objekt oder auf nullptr2
    Dereferenzierung von nicht existierenden Objekten (d.h. der Smartpointer zeigt intern auf nullptr) führt nicht zum Programmabsturz, sondern zu einer Exception
    Kopieren von Smartpointern führt dazu, dass sich mehrere Smartpointer das verwiesene Objekt teilen
    Smartpointer löschen sich selbst (und das verwiesene Objekt, falls kein anderer Smartpointer mehr darauf zeigt), wenn die Smartpointer ungültig werden (bei Verlassen des Scopes bzw. bei explizitem Aufruf von delete)
    Es gibt keine verwitweten Objekte mehr: Wenn mehrere Smartpointer auf das selbe Objekt zeigen, darf erst der letzte Smartpointer das Objekt aus dem Heap löschen
    Smartpointer funktionieren nur für mit new erzeugte Objekte

Es gibt in der C++-Standardbibliothek bereits verschiedene Smartpointer-Klassen. Um diese sicher benutzen zu können, benötigen Sie ein Grundverständnis der in C++11 hinzugekommenen Move-Semantik. => Themen in “Move-Semantik und Rvalue-Referenzen” und “Smartpointer”. Auf diesem Übungsblatt sollen Sie durch die eigenständige Implementierung der Smartpointer sowohl ein Grundverständnis für die prinzipielle Arbeitsweise erwerben als auch Ihre C++-Template-Kenntnisse vertiefen.
Hilfsklassen (1P)
Hilfsklasse für den Referenzen-Zähler

Für die Smartpointer brauchen Sie einen Zähler, der mitzählt, wie oft auf das Objekt gezeigt wird. Nutzen Sie dafür die Klasse RefCounter. Sie finden die Schnittstelle als Vorgabe im Header smartpointer/RefCounter.h. Implementieren Sie die Klasse in smartpointer/RefCounter.cpp.

Referenzen, Klassen und Konstruktoren in C++
Hilfsklasse für Exceptions

Bei der Dereferenzierung eines “leeren” Smartpointers, dessen interner Objektzeiger pObj ein nullptr ist, soll eine Exception ausgelöst werden. Implementieren Sie dafür die Klasse NullPointerException als “echte” Exception (std::runtime_error).

Implementieren Sie diese Klasse direkt im Header smartpointer/NullPointerException.h.

Vererbung, Exceptions in C++
Smartpointer in C++ (2P)

Implementieren Sie nun die Smartpointer mit dem Klassen-Template smartpointer/SmartPointer. Da es sich um ein Klassen-Template handelt, müssen Sie Ihre Implementierung direkt im Header vornehmen.

Betrachten Sie die vorgegebene Testsuite wieder als Ergänzung der Aufgabenstellung (“ausführbare Spezifikation”).

Sie sollen sich in dieser Aufgabe u.a. mit der Arbeitsweise von Smartpointern beschäftigen. Nutzen Sie für Ihre Lösung keine existierenden Smartpointer-Implementierungen!

Umgang mit Klassen-Templates und Überladen von Operatoren; Arbeitsweise von Smartpointern
Standard-Idiome in C++ (2P)

Gerade im Zusammenhang mit Smartpointern werden in C++ häufig die Idiome “RAII” (Resource Acquisition Is Initialisation) und “PIMPL” (Pointer to Implementation) verwendet.

Recherchieren Sie, was diese Idiome bedeuten und wie sie umgesetzt und genutzt werden. Erläutern Sie im Lerntagebuch anhand selbst implementierter Beispiele die Funktionsweise. Wo werden diese Idiome angewendet und warum?

Einarbeitung in zwei Standard-Idiome in C++: RAII und PIMPL

HOME

    Dereferenzierung von Null-Pointern oder nicht initialisierten Pointern, Nutzung von delete für Pointer, die nicht mit new erstellt wurden, mehrfaches delete, Speicherlöcher durch Vergessen von delete, Dangling Pointer, verwitwete Objekte, …↩︎

    Sie müssen dafür den g++ auf C++11 oder höher umstellen (--std=c++11) und den Header <cstddef> includen.↩︎

