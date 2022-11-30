/*
** EPITECH PROJECT, 2022
** game
** File description:
** game window
*/

#include "../include/my.h"

int display_game(sfRenderWindow *win, sfText *sc, sfSprite *csr, int sh)
{
    pmm(win, sh);
    sfRenderWindow_drawSprite(win, csr, NULL);
    sfRenderWindow_drawText(win, sc, NULL);
    sfRenderWindow_display(win);
    if (sh > 0)
        sh--;
    return sh;
}

void game(sfRenderWindow *window, sfEvent event)
{
    int nb_frames = 0, shoot = 0, pos_cursor, dth = 0, sc = 0, pos_csc;
    float pos_game_bg, pos_bridge;
    sfSprite *mobs[9][2], *cursor = set_ss(ss, p_cursor);
    sfSprite *ga_bg = set_sprite_float(game_bg, p_game_bg);
    sfSprite *bridg = set_sprite_float(bridge, p_bridge);
    sfText *score = text(game_font, p_csc, "Score : 0", sfBlack);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    mob_initialization(mobs);
    while (sfRenderWindow_isOpen(window)) {
        shoot = evt_hdl(window, event, cursor, shoot);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, ga_bg, NULL);
        if (nb_frames % nb_fps == 0) spawn_mob(mobs, nb_frames);
        dth = mob_dplc(mobs, nb_frames, window, shoot);
        sc = score_change(window, dth, sc, score);
        d_mobs(mobs, nb_frames, window);
        sfRenderWindow_drawSprite(window, bridg, NULL);
        shoot = display_game(window, score, cursor, shoot);
        nb_frames++;
    }
}
