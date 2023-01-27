/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-mael.rabot
** File description:
** my_structs
*/

#ifndef B_MUL_100_LYN_1_1_MYHUNTER_MAEL_RABOT_MY_STRUCTS_H_
    #define B_MUL_100_LYN_1_1_MYHUNTER_MAEL_RABOT_MY_STRUCTS_H_

    #include "SFML/System.h"
    #include "SFML/Graphics.h"
    #include "my.h"

typedef enum {TRUE, FALSE} bool_t;

typedef struct id_couple {
    int parent_id;
    int id;
} id_couple_t;

typedef struct settings {
    bool_t rotation;
    bool_t visible;
    bool_t outline;
    bool_t bg;
    bool_t grid;
    int speed;
} settings_t;

typedef struct timers {
    sfClock *global;
    sfClock *movement;
    sfClock *animation;
    sfClock *ui;
    int time_int;
} timers_t;

typedef struct tower {
    sfSprite *sprite;
    sfCircleShape *circle;
    sfVector2f pos;
    int radius;
} tower_t;

typedef struct plane {
    sfSprite *sprite;
    sfRectangleShape *outline;
    sfVector2f pos;
    sfVector2f rectangle_pos;
    sfVector2f target;
    sfVector2f direction;
    sfVector2f AB;
    int speed;
    int delay;
    float angle;
    int position_case;
    id_couple_t plane_ID;
    sfFloatRect hitbox;
    sfColor outline_color;
    bool_t take_off;
    bool_t landed;
    bool_t destroyed;
    bool_t tower_in_reach;
    sfIntRect sprite_rect;
} plane_t;

typedef struct launch_control {
    plane_t **plane_list;
    tower_t **tower_list;
    int plane_nb;
    int tower_nb;
} launch_control_t;

typedef struct corner {
    id_couple_t ID;
    struct corner **sub_corners;
    sfIntRect area;
    launch_control_t *objects;
    sfRectangleShape *rectangle;
} corner_t;

typedef struct map {
    corner_t **corners;
    sfIntRect area;
    launch_control_t *objects;
    bool_t leaf;
    bool_t is_visible;
    bool_t outline_visible;
    bool_t paused;
    bool_t background_;
    bool_t grid_;
    id_couple_t map_ID;
    timers_t *TIME;
    sfSprite *bg;
    sfColor boundary_color;
    sfText *ui_time;
    sfText *ui_speed;
    float speed_mult;
} map_t;

#endif /* !B_MUL_100_LYN_1_1_MYHUNTER_MAEL_RABOT_MY_STRUCTS_H_ */
