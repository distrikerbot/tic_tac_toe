// spiel.h initialisiert, "spielt" und gibt das Ergebnis eines Spiels aus

#ifndef SPIEL_H
#define SPIEL_H

#include "./definitions.h"
#include "./io.h"
#include "./bot.h"

// initialisiert das Spielfeld und die Spieler
spiel_t spiel_starten(spiel_t);

// lässt eine Runde (Ein Zug pro Spieler) stattfinden
// gibt true zurück, wenn spiel spiel noch läuft, false, wenn spiel beendet ist
spiel_t spiel_update(spiel_t);

#endif
