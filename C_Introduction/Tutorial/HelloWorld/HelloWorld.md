# Einf�hrung in die Arbeitsweise der Werkzeuge

[Zur�ck](../../Markdown/Agenda.md)

---

## Erl�uterungen

C ist eine Programmiersprache, die den vom Entwickler geschriebenen Quelltext des Programms (*Editor*)
zun�chst mittels eines *�bersetzers* (*Compiler*)
in ein ausf�hrbares Programm (*Maschinencode*) umgewandelt.

Erst dann kann das Programm ausgef�hrt werden.

In der *Visual Studio* Entwicklungsumgebung sind alle notwendigen Werkzeuge (Editor, �bersetzer, Debugger)
vorhanden bwz. integriert.

## &bdquo;Hello World&rdquo;

Der Quelltext f�r ein &bdquo;Hello World&rdquo; Programm sieht so aus:

#### Datei [*HelloWorld.c*](HelloWorld.c):

```cpp
#include <stdio.h>

int main()
{
    printf("HelloWorld\n");

    return 0;
}
```

Erstellen Sie mit der *Visual Studio* Entwicklungsumgebung ein C++&ndash;Projekt
und bringen Sie das Programm zum Laufen. Sie sollten dann folgende Ausgabe erhalten:

<img src="HelloWorld.png" width="600">

*Bemerkung*:<br />
Ja, Sie haben richtig gelesen: Ein **C++**&ndash;Projekt.
Die Dateiendungen &ndash; also in unserem Fall &bdquo;*.c*&rdquo;  &ndash; entscheiden dar�ber,
welcher Compiler gestartet wird!

---

## Quellcode des Beispiels:

[*HelloWorld.c*](HelloWorld.c)

---

[Zur�ck](../../Markdown/Agenda.md)

---

