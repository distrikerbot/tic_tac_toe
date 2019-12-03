// io.h handled alle Input/Output Operationen des Spiels

#ifndef IO_H
#define IO_H

#include "./definitions.h"

// druckt das momentane spielfeld
void print_spielfeld(feld_t[FELD_GROESSE][FELD_GROESSE]);

// druckt, dass ergebnis eines spiels
void print_ergebnis(ergebnis_t);

// druckt die ergebnisse / ablauf eines turniers
void print_turnier(turnier_t);

// fragt den spieler nach seinem zug
int player_get_move();

#endif