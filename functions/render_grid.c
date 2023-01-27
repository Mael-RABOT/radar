/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** render_grid
*/

#include "../include/my.h"

void render_grid(sfRenderWindow *window, map_t *map)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            sfRenderWindow_drawRectangleShape(window,
                map->corners[i]->sub_corners[j]->rectangle, NULL);
        sfRenderWindow_drawRectangleShape(window, map->corners[i]->rectangle,
            NULL);
    }
}
