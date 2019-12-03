// bot.h implementiert den KI Gegner

#ifndef BOT_H
#define BOT_H

#include "./definitions.h"

// setzt die Schwierigkeit / Strategie des Bots
void set_schwierigkeit(int);

// gibt einen Zug basierend auf der gewähltem Strategie und dem Spielfeld aus
int bot_get_move(feld_t[FELD_GROESSE][FELD_GROESSE]);

#endif