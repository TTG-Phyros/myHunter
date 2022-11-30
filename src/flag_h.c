/*
** EPITECH PROJECT, 2022
** flag_h
** File description:
** flag_h
*/

#include "../include/my.h"

void flag_h_second(void)
{
    write(1, "                                |\n", 35);
    write(1, "|   This game is a shooter based ", 34);
    write(1, "on a police / thief gameplay.   |\n", 35);
    write(1, "|         Civilians and thieves ", 33);
    write(1, "are present in the game,         |\n", 36);
    write(1, "|      you will receive 10 points ", 35);
    write(1, "for every kill of a thief      |\n", 34);
    write(1, "|         and lose 100 points ", 31);
    write(1, "for every civilian killed.         |\n", 38);
    write(1, "=================================", 34);
    write(1, "=================================\n", 35);
    write(1, "|                         How ", 31);
    write(1, "to play :                          |\n", 38);
    write(1, "|                                ", 34);
    write(1, "                                |\n", 35);
    write(1, "|       To shoot you have to aim ", 34);
    write(1, "at your target and click.       |\n", 35);
    write(1, "====================================", 37);
    write(1, "==============================\n", 32);
}

int flag_h(int argc, char **argv)
{
    if (argc == 2) {
        if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
            write(1, "=================================", 34);
            write(1, "=================================\n", 35);
            write(1, "|                          File ", 33);
            write(1, "Name :                           |\n", 36);
            write(1, "|                               ", 33);
            write(1, "                                 |\n", 36);
            write(1, "|                           My ", 32);
            write(1, "Hunter                            |\n", 37);
            write(1, "=================================", 34);
            write(1, "=================================\n", 35);
            write(1, "|                       File ", 30);
            write(1, "Description :                       |\n", 39);
            write(1, "|                                ", 34);
            flag_h_second();
            return 1;
        }
    }
    return 0;
}
