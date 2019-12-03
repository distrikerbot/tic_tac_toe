#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// standard includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Sleep für Windows und Mac
#ifdef __APPLE__
    #include <unistd.h>
    #define Sleep(ms) usleep(ms * 1000)
#elif _WIN32
    #include <windows.h>
#endif

#define FELD_GROESSE 3
// feld ist 3 * 3

// Spielfeld Status
typedef enum {
    leer,
    kreuz,
    kreis
} feld_t;

// Ergebnis eines Spiels
typedef enum {
    gewonnen,
    verloren,
    unentschieden
} ergebnis_t;

// Struktur um das Turnier zu speichern
typedef struct {
    //TODO
    int temporary_damit_compiler_happy_ist;
} turnier_t;

#endif