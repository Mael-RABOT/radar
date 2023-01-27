/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** rendering
*/

#include "include/my.h"

void render_plane_bis(sfRenderWindow *window, map_t *map, int i,
    plane_t **planes)
{
    if (map->is_visible == TRUE)
        sfRenderWindow_drawSprite(window, planes[i]->sprite, NULL);
    if (map->outline_visible == TRUE)
        sfRenderWindow_drawRectangleShape(window,
                                    planes[i]->outline, NULL);
    sfSprite_setPosition(planes[i]->sprite, plane_pos(planes[i]));
    sfRectangleShape_setOutlineColor(planes[i]->outline,
                                planes[i]->outline_color);
    sfRectangleShape_setPosition(planes[i]->outline,
                                rectangle_pos(planes[i]));
}

void render_plane(sfRenderWindow *window, map_t *map, launch_control_t *launch)
{
    plane_t **planes = launch->plane_list;
    int plane_nb = launch->plane_nb;
    for (int i = 0; i < plane_nb; i++)
        if (visibility_check(planes[i]) == TRUE)
            render_plane_bis(window, map, i, planes);
}

void render_tower(sfRenderWindow *window, map_t *map)
{
    tower_t **towers = map->objects->tower_list;
    int tower_nb = map->objects->tower_nb;
    for (int i = 0; i < tower_nb; i++) {
        if (map->is_visible == TRUE)
            sfRenderWindow_drawSprite(window, towers[i]->sprite, NULL);
        if (map->outline_visible == TRUE)
            sfRenderWindow_drawCircleShape(window, towers[i]->circle, NULL);
        sfCircleShape_setOutlineColor(towers[i]->circle, map->boundary_color);
        sfCircleShape_setPosition(towers[i]->circle, circle_pos(towers[i]));
        sfSprite_setPosition(towers[i]->sprite, tower_pos(towers[i]));
    }
}

void update_render(sfRenderWindow *window, map_t *map)
{
    sfRenderWindow_clear(window, sfBlack);
    if (map->background_ == TRUE)
        sfRenderWindow_drawSprite(window, map->bg, NULL);
    render_tower(window, map);
    if (map->grid_ == TRUE)
        render_grid(window, map);
    sfRenderWindow_drawText(window, map->ui_time, NULL);
    sfRenderWindow_drawText(window, map->ui_speed, NULL);
}
