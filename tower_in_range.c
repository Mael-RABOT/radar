/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** tower_in_range
*/

#include "include/my.h"

void tower_in_reach(plane_t *plane, tower_t *tower)
{
    if (visibility_check(plane) == FALSE)
        return;
    if (sqrt(pow(tower->pos.x - plane->pos.x, 2) +
            pow(tower->pos.y - plane->pos.y, 2)) <
            tower->radius + MAX(PLANE_WIDTH, PLANE_HEIGHT)) {
        plane->tower_in_reach = TRUE;
        plane->outline_color = sfBlue;
    }
}

void check_tower(launch_control_t **launch)
{
    for (int i = 0; i < (*launch)->plane_nb; i++) {
        (*launch)->plane_list[i]->tower_in_reach = FALSE;
        (*launch)->plane_list[i]->outline_color = sfYellow;
        for (int j = 0; j < (*launch)->tower_nb; j++) {
            tower_in_reach((*launch)->plane_list[i], (*launch)->tower_list[j]);
        }
    }
}
