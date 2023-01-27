/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** rotation
*/

#include "../include/my.h"

int analyse_pos(sfVector2f A, sfVector2f B)
{
    if (A.x < B.x && A.y < B.y)
        return (CASE_1);
    if (A.x > B.x && A.y < B.y)
        return (CASE_2);
    if (A.x > B.x && A.y > B.y)
        return (CASE_3);
    if (A.x < B.x && A.y > B.y)
        return (CASE_4);
    if (A.x < B.x && A.y == B.y)
        return (CASE_5);
    if (A.x == B.x && A.y < B.y)
        return (CASE_6);
    if (A.x > B.x && A.y == B.y)
        return (CASE_7);
    if (A.x == B.x && A.y > B.y)
        return (CASE_8);
    return (ERROR_CASE);
}

float choose_angle(sfVector2f A, sfVector2f B, float alpha, plane_t *plane)
{
    plane->position_case = analyse_pos(A, B);
    switch (plane->position_case) {
        case CASE_1:
            return (alpha);
        case CASE_2:
            return (90 + (90 - alpha));
        case CASE_3:
            return (180 + alpha);
        case CASE_4:
            return (270 + (90 - alpha));
        case CASE_5:
            return (0);
        case CASE_6:
            return (90);
        case CASE_7:
            return (180);
        case CASE_8:
            return (270);
    }
    return (0.0);
}

void add_rotation(launch_control_t **launch, bool_t rotation)
{
    float angle;
    float sqrt_f;
    float AB;
    float CB;
    for (int i = 0; i < (*launch)->plane_nb; i++) {
        CB = ((*launch)->plane_list[i]->target.x -
            (*launch)->plane_list[i]->pos.x);
        AB = sqrt(pow((*launch)->plane_list[i]->AB.x, 2) +
            pow((*launch)->plane_list[i]->AB.y, 2));
        sqrt_f = CB / AB;
        angle = choose_angle((*launch)->plane_list[i]->pos,
                            (*launch)->plane_list[i]->target,
                            90 - RAD_TO_ANGLE(ABS(asin(sqrt_f))),
                            (*launch)->plane_list[i]);
        (*launch)->plane_list[i]->angle = (rotation == TRUE) ? angle : 0.0;
        sfSprite_setRotation((*launch)->plane_list[i]->sprite,
                                (*launch)->plane_list[i]->angle);
    }
}
