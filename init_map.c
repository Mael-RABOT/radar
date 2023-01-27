/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** init_map
*/

#include "include/my.h"

corner_t *init_mini_corner(sfIntRect area)
{
    corner_t *mini_corner = malloc(sizeof(corner_t));
    mini_corner->sub_corners = NULL;
    mini_corner->objects = malloc(sizeof(launch_control_t));
    mini_corner->objects->plane_list = malloc(sizeof(plane_t) * 10000);
    mini_corner->objects->tower_list = NULL;
    mini_corner->objects->plane_nb = 0;
    mini_corner->objects->tower_nb = 0;
    mini_corner->area = area;
    mini_corner->rectangle = make_rectangle((sfVector2f){area.left, area.top},
        (sfVector2f){area.width, area.height});
    return (mini_corner);
}

corner_t *init_sub_corner(sfIntRect area, int parent_id)
{
    sfIntRect *areas = init_areas(area);
    corner_t *sub_corner = malloc(sizeof(corner_t));
    sub_corner->sub_corners = malloc(sizeof(corner_t) * 4);
    for (int i = 0; i < 4; i++) {
        sub_corner->sub_corners[i] = init_mini_corner(areas[i]);
        sub_corner->sub_corners[i]->ID = (id_couple_t){parent_id, i};
    }
    sub_corner->objects = malloc(sizeof(launch_control_t));
    sub_corner->objects->plane_list = malloc(sizeof(plane_t) * 10000);
    sub_corner->objects->tower_list = NULL;
    sub_corner->objects->plane_nb = 0;
    sub_corner->objects->tower_nb = 0;
    sub_corner->area = area;
    sub_corner->rectangle = make_rectangle((sfVector2f){area.left, area.top},
        (sfVector2f){area.width, area.height});
    return (sub_corner);
}

corner_t **init_corner_list(void)
{
    corner_t **list = malloc(sizeof(corner_t) * 4);
    sfIntRect *areas = init_areas((sfIntRect){0, 0,
        STD_WINDOW_WIDTH, STD_WINDOW_HEIGHT});
    for (int i = 0; i < 4; i++) {
        list[i] = init_sub_corner(areas[i], i);
        list[i]->ID = (id_couple_t){-1, i};
    }
    return (list);
}

map_t *init_map(settings_t *setting)
{
    map_t *res = malloc(sizeof(map_t));
    res->TIME = make_timers();
    res->bg = make_background();
    res->is_visible = setting->visible;
    res->outline_visible = setting->outline;
    res->paused = FALSE;
    res->background_ = setting->bg;
    res->grid_ = setting->grid;
    res->boundary_color = (setting->bg == TRUE) ? sfBlack : sfYellow;
    res->speed_mult = setting->speed;
    res->map_ID = (id_couple_t){0, -1};
    res->corners = init_corner_list();
    return (res);
}
