/*
** EPITECH PROJECT, 2022
** Display functions
** File description:
** Display Functions
*/

#include "../include/my.h"

sfSprite *ssf(char *filepath, float pos[2][2])
{
    sfTexture *texture_sprite;
    sfVector2f pos_sprite = {pos[0][0], pos[0][1]};
    sfVector2f scale_sprite = {pos[1][0], pos[1][1]};
    texture_sprite = sfTexture_createFromFile(filepath, NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture_sprite, sfTrue);
    sfSprite_setPosition(sprite, pos_sprite);
    sfSprite_scale(sprite, scale_sprite);
    return sprite;
}

sfSprite *set_sprite(char *filepath, int pos[2][2])
{
    sfTexture *texture_sprite;
    sfVector2f pos_sprite = {pos[0][0], pos[0][1]};
    sfVector2f scale_sprite = {pos[1][0], pos[1][1]};
    texture_sprite = sfTexture_createFromFile(filepath, NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture_sprite, sfTrue);
    sfSprite_setPosition(sprite, pos_sprite);
    sfSprite_scale(sprite, scale_sprite);
    return sprite;
}

sfSprite *set_ss(char *fp, int p_rep[4][2])
{
    sfTexture *texture_sprite;
    sfVector2f pos_sprite = {p_rep[0][0], p_rep[0][1]};
    sfVector2f pm_scale = {p_rep[1][0], p_rep[1][1]};
    sfIntRect *rect = malloc(sizeof(sfIntRect));
    rect->left = p_rep[2][0];
    rect->top = p_rep[2][1];
    rect->width = p_rep[3][0];
    rect->height = p_rep[3][1];
    texture_sprite = sfTexture_createFromFile(fp, rect);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture_sprite, sfTrue);
    sfSprite_setPosition(sprite, pos_sprite);
    sfSprite_scale(sprite, pm_scale);
    return sprite;
}

sfText *text(char *filepath, int *pos_text, char *paraf, sfColor color)
{
    sfFont *font = sfFont_createFromFile(filepath);
    sfText *text = sfText_create();
    sfText_setString(text, paraf);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, pos_text[2]);
    sfText_setColor(text, color);
    sfVector2f pos_title = {pos_text[0], pos_text[1]};
    sfText_setPosition(text, pos_title);
    return text;
}
