/*
** EPITECH PROJECT, 2022
** main
** File description:
** main screen
*/

#include "../include/my.h"
#include <stdio.h>

void redirect(sfRenderWindow *window, sfEvent event, int choice)
{
    if (choice == 1) {
        if (event.type == sfEvtMouseButtonPressed)
            game(window, event);
    }
    if (choice == 2) {
        if (event.type == sfEvtMouseButtonPressed)
            settings(window, event);
    }
    if (choice == 3) {
        if (event.type == sfEvtMouseButtonPressed)
            scoreboard(window, event);
    }
}

void if_click(sfRenderWindow *window, sfEvent event)
{
    int pos_sbu, pos_se, pos_sc;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x >= pos_but[0] && mouse.x <= pos_but[0] + 510) {
        if (mouse.y >= pos_but[1] && mouse.y <= pos_but[1] + 125) {
            redirect(window, event, 1);
        }
    }
    if (mouse.x >= p_se[0][0] && mouse.x <= p_se[0][0] + 150) {
        if (mouse.y >= p_se[0][1] && mouse.y <= p_se[0][1] + 150) {
            redirect(window, event, 2);
        }
    }
    if (mouse.x >= p_sc[0][0] && mouse.x <= p_sc[0][0] + 150) {
        if (mouse.y >= p_sc[0][1] && mouse.y <= p_sc[0][1] + 150) {
            redirect(window, event, 3);
        }
    }
}

int close_event(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
        return 1;
    }
    return 0;
}

void draw(sfRenderWindow *win, sfSprite *bg, sfSprite *bu[2], sfText **txt)
{
    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, bg, NULL);
    sfRenderWindow_drawSprite(win, bu[0], NULL);
    sfRenderWindow_drawSprite(win, bu[1], NULL);
    sfRenderWindow_drawText(win, txt[0], NULL);
    sfRenderWindow_drawText(win, txt[1], NULL);
    sfRenderWindow_display(win);
}

int main(int argc, char **argv)
{
    int di_w, pos_ti, pos_bg, pos_se, pos_sc, pos_sbu;
    char mus; float v_mus; videomode;
    if (flag_h(argc, argv) == 1) return 0;
    sfText *txt[2] = {text(game_font, pos_tit, game_name, sfBlack),
    text(game_font, pos_but, bu_text, sfBlack)};
    sfRenderWindow *win = sfRenderWindow_create(md, game_name, sfClose, NULL);
    sfEvent event;
    sfMusic *music = music_create(musics, volume_mus);
    sfSprite *sprite_bg = set_sprite(main_bg, p_bg);
    sfSprite *bu[2] = {set_ss(ss, p_se), set_ss(ss, p_sc)};
    sfRenderWindow_setFramerateLimit(win, nb_fps);
    play_music(music);
    while (sfRenderWindow_isOpen(win)) {
        sfRenderWindow_setMouseCursorVisible(win, sfTrue);
        while (sfRenderWindow_pollEvent(win, &event))
            close_event(win, event);
        draw(win, sprite_bg, bu, txt);
        if_click(win, event);
    }
    return 0;
}
