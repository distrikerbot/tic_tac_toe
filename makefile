IDIR =./include/*

CC=gcc
CFLAGS=-I$(IDIR)

ODIR=./src/
LDIR =../lib
LIBS=

_DEPS =
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = bot.c io.c main.c spiel.c turnier.c
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tic_tac_toe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
