/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** landing
*/

#include "include/my.h"


void landing_direct_line(plane_t *plane)
{
    if (plane->position_case == CASE_5 && plane->pos.x > plane->target.x)
        plane->landed = TRUE;
    if (plane->position_case == CASE_6 && plane->pos.y > plane->target.y)
        plane->landed = TRUE;
    if (plane->position_case == CASE_7 && plane->pos.x < plane->target.x)
        plane->landed = TRUE;
    if (plane->position_case == CASE_8 && plane->pos.y < plane->target.y)
        plane->landed = TRUE;
}

void landing(plane_t *plane)
{
    if (visibility_check(plane) == FALSE)
        return;
    if (plane->position_case == CASE_1 && plane->pos.x > plane->target.x &&
        plane->pos.y > plane->target.y)
        plane->landed = TRUE;
    if (plane->position_case == CASE_2 && plane->pos.x < plane->target.x &&
        plane->pos.y > plane->target.y)
        plane->landed = TRUE;
    if (plane->position_case == CASE_3 && plane->pos.x < plane->target.x &&
        plane->pos.y < plane->target.y)
        plane->landed = TRUE;
    if (plane->position_case == CASE_4 && plane->pos.x > plane->target.x &&
        plane->pos.y < plane->target.y)
        plane->landed = TRUE;
    landing_direct_line(plane);
}
