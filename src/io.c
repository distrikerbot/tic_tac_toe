// io.c

#include "../includes/io.h"

// equivalent zu: system("cls"); funktioniert auf allen systemen
void clear_screen() { system("@cls||clear"); }

void print_spielfeld(spiel_t spiel)
{
    clear_screen();

    // TODO improve
    for(int i = 0; i < FELD_GROESSE; i++)   {
        for(int j = 0; j < FELD_GROESSE; j++)   {
            printf("%d ", spiel.spielfeld[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
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