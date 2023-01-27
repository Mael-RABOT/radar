/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** garbage
*/

#include "../include/my.h"

void garbage(sfRenderWindow *window, map_t *map)
{
    for (int i = 0; i < map->objects->tower_nb; i++)
        sfSprite_destroy(map->objects->tower_list[i]->sprite);
    for (int i = 0; i < map->objects->plane_nb; i++)
        sfSprite_destroy(map->objects->plane_list[i]->sprite);
    free(map->corners);
    free(map->objects);
    sfClock_destroy(map->TIME->animation);
    sfClock_destroy(map->TIME->global);
    sfClock_destroy(map->TIME->movement);
    sfRenderWindow_destroy(window);
    free(map);
}
