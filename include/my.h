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
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <math.h>

    // * Macros
    #define pos_ti pos_tit[3] = {200, 50, 200}
    #define pos_sbu pos_but[3] = {750, 400, 125}
    #define pos_csc p_csc[3] = {30, 955, 75}
    #define game_ove game_ov[3] = {200, 200, 200}
    #define peak_scor p_sco[3] = {250, 450, 125}
    #define pos_se p_se[4][2] = {{1735, 915}, {1, 1}, {0, 53}, {153, 153}}
    #define pos_sc p_sc[4][2] = {{1735, 740}, {1, 1}, {153, 53}, {153, 153}}
    #define pos_bg p_bg[2][2] = {{0, 0}, {1, 1}}
    #define p_re p_rep[4][2] = {{920, 875}, {5, 5}, {55, 21}, {20, 32}}
    #define p_shoot p_shot[4][2] = {{920, 830}, {5, 5}, {75, 12}, {20, 41}}
    #define p_shd p_shoted[4][2] = {{920, 770}, {5, 5}, {95, 0}, {20, 53}}
    #define pos_game_bg p_game_bg[2][2] = {{0, 0},{1.7, 1.7}}
    #define pos_bridge p_bridge[2][2] = {{0, 867},{1.7, 1.8}}
    #define pos_cursor p_cursor[4][2] = {{0, 0}, {5, 5}, {212, 0}, {10, 10}}
    #define p_fe p_cf[2][4][2] = {{{498, 1000}, {5, 5}, {151, 0}, \
    {22, 34}}, {{498, 1000}, {5, 5}, {173, 0}, {22, 34}}}
    #define p_ma p_cm[2][4][2] = {{{500, 1000}, {5, 5}, {115, 0}, \
    {18, 35}}, {{500, 1000}, {5, 5}, {133, 0}, {18, 35}}}
    #define p_th p_ti[2][4][2] = {{{490, 1000}, {4, 4}, {0, 0}, \
    {27, 40}}, {{490, 1000}, {4, 4}, {27, 0}, {27, 40}}}
    #define di_w width = 1920, height = 1080
    #define videomode sfVideoMode md = {width, height, 32};
    #define nb_fps 60
    #define game_name "My Hunter"
    #define bu_text "Start"
    #define game_font "./content/pixel_police.ttf"
    #define main_bg "./content/main_bg.png"
    #define game_bg "./content/game_bg.png"
    #define bridge "./content/bridge.png"
    #define ss "./content/sprite_sheet_hunter.png"
    #define main_theme "./content/musics/main_theme.ogg"
    #define mus *musics = "./content/musics/musics.ogg"
    #define v_mus volume_mus = 50
    #define p_sound "./content/effects/pistol_shoot.ogg"
    #define ma_cho "./content/effects/man_groan.ogg"
    #define fe_cho "./content/effects/fem_groan.ogg"
    #define th_cho "./content/effects/thie_groan.ogg"

    // * display_functions.c
    sfSprite *ssf(char *filepath, float pos[2][2]);
    sfSprite *set_sprite(char *filepath, int pos[2][2]);
    sfSprite *set_ss(char *fp, int p_rep[4][2]);
    sfText *text(char *filepath, int *pos_text, char *paraf, sfColor color);

    // * flag_h.c
    int flag_h(int argc, char **argv);
    void flag_h_second(void);
    void flag_h_third(void);

    // * game.c
    void game_over(sfRenderWindow *window, int score);
    int display_game(sfRenderWindow *win, sfText *sc, sfSprite *csr, int sh);
    int evt_hdl(sfRenderWindow *win, sfEvent evt, int st, sfSprite *cs);
    void game(sfRenderWindow *window, sfEvent event);

    // * main.c
    void redirect(sfRenderWindow *window, sfEvent event, int choice);
    void if_click(sfRenderWindow *window, sfEvent event);
    int close_event(sfRenderWindow *window, sfEvent event);
    void draw(sfRenderWindow *win, sfSprite *bg, sfSprite *bu[2], sfText **txt);
    int main(int argc, char **argv);

    // * mob_death.c
    int mob_death_sec(int mob_nb, int shoot);
    int mob_death(sfRenderWindow *window, sfSprite *mob, int mob_nb, int sh);

    // * mobs.c
    int mob_initialization(sfSprite *mobs[9][2]);
    int mob_dplc(sfSprite *mob[9][2], int n_fr, sfRenderWindow *win, int sh);
    int spawn_mob(sfSprite *mobs[9][2], int nb_frames);
    void d_mobs(sfSprite *mobs[9][2], int nb_frames, sfRenderWindow *window);

    // * music.c
    sfMusic *music_create(char *filepath, float volume);
    void play_music(sfMusic *musics);

    // * policeman.c
    int can_shoot(int shoot);
    void pmm(sfRenderWindow *window, int shoot);

    // * scoreboard.c
    int score_change_sec(int score, int death, sfText *sc);
    void scoreboard(sfRenderWindow *window, sfEvent event);
    void death_sound(int death);
    int score_change(int death, int score, sfText *sc);
    int evt_handler(sfRenderWindow *window, sfEvent evt);

    // * settings.c
    int event_handler(sfRenderWindow *window, sfEvent evt);
    void settings(sfRenderWindow *window, sfEvent event);

    // * transformations.c
    int my_intlen(int nb);
    int my_strlen(char const *str);
    char *merge_int_str(char *str, char *dest, int nb);

#endif
