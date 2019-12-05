// io.c

#include "../includes/io.h"

// equivalent zu: system("cls"); funktioniert auf allen systemen
void clear_screen() { system("@cls||clear"); }

void print_spielfeld(spiel_t spiel)
{
    clear_screen();

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

}

void print_ergebnis(ergebnis_t ergebnis)
{
    clear_screen();

    // TODO
}

void print_turnier(turnier_t turnier)
{
    clear_screen();

    // TODO
}

int player_get_move()
{
    // TODO

    return 0;
}