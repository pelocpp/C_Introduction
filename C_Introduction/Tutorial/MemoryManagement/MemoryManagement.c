// ===========================================================================
// MemoryManagement.c // Memory Management
// ===========================================================================

#include <stdio.h>

int programGlobal = 123;               // globale Variable, im gesamten Programm verf�gbar

static int fileGlobal = 456;           // globale Variable, aber nur in dieser Datei verf�gbar

static void memoryManagement_01()
{
    printf("global:            %d\n", programGlobal);
    printf("file static:       %d\n\n", fileGlobal);

    programGlobal++;
    fileGlobal++;
}

void memoryManagement_02()
{
    static int fileGlobal = 111;       // globale Variable, aber nur im Scope dieser Funktion verf�gbar

    fileGlobal++;

    printf("function global:   %d\n\n", fileGlobal);

    return;
}

void memoryManagement_03()
{
    auto int local1 = 0;               // lokale Variable, nur im Scope dieser Funktion verf�gbar
    int local2 = 0;                    // lokale Variable, nur im Scope dieser Funktion verf�gbar

    local1++;
    local2++;

    printf("local:             %d\n", local1);
    printf("local:             %d\n", local2);
}

void mainMemoryManagement()
{
    memoryManagement_01();
    memoryManagement_01();

    memoryManagement_02();
    memoryManagement_02();

    memoryManagement_01();
    memoryManagement_01();

    memoryManagement_02();
    memoryManagement_02();

    memoryManagement_03();
    memoryManagement_03();
    memoryManagement_03();
}

// ===========================================================================
// End-of-File
// ===========================================================================
