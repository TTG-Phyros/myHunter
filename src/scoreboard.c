/*
** EPITECH PROJECT, 2022
** scoreboard
** File description:
** hunter scoreboard
*/

#include "../include/my.h"

int score_change_sec(int score, int death, sfText *sc)
{
    int buffer = score;
    char *dest = malloc((my_intlen(score) + 8) * sizeof(char));
    if (death == 2 || death == 3) {
        score -= 100;
        if (score > 0)
            merge_int_str("Score : ", dest, score);
    }
    if (death == 1) {
        score += 10;
        if (score > 0)
            merge_int_str("Score : ", dest, score);
    }
    if ((death - 4) == 2 || (death - 4) == 5 || (death - 4) == 8) {
        score -= 100;
        if (score > 0)
            merge_int_str("Score : ", dest, score);
    }
    if (score > 0 && buffer != score) sfText_setString(sc, dest);
    free(dest);
    return score;
}

void death_sound(int death)
{
    sfSound *sound_cho = sfSound_create();
    sfSoundBuffer *buffer_ma = sfSoundBuffer_createFromFile(ma_cho);
    sfSoundBuffer *buffer_fe = sfSoundBuffer_createFromFile(fe_cho);
    sfSoundBuffer *buffer_th = sfSoundBuffer_createFromFile(th_cho);
    sfSound_setVolume(sound_cho, 35);
    if (death == 3) {
        sfSound_setBuffer(sound_cho, buffer_ma);
        sfSound_play(sound_cho);
    }
    if (death == 2) {
        sfSound_setBuffer(sound_cho, buffer_fe);
        sfSound_play(sound_cho);
    }
    if (death == 1) {
        sfSound_setBuffer(sound_cho, buffer_th);
        sfSound_play(sound_cho);
    }
}

int score_change(int death, int score, sfText *sc)
{
    if (death > 0)
        death_sound(death);
    score = score_change_sec(score, death, sc);
    if (score == 0) {
        sfText_setString(sc, "Score : 0");
    }
    return score;
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
