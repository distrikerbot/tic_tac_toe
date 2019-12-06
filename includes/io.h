// io.h handled alle Input/Output Operationen des Spiels

#ifndef IO_H
#define IO_H

#include "./definitions.h"

// wie system("cls") nur auf allen platformen
void clear_screen();

// druckt das momentane spielfeld
void print_spielfeld(spiel_t);

// druckt, dass ergebnis eines spiels
void print_ergebnis(spiel_t);

// druckt die ergebnisse / ablauf eines turniers
void print_turnier(turnier_t);

// fragt den spieler nach seinem zug
int player_get_move(spiel_t);

#endif
