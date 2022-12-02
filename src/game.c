/*
** EPITECH PROJECT, 2022
** game
** File description:
** game window
*/

#include "../include/my.h"

void game_over(sfRenderWindow *window, int score)
{
    if (score < 0) {
        int i = 200, game_ove, peak_scor;
        char *dest = malloc((my_intlen(score) + 14) * sizeof(char));
        merge_int_str("Peak Score : ", dest, score);
        sfRenderWindow_clear(window, sfBlack);
        sfText *game_is_over = text(game_font, game_ov, "Game Over", sfRed);
        if (score == 0)
            dest = "Peak Score : 0";
        sfText *scor = text(game_font, p_sco, dest, sfRed);
        sfRenderWindow_drawText(window, game_is_over, NULL);
        sfRenderWindow_drawText(window, scor, NULL);
        while (i != 0) {
            sfRenderWindow_display(window);
            i--;
        }
    }
}

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

int evt_hdl(sfRenderWindow *win, sfEvent evt, int st, sfSprite *cs)
{
    int buffer;
    while (sfRenderWindow_pollEvent(win, &evt)) {
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(win);
        buffer = can_shoot(st);
        if (buffer == 1)
            st = nb_fps;
        if (evt.type == sfEvtMouseMoved) {
            sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(win);
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
    int nb_fr = 0, shoot = 0, pos_cursor, dth = 0, sc = 0, pos_csc, psc = 0;
    float pos_game_bg, pos_bridge;
    sfSprite *mobs[9][2], *cursor = set_ss(ss, p_cursor);
    sfSprite *env[2] = {ssf(game_bg, p_game_bg), ssf(bridge, p_bridge)};
    sfText *score = text(game_font, p_csc, "Score : 0", sfBlack);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    mob_initialization(mobs);
    while (sfRenderWindow_isOpen(window) && sc >= 0) {
        shoot = evt_hdl(window, event, shoot, cursor);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, env[0], NULL);
        if (nb_fr % nb_fps == 0) spawn_mob(mobs, nb_fr, sc);
        dth = mob_dplc(mobs, nb_fr, window, shoot);
        sc = score_change(dth, sc, score);
        if (sc > psc) psc = sc;
        d_mobs(mobs, nb_fr, window);
        sfRenderWindow_drawSprite(window, env[1], NULL);
        shoot = display_game(window, score, cursor, shoot); nb_fr++; dth = 0;
    }
    game_over(window, psc);
}
