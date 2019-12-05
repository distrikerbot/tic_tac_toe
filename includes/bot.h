// bot.h implementiert den KI Gegner

#ifndef BOT_H
#define BOT_H

#include "./definitions.h"

// gibt einen Zug basierend auf der gewähltem Strategie und dem Spielfeld aus
int bot_get_move(spiel_t);

#endif