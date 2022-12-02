/*
** EPITECH PROJECT, 2022
** transformations
** File description:
** transformations
*/

#include "../include/my.h"
#include <stdio.h>

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int my_intlen(int nb)
{
    int i = 0;
    if (nb >= 0)
        i++;
    while (nb > 0) {
        nb /= 10;
        i++;
    }
    return i;
}

char *merge_int_str(char *str, char *dest, int nb)
{
    int str_l = my_strlen(str), i = 0, int_l = my_intlen(nb), num = 0, j = 0;
    int diviseur;
    while (i != str_l) {
        dest[i] = str[i];
        i++;
    }
    while (j != int_l) {
        diviseur = 1;
        while (my_intlen(diviseur) < my_intlen(nb))
            diviseur *= 10;
        if (my_intlen(nb) == 2)
            num = 0;
        else
            num = nb / diviseur;
        dest[i] = (num + '0');
        nb -= (nb / diviseur) * diviseur;
        j++; i++;
    }
    dest[i - 1] = '\0';
    return dest;
}
