/*
** EPITECH PROJECT, 2022
** policeman
** File description:
** policeman
*/

#include "../include/my.h"

int can_shoot(int shoot)
{
    int nb = 0;
    if (sfMouse_isButtonPressed(sfMouseLeft))
        if (shoot == 0)
            nb = 1;
    return nb;
}

void pmm(sfRenderWindow *window, int shoot)
{
    int p_re, p_shoot, p_shd;
    sfSprite *pm[3] = {set_ss(ss, p_rep), set_ss(ss, p_shot),
    set_ss(ss, p_shoted)};
    if (shoot <= (nb_fps) && shoot >= ((0.75 * nb_fps) + 1))
        sfRenderWindow_drawSprite(window, pm[1], NULL);
    if (shoot <= (0.75 * nb_fps) && shoot >= (0.5 * nb_fps))
        sfRenderWindow_drawSprite(window, pm[2], NULL);
    if (shoot < (0.5 * nb_fps) && shoot >= 0) {
        sfRenderWindow_drawSprite(window, pm[0], NULL);
    }
}
