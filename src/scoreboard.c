/*
** EPITECH PROJECT, 2022
** scoreboard
** File description:
** hunter scoreboard
*/

#include "../include/my.h"

int score_change(sfRenderWindow *window, int death, int score, sfText *sc)
{
    if (death == 2)
        score -= 100;
    if (death == 1)
        score += 10;
    if ((death - 4) == 2 || (death - 4) == 5 || (death - 4) == 8)
        score -= 100;
    if (score > 0) {
        char *dest = malloc((my_intlen(score) + 8) * sizeof(char));
        merge_int_str("Score : ", dest, score);
        sfText_setString(sc, dest);
        free(dest);
    }
    if (score == 0) {
        sfText_setString(sc, "Score : 0");
    }
    if (score < 0) {
        sfRenderWindow_close(window);
        return -1;
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

int evt_handler(sfRenderWindow *window, sfEvent evt)
{
    while (sfRenderWindow_pollEvent(window, &evt)) {
        if (evt.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeySpace))
            return -1;
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
    return 0;
}

void scoreboard(sfRenderWindow *window, sfEvent event)
{
    int pos_wip[3] = {200, 200, 125};
    sfText *wip = text(game_font, pos_wip, "Work in Progress", sfWhite);
    while (sfRenderWindow_isOpen(window)) {
        if (evt_handler(window, event) == -1)
            return;
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawText(window, wip, NULL);
        sfRenderWindow_display(window);
    }
}
