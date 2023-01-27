/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** take_off
*/

#include "include/my.h"

void take_off(launch_control_t *launch, sfClock *global_time, bool_t paused)
{
    for (int i = 0; i < launch->plane_nb; i++)
        if (sfClock_getElapsedTime(global_time).microseconds / 1000000.0 >=
            launch->plane_list[i]->delay && paused == FALSE) {
            launch->plane_list[i]->take_off = TRUE;
        }
}
