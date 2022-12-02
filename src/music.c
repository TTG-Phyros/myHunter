/*
** EPITECH PROJECT, 2022
** music
** File description:
** music
*/

#include "../include/my.h"

sfMusic *music_create(char *filepath, float volume)
{
    sfMusic *music = sfMusic_createFromFile(filepath);
    sfMusic_setVolume(music, volume);
    return music;
}

void play_music(sfMusic *musics)
{
    sfMusic_setLoop(musics, sfTrue);
    sfMusic_play(musics);
}
