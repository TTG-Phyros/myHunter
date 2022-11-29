/*
** EPITECH PROJECT, 2022
** game
** File description:
** game window
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
            sfVector2i pos_mouse = sfMouse_getPosition(window);
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
    int nb_frames = 0, shoot = 0, pos_cursor, pos_game_bg;
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
        mob_deplacement(mobs, nb_frames);
        d_mobs(mobs, nb_frames, window);
        pmm(window, shoot);
        sfRenderWindow_drawSprite(window, cursor, NULL);
        sfRenderWindow_display(window);
        nb_frames++;
        if (shoot > 0)
            shoot--;
    }
}
