/*
** EPITECH PROJECT, 2022
** mob_death
** File description:
** mob_death
*/

#include "../include/my.h"

int mob_death_sec(int mob_nb, int shoot)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && shoot == nb_fps) {
        if (mob_nb == 2 || mob_nb == 5 || mob_nb == 8) {
            return 1;
        } else {
            return 2;
        }
    }
    return 0;
}

int mob_death(sfRenderWindow *window, sfSprite *mob, int mob_nb, int sh)
{
    int ans = 0;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mob_pos = sfSprite_getPosition(mob);
    if (mouse_pos.x >= mob_pos.x && mouse_pos.x <= mob_pos.x + 140) {
        if (mouse_pos.y >= mob_pos.y && mouse_pos.y <= mob_pos.y + 175) {
            ans = mob_death_sec(mob_nb, sh);
        }
    }
    return ans;
}
