/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** move_plane_list
*/

#include "include/my.h"

int my_rect_intersect(sfFloatRect rect1, sfIntRect rect2)
{
    return (rect1.left < rect2.left + rect2.width) &&
        (rect2.left < rect1.left + rect1.width) &&
        (rect1.top < rect2.top + rect2.height) &&
        (rect2.top < rect1.top + rect1.height);
}

void move_action(map_t *map, launch_control_t *launch, int index,
    id_couple_t id)
{
    plane_t *plane = launch->plane_list[index];
    if (my_rect_intersect(plane->hitbox,
    map->corners[id.parent_id]->sub_corners[id.id]->area) == 1) {
        if (launch ==
            map->corners[id.parent_id]->sub_corners[id.id]->objects) {
            return;
        }
        plane_list_swap(launch,
        map->corners[id.parent_id]->sub_corners[id.id]->objects, index, id);
        return;
    }
}

void move_list_plane(map_t *map, launch_control_t *launch, int index)
{
    for (int i = 0; i < GRID_NUMBER; i++) {
        for (int j = 0; j < GRID_NUMBER; j++) {
            move_action(map, launch, index, (id_couple_t){i, j});
        }
    }
}

void move_list(map_t *map, launch_control_t *launch, int ctrl)
{
    if (ctrl == -1)
        return;
    for (int i = 0; i < launch->plane_nb; i++) {
        move_list_plane(map, launch, i);
    }
}
