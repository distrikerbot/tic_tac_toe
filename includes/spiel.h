// spiel.h initialisiert, "spielt" und gibt das Ergebnis eines Spiels aus

#ifndef SPIEL_H
#define SPIEL_H

#include "./definitions.h"
#include "./io.h"
#include "./bot.h"

ergebnis_t status;

// initialisiert das Spielfeld und die Spieler
void spiel_starten(feld_t[FELD_GROESSE][FELD_GROESSE]);

// lässt eine Runde (Ein Zug pro Spieler) stattfinden
// gibt true zurück, wenn spiel spiel noch läuft, false, wenn spiel beendet ist
bool spiel_update(feld_t[FELD_GROESSE][FELD_GROESSE]);

// gibt das Ergebnis zurück. NULL wenn Spiel noch läuft
ergebnis_t get_spiel_ergebnis();

#endif