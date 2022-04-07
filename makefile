.DEFAULT_GOAL := all

IDIR =./include/*

CC=gcc
CFLAGS=\
	-I$(IDIR)\
	-Wall\
	-Wextra\
	-std='c99'\
	-O1

ODIR=./src/
LDIR =../lib
LIBS=

_DEPS =
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = bot.c io.c main.c spiel.c turnier.c
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

EXEC=./bin/tic_tac_toe

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(EXEC)
	rm -rf ./bin/*.dSYM

run:
	./$(EXEC)

debug:
	gdb $(EXEC)

all: $(OBJ)
	$(CC) -o $(EXEC) $^ $(CFLAGS) $(LIBS)

.PHONEY: clean run all debug
