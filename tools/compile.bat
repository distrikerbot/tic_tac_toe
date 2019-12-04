@echo off
set OBJ=./src/bot.c ./src/io.c ./src/main.c ./src/spiel.c ./src/turnier.c
gcc -o tic_tac_toe %OBJ% -I ../includes/*
