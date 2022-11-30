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
    #define pos_csc p_csc[3] = {30, 955, 75}
    #define pos_se p_se[4][2] = {{1735, 915}, {1, 1}, {0, 53}, {153, 153}}
    #define pos_sc p_sc[4][2] = {{1735, 740}, {1, 1}, {153, 53}, {153, 153}}
    #define pos_bg p_bg[2][2] = {{0, 0}, {1, 1}}
    #define p_re p_rep[4][2] = {{920, 875}, {5, 5}, {55, 21}, {20, 32}}
    #define p_shoot p_shot[4][2] = {{920, 830}, {5, 5}, {75, 12}, {20, 41}}
    #define p_shd p_shoted[4][2] = {{920, 770}, {5, 5}, {95, 0}, {20, 53}}
    #define pos_game_bg p_game_bg[2][2] = {{0, 0},{1.7, 1.7}}
    #define pos_bridge p_bridge[2][2] = {{0, 867},{1.7, 1.8}}
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
    #define bridge "./content/bridge.png"
    #define ss "./content/sprite_sheet_hunter.png"

    // * main.c
    void if_click(sfRenderWindow *window, sfEvent event);
    int main(int argc, char **argv);

    // * game.c
    int display_game(sfRenderWindow *win, sfText *sc, sfSprite *csr, int sh);
    void game(sfRenderWindow *window, sfEvent event);

    // * display_functions.c
    sfSprite *set_sprite_float(char *filepath, float pos[2][2]);
    sfSprite *set_sprite(char *filepath, int pos[2][2]);
    sfSprite *set_ss(char *fp, int p_rep[4][2]);
    sfText *text(char *filepath, int *pos_text, char *paraf, sfColor color);

    // * mobs.c
    int mob_initialization(sfSprite *mobs[9][2]);
    int mob_dplc(sfSprite *mob[9][2], int n_fr, sfRenderWindow *win, int sh);
    int spawn_mob(sfSprite *mobs[9][2], int nb_frames);
    void d_mobs(sfSprite *mobs[9][2], int nb_frames, sfRenderWindow *window);

    // * settings.c
    int event_handler(sfRenderWindow *window, sfEvent evt);
    void settings(sfRenderWindow *window, sfEvent event);

    // * scoreboard.c
    void scoreboard(sfRenderWindow *window, sfEvent event);
    int score_change(sfRenderWindow *window, int death, int score, sfText *sc);
    int evt_hdl(sfRenderWindow *window, sfEvent event, sfSprite *cs, int st);
    int evt_handler(sfRenderWindow *window, sfEvent evt);

    // * policeman.c
    int can_shoot(int shoot);
    void pmm(sfRenderWindow *window, int shoot);

    // * flag_h.c
    int flag_h(int argc, char **argv);
    void flag_h_second(void);

    // * mob_death.c
    int mob_death_sec(int mob_nb, int shoot);
    int mob_death(sfRenderWindow *window, sfSprite *mob, int mob_nb, int sh);

    // * transformations.c
    int my_strlen(char const *str);
    int my_intlen(int nb);
    char *merge_int_str(char *str, char *dest, int nb);

#endif
