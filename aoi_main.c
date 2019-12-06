// DEFINITIONS

// standard includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Sleep für Windows und posix
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    #include <unistd.h>
    #define Sleep(ms) usleep(ms * 1000)
#elif defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#endif

#define FELD_GROESSE 3 // Spielfeld ist 3x3
#define MAX_SPIELE 10 // max Anzahl aller Spiele

// Status eines einzelnen Spielfeldes
typedef enum Feld{
    leer,
    kreuz,
    kreis
} feld_t;

// Ergebnis eines Spiels
typedef enum {
    kreuz_gewonnen,
    kreis_gewonnen,
    unentschieden,
    unterwegs // spiel ist in progress, noch nicht zu ende
} ergebnis_t;

// Ein Spiel mit Feld
typedef struct {
    feld_t spielfeld[FELD_GROESSE][FELD_GROESSE];
    ergebnis_t ergebnis;
    int  bot_schwierigkeit;
	int spielzuege;
} spiel_t;

// speichert alle Spiele
typedef struct {
    spiel_t spiele[MAX_SPIELE];
    int current_spiel;
    int gesamt_spiele;
} turnier_t;

// SIG

int bot_get_move(spiel_t);

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

// initialisiert das Spielfeld und die Spieler
spiel_t spiel_starten(spiel_t);

// lässt eine Runde (Ein Zug pro Spieler) stattfinden
// gibt true zurück, wenn spiel spiel noch läuft, false, wenn spiel beendet ist
spiel_t spiel_update(spiel_t);

// initialisiert ein turnier und dessen spiele
turnier_t turnier_starten(turnier_t);

// lässt ein spiel vollständig ablaufen
turnier_t turnier_update(turnier_t);

// BOT


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


// IO


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

// SPIEL


ergebnis_t check_win(spiel_t spiel)
{
    int feld_frei = 0;

    for (int i = 0; i < FELD_GROESSE; i++)
    {
        if (spiel.spielfeld[i][0] == spiel.spielfeld[i][1] && spiel.spielfeld[i][0] == spiel.spielfeld[i][2] && spiel.spielfeld[i][0] != leer)
        {
            return spiel.spielfeld[i][0] == kreuz ? kreuz_gewonnen : kreis_gewonnen;
        }
        else if (spiel.spielfeld[0][i] == spiel.spielfeld[1][i] && spiel.spielfeld[0][i] == spiel.spielfeld[2][i] && spiel.spielfeld[0][i] != leer)
        {
            return spiel.spielfeld[0][i] == kreuz ? kreuz_gewonnen : kreis_gewonnen;
        }
    }
     if (spiel.spielfeld[0][0] == spiel.spielfeld[1][1] && spiel.spielfeld[0][0] == spiel.spielfeld[2][2] && spiel.spielfeld[0][0] != leer)
    {
        return spiel.spielfeld[0][0] == kreuz ? kreuz_gewonnen : kreis_gewonnen;
    }
    else if (spiel.spielfeld[0][2] == spiel.spielfeld[1][1] && spiel.spielfeld[0][2] == spiel.spielfeld[2][0] && spiel.spielfeld[0][2] != leer)
    {
        return spiel.spielfeld[0][2] == kreuz ? kreuz_gewonnen : kreis_gewonnen;
    }

    for (int i = 0; i < FELD_GROESSE * FELD_GROESSE; i++)
    {
        if (spiel.spielfeld[i / 3][i % 3] == leer)
        {
            feld_frei++;
        }
    }

    if (feld_frei == 0)
    {
        return unentschieden;
    }

    return unterwegs;
}

spiel_t spiel_starten(spiel_t spiel)
{
    spiel.ergebnis = unterwegs;
    spiel.bot_schwierigkeit = 1;
    spiel.spielzuege = 0;

    for (int i = 0; i < FELD_GROESSE; i++)
    {
        for (int j = 0; j < FELD_GROESSE; j++)
        {
            spiel.spielfeld[i][j] = leer;
        }
    }
    return spiel;
}

spiel_t spiel_update(spiel_t spiel)
{
    spiel.spielzuege++;

    print_spielfeld(spiel);
    int player_move = player_get_move(spiel);
    spiel.spielfeld[player_move / 3][player_move % 3] = kreuz;

    clear_screen();
    print_spielfeld(spiel);

    spiel.ergebnis = check_win(spiel);
    if(spiel.ergebnis != unterwegs) return spiel;

    Sleep(500);

    int bot_move = bot_get_move(spiel);
    if(bot_move != -1)  {
        spiel.spielfeld[bot_move / 3][bot_move % 3] = kreis;
        clear_screen();
        print_spielfeld(spiel);
    }

    spiel.ergebnis = check_win(spiel);
    if(spiel.ergebnis != unterwegs) return spiel;

    clear_screen();

    return spiel;
}

// TURNIER


turnier_t turnier_starten(turnier_t turnier)  {
    turnier.current_spiel = 0;
    for(int i = 0; i < MAX_SPIELE; i++) {
        turnier.spiele[i] = spiel_starten(turnier.spiele[i]);
    }
    return turnier;
}

turnier_t turnier_update(turnier_t turnier)   {

    while(1)    {
        turnier.spiele[turnier.current_spiel] = spiel_update(turnier.spiele[turnier.current_spiel]);

        if(turnier.spiele[turnier.current_spiel].ergebnis != unterwegs ) {
            print_ergebnis(turnier.spiele[turnier.current_spiel]);
            turnier.current_spiel++;
            break;
        }
    }

    return turnier;
}

// MAIN


int main()  {

    srand(time(NULL));

    // TODO: get input für konfiguration
    // Anzahl Spiele (=turnier.gesamt_spiele) / Bot Schwierigkeit / ...

    turnier_t turnier = {};

    turnier.gesamt_spiele = 1; // 0-indexed
    turnier = turnier_starten(turnier);

    while(true)    {
        clear_screen();
        print_turnier(turnier);

        turnier = turnier_update(turnier);

        if(turnier.current_spiel > turnier.gesamt_spiele)   {
            // Alle Spiele fertig
            printf("\nAlle Spiele Fertig\n\n");
            break;
        }
    }

    return EXIT_SUCCESS;
}
