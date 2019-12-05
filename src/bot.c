// bot.c

#include "../includes/bot.h"

int bot_random(spiel_t spiel)	{

	int move;

	do {
		move = rand() % 9;
	} while( spiel.spielfeld[move%3][move/3] != leer );

	printf("move %u\n", move);
	scanf("%d");

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