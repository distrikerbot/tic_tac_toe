// turnier.h startet ein turnier und kümmert sich um den Ablauf

#ifndef TURNIER_H
#define TURNIER_H

#include "./definitions.h"

// initialisiert ein turnier und dessen spiele
turnier_t turnier_starten(turnier_t);

// lässt ein spiel vollständig ablaufen
turnier_t turnier_update(turnier_t);

#endif
