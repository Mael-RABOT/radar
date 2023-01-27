/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-BSQ-mael.rabot
** File description:
** my.h
*/

#ifndef TEK1_MY_H_
    #define TEK1_MY_H_

    #define MIN(x, y)           (((x) < (y)) ? (x) : (y))
    #define MAX(x, y)           (((x) > (y)) ? (x) : (y))
    #define ABS(x)              ((x) > 0) ? (x) : (-x)
    #define RAD_TO_ANGLE(x)     ((x) * (180 / PI))

    #define PI                  3.14159

    #define STD_WINDOW_WIDTH    1920
    #define STD_WINDOW_HEIGHT   1080
    #define PLANE_WIDTH         20
    #define PLANE_HEIGHT        20
    #define TOWER_WIDTH         100
    #define TOWER_HEIGHT        100
    #define GRID_NUMBER         4

    #define ERR_ARG             1
    #define ERR_FILE            2
    #define ERR_OPN             3
    #define ERR_ARG_MSG         "bad argument, use -h to see help\n"
    #define ERR_FILE_MSG        "bad script format, use -h to see help\n"

    #define MAN_BUFFER_SIZE     2100

    #define DRAGON              "./sources/dragon_small.png"
    #define TOWER               "./sources/fan_tower.png"
    #define BACKGROUND          "./sources/fantasy2.jpg"
    #define BACKGROUND_BLUR     "./sources/fantasy2_blur.jpg"
    #define FONT                "./sources/Freshman.ttf"

    #define CASE_1 1
    #define CASE_2 2
    #define CASE_3 3
    #define CASE_4 4
    #define CASE_5 5
    #define CASE_6 6
    #define CASE_7 7
    #define CASE_8 8
    #define ERROR_CASE 84

    #include "mylib.h"
    #include "my_printf.h"
    #include "my_structs.h"

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>

    #include <math.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/syscall.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <stdint.h>
    #include <time.h>
    #include <sys/sysmacros.h>
    #include <pwd.h>
    #include <grp.h>
    #include <errno.h>
    #include <string.h>

    void add_plane_data(launch_control_t **launch, char *data);
    void add_tower_data(launch_control_t **launch, char *data);
    void event_selector(sfRenderWindow *window, sfEvent evt, map_t **map,
        float *speed_multiplier);
    void add_sprite(launch_control_t **launch);
    void add_direction(launch_control_t **launch);
    void add_rotation(launch_control_t **launch, bool_t rotation);
    void update_render(sfRenderWindow *window, map_t *map);
    void render_tower(sfRenderWindow *window, map_t *map);
    void render_plane(sfRenderWindow *window, map_t *map,
        launch_control_t *launch);
    void check_collision(launch_control_t *launch);
    void landing(plane_t *plane);
    void take_off(launch_control_t *launch, sfClock *global_time,
        bool_t paused);
    void animation(launch_control_t *launch, sfClock *clock, bool_t paused);
    void update_position(launch_control_t *launch, sfClock *clock,
        bool_t paused, float speed_mult);
    void render_grid(sfRenderWindow *window, map_t *map);
    void check_tower(launch_control_t **launch);
    void time_text_upd(map_t *map);
    void speed_time_upd(sfText *text, float speed_mult, bool_t background);
    void move_list(map_t *map, launch_control_t *launch, int ctrl);
    void garbage(sfRenderWindow *window, map_t *map);

    int print_man(void);
    int main_loop(sfRenderWindow *window, map_t *map);
    int visibility_check(plane_t *plane);
    int menu(sfRenderWindow *window);
    int plane_list_swap(launch_control_t *src, launch_control_t *dest,
        int index, id_couple_t new_ID);
    int file_checker(char *path);
    int print_error(int error_type, char *path);

    char **line_extractor(char *data);

    map_t *init_map(settings_t *setting);

    launch_control_t *extract_data(char *path, settings_t *setting);

    timers_t *make_timers(void);

    sfIntRect *init_areas(sfIntRect size);

    sfSprite *plane_sprite(void);
    sfSprite *tower_sprite(void);
    sfSprite *make_background(void);

    sfRectangleShape *plane_outline(void);
    sfRectangleShape *make_rectangle(sfVector2f pos, sfVector2f size);

    sfVector2f plane_pos(plane_t *plane);
    sfVector2f tower_pos(tower_t *tower);
    sfVector2f circle_pos(tower_t *tower);
    sfVector2f rectangle_pos(plane_t *plane);

    sfText *create_ui_text(sfVector2f position);

#endif /* !TEK1_MY_H_ */
