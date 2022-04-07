// bot.c

#include "../includes/bot.h"

bool feld_frei(spiel_t spiel)	{
	int feld_frei = 0;
	for(int i = 0; i < FELD_GROESSE * FELD_GROESSE; i++)	{
		if(spiel.spielfeld[i/3][i%3] == leer)	{
			feld_frei++;
		}
	}

	if(feld_frei != 0)	{
		return true;
	}	else {
		return false;
	}

}

int bot_random(spiel_t spiel)	{

	int move = -1;

	if(feld_frei(spiel))	{

		do {
			move = rand() % 9;
		} while( spiel.spielfeld[move/3][move%3] != leer  );

	}

	return move;
}

int bot_get_move(spiel_t spiel)
{
	switch(spiel.bot_schwierigkeit)	{
		case 1:
		default:
			return bot_random(spiel);
	}
}
