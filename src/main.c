#include "../includes/definitions.h"
#include "../includes/spiel.h"
#include "../includes/io.h"
#include "../includes/bot.h"
#include "../includes/turnier.h"

int main()  {

    srand(time(NULL));

    // TODO: get input für konfiguration
    // Anzahl Spiele (=turnier.gesamt_spiele) / Bot Schwierigkeit / ...

    turnier_t turnier = {};

    turnier.gesamt_spiele = 5;
    turnier = turnier_starten(turnier);

    while(true)    {
        print_turnier(turnier);

        turnier = turnier_update(turnier);

        Sleep(500); // temporary
        if(turnier.current_spiel > turnier.gesamt_spiele)   {
            // Alle Spiele fertig
            break;
        }
    }

    return EXIT_SUCCESS;
}
