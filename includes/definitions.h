// degfinitions.h includes und struct/enum type deifnitions

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// standard includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Sleep für Windows und posix
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    #include <unistd.h>
    #define Sleep(ms) usleep(ms * 1000)
#elif defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#endif

#define FELD_GROESSE 3 // Spielfeld ist 3x3
#define MAX_SPIELE 10 // max Anzahl aller Spiele

// Status eines einzelnen Spielfeldes
typedef enum Feld{
    leer,
    kreuz,
    kreis
} feld_t;

// Ergebnis eines Spiels
typedef enum {
    kreuz_gewonnen,
    kreis_gewonnen,
    unentschieden,
    unterwegs // spiel ist in progress, noch nicht zu ende
} ergebnis_t;

// Ein Spiel mit Feld
typedef struct {
    feld_t spielfeld[FELD_GROESSE][FELD_GROESSE];
    ergebnis_t ergebnis;
    int  bot_schwierigkeit;
	int spielzuege;
} spiel_t;

// speichert alle Spiele
typedef struct {
    spiel_t spiele[MAX_SPIELE];
    int current_spiel;
    int gesamt_spiele;
} turnier_t;

#endif
