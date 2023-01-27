/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** collision
*/

#include "include/my.h"

int my_float_rect_intersect(sfFloatRect rect1, sfFloatRect rect2)
{
    return (rect1.left < rect2.left + rect2.width) &&
            (rect2.left < rect1.left + rect1.width) &&
            (rect1.top < rect2.top + rect2.height) &&
            (rect2.top < rect1.top + rect1.height);
}

void collision_check_bis(launch_control_t *launch, int i, int j)
{
    if (launch->plane_list[i]->tower_in_reach == TRUE ||
    launch->plane_list[j]->tower_in_reach == TRUE)
        return;
    if (i != j && visibility_check(launch->plane_list[i]) == TRUE &&
        visibility_check(launch->plane_list[j]) == TRUE)
        if (my_float_rect_intersect(launch->plane_list[i]->hitbox,
            launch->plane_list[j]->hitbox) == 1) {
            launch->plane_list[i]->destroyed = TRUE;
            launch->plane_list[j]->destroyed = TRUE;
        }
}

void check_collision(launch_control_t *launch)
{
    for (int i = 0; i < launch->plane_nb; i++)
        for (int j = 0; j < launch->plane_nb; j++)
            collision_check_bis(launch, i, j);
}
