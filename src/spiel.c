//spiel .c

#include "../includes/spiel.h"

spiel_t spiel_starten(spiel_t spiel)
{
    spiel.ergebnis = unterwegs;
    spiel.bot_schwierigkeit = 1;
	spiel.spielzuege = 0;

    for(int i = 0; i < FELD_GROESSE; i++)  {
        for(int j = 0; j < FELD_GROESSE; j++) {
            spiel.spielfeld[i][j] = leer;
        }
    }
    return spiel;
}

spiel_t spiel_update(spiel_t spiel)
{
    int player_move = player_get_move(spiel);
    int bot_move = bot_get_move(spiel);

	spiel.spielzuege++;

    // TODO
    // daten im spielfeld basierend auf zügen der spieler handlen
    // außerdem gewinn / unentschieden checken und setzen

    print_spielfeld(spiel);

    return spiel;
}
