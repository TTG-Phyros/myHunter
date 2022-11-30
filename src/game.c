/*
** EPITECH PROJECT, 2022
** game
** File description:
** game window
*/

#include "../include/my.h"
#include <stdio.h>

int score_change(int death, int score)
{
    if (death == 2) {
        score -= 100;
        printf("You killed a civilian, score : %d\n", score);
    }
    if (death == 1) {
        score += 10;
        printf("You killed a Thief, score : %d\n", score);
    }
    if ((death - 4) == 2 || (death - 4) == 5 || (death - 4) == 8) {
        score -= 100;
        printf("A thief escaped, score : %d\n", score);
    }
    return score;
}

int evt_hdl(sfRenderWindow *window, sfEvent event, sfSprite *cs, int st)
{
    int buffer;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        buffer = can_shoot(st);
        if (buffer == 1)
            st = nb_fps;
        if (event.type == sfEvtMouseMoved) {
            sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window);
            sfVector2f posi_mouse;
            posi_mouse.x = pos_mouse.x - 25;
            posi_mouse.y = pos_mouse.y - 25;
            sfSprite_setPosition(cs, posi_mouse);
        }
    }
    return st;
}

void game(sfRenderWindow *window, sfEvent event)
{
    int nb_frames = 0, shoot = 0, pos_cursor, pos_game_bg, dth = 0, sc = 0;
    sfSprite *mobs[9][2], *cursor = set_ss(ss, p_cursor);
    sfSprite *ga_bg = set_sprite(game_bg, p_game_bg);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    mob_initialization(mobs);
    while (sfRenderWindow_isOpen(window)) {
        shoot = evt_hdl(window, event, cursor, shoot);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, ga_bg, NULL);
        if (nb_frames % nb_fps == 0)
            spawn_mob(mobs, nb_frames);
        dth = mob_deplacement(mobs, nb_frames, window);
        sc = score_change(dth, sc);
        d_mobs(mobs, nb_frames, window);
        pmm(window, shoot);
        sfRenderWindow_drawSprite(window, cursor, NULL);
        sfRenderWindow_display(window);
        nb_frames++;
        if (shoot > 0) shoot--;
    }
}
