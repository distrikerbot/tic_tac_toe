// turnier.c

#include "../includes/turnier.h"
#include "../includes/spiel.h"

turnier_t turnier_starten(turnier_t turnier)  {
    turnier.current_spiel = 0;
    for(int i = 0; i < MAX_SPIELE; i++) {
        turnier.spiele[i] = spiel_starten(turnier.spiele[i]);
    }
    return turnier;
}

turnier_t turnier_update(turnier_t turnier)   {
    turnier.spiele[turnier.current_spiel] = spiel_update(turnier.spiele[turnier.current_spiel]);

    if(turnier.spiele[turnier.current_spiel].ergebnis != unterwegs ) {
        print_ergebnis(turnier.spiele[turnier.current_spiel]);
        turnier.current_spiel++;
    }

    return turnier;
}
