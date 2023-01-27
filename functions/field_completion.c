/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** field_completion
*/

#include "../include/my.h"

sfCircleShape *make_circle(int radius)
{
    sfCircleShape *res = sfCircleShape_create();
    sfCircleShape_setOutlineColor(res, sfBlue);
    sfCircleShape_setRadius(res, radius);
    sfCircleShape_setOutlineThickness(res, 2);
    sfCircleShape_setFillColor(res, sfTransparent);
    return (res);
}

void add_sprite(launch_control_t **launch)
{
    for (int i = 0; i < (*launch)->plane_nb; i++) {
        (*launch)->plane_list[i]->sprite = plane_sprite();
        (*launch)->plane_list[i]->outline =
            plane_outline();
        (*launch)->plane_list[i]->destroyed = FALSE;
        (*launch)->plane_list[i]->landed = FALSE;
    }
    for (int j = 0; j < (*launch)->tower_nb; j++) {
        (*launch)->tower_list[j]->sprite = tower_sprite();
        (*launch)->tower_list[j]->circle = make_circle(
            (*launch)->tower_list[j]->radius);
    }
}

void add_direction(launch_control_t **launch)
{
    sfVector2f dir;
    float AB;
    float reduction;
    for (int i = 0; i < (*launch)->plane_nb; i++) {
        dir.x = (*launch)->plane_list[i]->target.x -
                (*launch)->plane_list[i]->pos.x;
        dir.y = (*launch)->plane_list[i]->target.y -
                (*launch)->plane_list[i]->pos.y;
        (*launch)->plane_list[i]->AB = dir;
        AB = sqrt(pow(dir.x, 2) + pow(dir.y, 2));
        reduction = (100 * (*launch)->plane_list[i]->speed) / AB;
        (*launch)->plane_list[i]->direction.x = (dir.x * reduction) / 200;
        (*launch)->plane_list[i]->direction.y = (dir.y * reduction) / 200;
    }
}
