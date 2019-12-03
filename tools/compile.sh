#!/bin/sh
OBJ="./src/bot.c ./src/io.c ./src/main.c ./src/spiel.c ./src/turnier.c"
gcc -o tic_tac_toe.o ${OBJ} -I ../includes/*
