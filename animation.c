/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** animation
*/

#include "include/my.h"

void find_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left = (rect->left + offset) % max_value;
}

void animation(launch_control_t *launch, sfClock *clock, bool_t paused)
{
    if (sfClock_getElapsedTime(clock).microseconds / 1000000.0 > 0.25 &&
        paused == FALSE) {
        for (int i = 0; i < launch->plane_nb; i++) {
            find_rect(&(launch->plane_list[i]->sprite_rect),
                PLANE_WIDTH, PLANE_WIDTH * 3);
            sfSprite_setTextureRect(launch->plane_list[i]->sprite,
                                    launch->plane_list[i]->sprite_rect);
        }
        sfClock_restart(clock);
    }
}
