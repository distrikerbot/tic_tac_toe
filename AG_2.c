#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void speichern_des_aktuellen_spielfeldes(int[3][3]);
void laden_eines_spielfeldes(int[10][3][3], int);
void eingabe_spieler(int, int, int);
void loeschen_des_spielfeldes();
void spielfeld_ausgeben(int[3][3]);
int spiele_speicher[10][3][3]; //vorrat für 10 spiele
int current_spiel[3][3]; //akutelles spiel
int spiele_speicher_anzahl = 0; //wie viele spiele gespeichert wurden

int main()
{

	return EXIT_SUCCESS;
}

void speichern_des_aktuellen_spielfeldes(int feld[3][3]) //abspeichern eines spielfeldes im array
{
	for(int zeile = 0; zeile < 3; zeile++)
	{
		for(int spalte = 0; spalte < 3; spalte++)
		{
			spiele_speicher[spiele_speicher_anzahl][zeile][spalte] = feld[zeile][spalte];
		}
	}

	spiele_speicher_anzahl++;
}

void laden_eines_spielfeldes(int spiele_speicher [10][3][3], int zu_ladende_spiel_nummer) //laden einer spielnummer
{
	for(int zeile = 0; zeile < 3; zeile++)
	{
		for(int spalte = 0; spalte < 3; spalte++)
		{
			current_spiel[zeile][spalte] = spiele_speicher[zu_ladende_spiel_nummer][zeile][spalte]; //hier current_spiel mit aktuellem spielspeicher austauschen
		}
	}
}

void eingabe_spieler(int echte_zeile, int echte_spalte, int eingabe)  		//   1   2   3  <--- spalten
{
																			//1  x / x / x
	current_spiel[echte_zeile - 1][echte_spalte - 1] = eingabe;				//2	 x / x / x   	 Spielfeldnummern
}																			//3  x / x / x		 current_spiel wieder mit aktuellem spielnamen auswechseln
																			//^
																			//| zeilen

void loeschen_des_spielfeldes()
{
	for(int zeile = 0; zeile < 3; zeile++)
	{
		for(int spalte = 0; spalte < 3; spalte++)
		{
			current_spiel[zeile][spalte] = 0; //hier current_spiel mit aktuellem spielspeicher austauschen
		}
	}
}

void spielfeld_ausgeben(int spielfeld[3][3])
{
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
					switch(spielfeld[feld_zeile][feld_spalte]) //ob x oder o oder nichts
					{
						case 0: //leer
							temp = ' ';
							break;

						case 1: //kreuz
							temp = 'x';
							break;

						case 2: //kreis
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






