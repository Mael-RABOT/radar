/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** init_map_make_rectangle
*/

#include "../include/my.h"

sfRectangleShape *make_rectangle(sfVector2f pos, sfVector2f size)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfRectangleShape_setPosition(rectangle, pos);
    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setOutlineColor(rectangle, sfWhite);
    sfRectangleShape_setFillColor(rectangle, sfTransparent);
    sfRectangleShape_setOutlineThickness(rectangle, 1);
    return (rectangle);
}

launch_control_t *empty_obj(void)
{
    launch_control_t *empty = malloc(sizeof(launch_control_t));
    empty->tower_nb = 0;
    empty->plane_nb = 0;
    empty->tower_list = NULL;
    empty->plane_list = NULL;
    return (empty);
}

sfIntRect *init_areas(sfIntRect size)
{
    int left = size.left;
    int top = size.top;
    int width = size.width;
    int height = size.height;
    sfIntRect *areas = malloc(1000);
    areas[0] = (sfIntRect){left, top, width / 2, height / 2};
    areas[1] = (sfIntRect){left + width / 2, top, width / 2, height / 2};
    areas[2] = (sfIntRect){left, top + height / 2, width / 2, height / 2};
    areas[3] = (sfIntRect){left + width / 2, top + height / 2, width / 2,
        height / 2};
    return (areas);
}
