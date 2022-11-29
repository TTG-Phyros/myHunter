/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef MY
    #define MY


    // * includes
    #include <stdlib.h>
    #include <unistd.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <stdlib.h>
    #include <math.h>

    // * Macros
    #define pos_ti pos_tit[3] = {200, 50, 200}
    #define pos_sbu pos_but[3] = {750, 400, 125}
    #define pos_se p_se[4][2] = {{1735, 915}, {1, 1}, {0, 53}, {153, 153}}
    #define pos_sc p_sc[4][2] = {{1735, 740}, {1, 1}, {153, 53}, {153, 153}}
    #define pos_bg p_bg[2][2] = {{0, 0}, {1, 1}}
    #define p_re p_rep[4][2] = {{920, 875}, {5, 5}, {55, 21}, {20, 32}}
    #define p_shoot p_shot[4][2] = {{920, 830}, {5, 5}, {75, 12}, {20, 41}}
    #define p_shd p_shoted[4][2] = {{920, 770}, {5, 5}, {95, 0}, {20, 53}}
    #define pos_game_bg p_game_bg[2][2] = {{0, 0},{1, 1}}
    #define pos_cursor p_cursor[4][2] = {{0, 0}, {5, 5}, {212, 0}, {10, 10}}
    #define p_fe p_cf [2][4][2] = {{{498, 1000}, {5, 5}, {151, 0}, \
    {22, 34}}, {{498, 1000}, {5, 5}, {173, 0}, {22, 34}}}
    #define p_ma p_cm [2][4][2] = {{{500, 1000}, {5, 5}, {115, 0}, \
    {18, 35}}, {{500, 1000}, {5, 5}, {133, 0}, {18, 35}}}
    #define p_th p_ti [2][4][2] = {{{490, 1000}, {4, 4}, {0, 0}, \
    {27, 40}}, {{490, 1000}, {4, 4}, {27, 0}, {27, 40}}}
    #define di_w width = 1920, height = 1080
    #define videomode sfVideoMode md = {width, height, 32};
    #define nb_fps 60
    #define game_name "My Hunter"
    #define bu_text "Start"
    #define game_font "./content/pixel_police.ttf"
    #define main_bg "./content/fond_3.png"
    #define game_bg "./content/game_bg.png"
    #define ss "./content/sprite_sheet_hunter.png"
    #define voleur "./content/voleur.png"
    #define civilian_ma "./content/civilian_ma.png"
    #define civilian_fe "./content/civilian_fe.png"

    // * main.c
    void if_click(sfRenderWindow *window, sfEvent event);
    int main(void);

    // * game.c
    //void spawn_mob(int nb);
    int can_shoot(int shoot);
    void game(sfRenderWindow *window, sfEvent event);

    // * display_functions.c
    sfSprite *set_sprite(char *filepath, int pos[2][2]);
    sfSprite *set_ss(char *fp, int p_rep[4][2]);
    sfText *text(char *filepath, int *pos_text, char *paraf, sfColor color);

    // * mobs.c
    int mob_initialization(sfSprite *mobs[9][2]);
    int mob_deplacement(sfSprite *mobs[9][2], int nb_frames);
    int spawn_mob(sfSprite *mobs[9][2], int nb_frames);
    void d_mobs(sfSprite *mobs[9][2], int nb_frames, sfRenderWindow *window);

    // * settings.c
    void settings(sfRenderWindow *window, sfEvent event);
    void scoreboard(sfRenderWindow *window, sfEvent event);

#endif
