//spiel .c

#include "../includes/spiel.h"

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
