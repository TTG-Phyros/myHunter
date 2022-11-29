/*
** EPITECH PROJECT, 2022
** settings
** File description:
** hunter settings
*/

#include "../include/my.h"

int event_handler(sfRenderWindow *window, sfEvent evt)
{
    while (sfRenderWindow_pollEvent(window, &evt)) {
        if (evt.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeySpace))
            return -1;
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    return 0;
}

void settings(sfRenderWindow *window, sfEvent event)
{
    int pos_wip[3] = {200, 200, 125};
    sfText *wip = text(game_font, pos_wip, "Work in Progress", sfWhite);
    while (sfRenderWindow_isOpen(window)) {
        if (event_handler(window, event) == -1)
            return;
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawText(window, wip, NULL);
        sfRenderWindow_display(window);
    }
}
