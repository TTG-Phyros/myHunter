/*
** EPITECH PROJECT, 2022
** mobs
** File description:
** mobs
*/

#include "../include/my.h"

int mob_initialization(sfSprite *mobs[9][2])
{
    int p_fe, p_ma, p_th;
    mobs[0][0] = set_ss(ss, p_cf[0]), mobs[0][1] = set_ss(ss, p_cf[1]);
    mobs[1][0] = set_ss(ss, p_cm[0]), mobs[1][1] = set_ss(ss, p_cm[1]);
    mobs[2][0] = set_ss(ss, p_ti[0]), mobs[2][1] = set_ss(ss, p_ti[1]);
    p_cf[0][0][0] += 430, p_cm[0][0][0] += 435, p_ti[0][0][0] += 425;
    p_cf[1][0][0] += 430, p_cm[1][0][0] += 435, p_ti[1][0][0] += 425;
    mobs[3][0] = set_ss(ss, p_cf[0]), mobs[3][1] = set_ss(ss, p_cf[1]);
    mobs[4][0] = set_ss(ss, p_cm[0]), mobs[4][1] = set_ss(ss, p_cm[1]);
    mobs[5][0] = set_ss(ss, p_ti[0]), mobs[5][1] = set_ss(ss, p_ti[1]);
    p_cf[0][0][0] += 425, p_cm[0][0][0] += 430, p_ti[0][0][0] += 425;
    p_cf[1][0][0] += 425, p_cm[1][0][0] += 430, p_ti[1][0][0] += 425;
    mobs[6][0] = set_ss(ss, p_cf[0]), mobs[6][1] = set_ss(ss, p_cf[1]);
    mobs[7][0] = set_ss(ss, p_cm[0]), mobs[7][1] = set_ss(ss, p_cm[1]);
    mobs[8][0] = set_ss(ss, p_ti[0]), mobs[8][1] = set_ss(ss, p_ti[1]);
    return 0;
}

int mob_dplc(sfSprite *mob[9][2], int n_fr, sfRenderWindow *win, int sh)
{
    int i = 0, anim = 0, death = 0, buffer = 0;
    if ((n_fr / 30) % 2 == 0) anim = 1;
    for (; i != 9; i++) {
        sfVector2f pos = sfSprite_getPosition(mob[i][anim]);
        if (pos.y < -200) {
            pos.y = 1000;
            buffer = 4 + i;
        }
        if (pos.y <= 850 && pos.y >= -200) pos.y -= 5;
        sfSprite_setPosition(mob[i][anim], pos);
        sfSprite_setPosition(mob[i][!anim], pos);
        death = mob_death(win, mob[i][0], i, sh);
        if (death != 0) buffer = death;
        if (death > 0) {
            pos.y = 1000;
            sfSprite_setPosition(mob[i][anim], pos);
            sfSprite_setPosition(mob[i][!anim], pos);
        }
    }
    return buffer;
}

int spawn_mob(sfSprite *mobs[9][2], int nb_frames)
{
    int pos = (rand() % 3), skin = (rand() % 3), nb_mob, anim = 0;
    if ((nb_frames / 30) % 2 == 0)
        anim = 1;
    if (pos == 1)
        pos = 3;
    if (pos == 2)
        pos = 6;
    nb_mob = pos + skin;
    sfVector2f posi = sfSprite_getPosition(mobs[nb_mob][anim]);
    while (posi.y < 1000) {
        nb_mob++;
        if (nb_mob >= 9)
            nb_mob = 0;
        posi = sfSprite_getPosition(mobs[nb_mob][anim]);
    }
    posi.y = 850;
    sfSprite_setPosition(mobs[nb_mob][anim], posi);
    sfSprite_setPosition(mobs[nb_mob][!anim], posi);
    return 0;
}

void d_mobs(sfSprite *mobs[9][2], int nb_frames, sfRenderWindow *window)
{
    int i = 0, anim = 0;
    while (i != 9) {
        if ((nb_frames / 30) % 2 == 0)
            anim = 1;
        sfRenderWindow_drawSprite(window, mobs[i][anim], NULL);
        i++;
    }
}
