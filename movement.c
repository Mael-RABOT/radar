/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** movement
*/

#include "include/my.h"

void move_plane(plane_t *plane, float speed_mult)
{
    if (visibility_check(plane) == TRUE) {
        plane->pos.x += (plane->direction.x / 20) * speed_mult;
        plane->pos.y += (plane->direction.y / 20) * speed_mult;
        plane->rectangle_pos.x += (plane->direction.x / 20) * speed_mult;
        plane->rectangle_pos.y += (plane->direction.y / 20) * speed_mult;
        plane->hitbox.left = (plane->pos.x) * speed_mult;
        plane->hitbox.top = (plane->pos.y) * speed_mult;
    }
}

void update_position(launch_control_t *launch,
    sfClock *clock, bool_t paused, float speed_mult)
{
    if (sfClock_getElapsedTime(clock).microseconds / 1000000.0 > 0.005
        && paused == FALSE) {
        sfClock_restart(clock);
        for (int i = 0; i < launch->plane_nb; i++) {
            move_plane(launch->plane_list[i], speed_mult);
            landing(launch->plane_list[i]);
        }
    }
}
