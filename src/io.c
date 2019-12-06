// io.c

#include "../includes/io.h"

void clear_screen() {
	#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
		system("clear");
	#elif defined(_WIN32) || defined(_WIN64)
		system("cls");
	#endif
}

void print_spielfeld(spiel_t spiel)
{
		printf("\n");

	int feld_zeile = 0;
	int feld_spalte = 0;

	for(int zeilen = 1; zeilen <= 5; zeilen++)
	{
		if(zeilen % 2 == 0) // jede zweite zeile ist eine trennlinie
		{
			printf("---|---|---");
		}
		else
		{
			for(int spalten = 1; spalten <= 5; spalten++)
			{
				char temp;

				if(spalten % 2 == 0) //jeder zweite brocken ist ein |
				{
					printf("|");
				}
				else
				{
					switch(spiel.spielfeld[feld_zeile][feld_spalte]) //ob x oder o oder nichts
					{
						case leer:
							temp = ' ';
							break;

						case kreuz:
							temp = 'x';
							break;

						case kreis:
							temp = 'o';
							break;
					}

					feld_spalte++;
					printf(" %c ", temp);
				}

				if(spalten == 5)
				{
					feld_zeile++;
					feld_spalte = 0;
				}
			}
		}

		printf("\n");
	}

	printf("\n");

}

void print_ergebnis(spiel_t spiel)
{
	printf("\nSpiel nach %i Zügen beendet!\n", spiel.spielzuege);

	switch(spiel.ergebnis)	{
		case kreuz_gewonnen: printf("Kreuz hat gewonnen!\n"); break;
		case kreis_gewonnen: printf("Kreis hat gewonnen!\n"); break;
		case unentschieden: printf("Unentschiedn!\n"); break;
		case unterwegs: printf("?? Das hätte nicht passieren dürfen!\n"); break;
	}

	Sleep(700);
	printf("\n");

	#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
	system("read -p \"Drücke [Enter] um fortzufahren ...\"");
	#elif defined(_WIN32) || defined(_WIN64)
	system("pause");
	#endif


}

void print_turnier(turnier_t turnier)
{
    //clear_screen();

	printf("\nSpiel %i von %i!\n", ++turnier.current_spiel, ++turnier.gesamt_spiele);

    // TODO
}

int player_get_move(spiel_t spiel)
{
	int move;

	while(true)	{
		printf("Zug: ");
		scanf("%u", &move);

		if(move > 0 && move < 10)	{
			move--; // intern: 0-index, user: 1-index

			if( spiel.spielfeld[move/3][move%3] == leer )	{
				break;
			}	else	{
				printf("Feld %i besetzt.\n", move++);
				continue;
			}
		}	else	{
			printf("Feld %i existiert nicht.\n", move++);
		}
	}

    return move;
}
