/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** outline_position
*/

#include "../include/my.h"

sfVector2f add_head(plane_t *plane)
{
    sfVector2f head;
    double norm = sqrt(pow(plane->AB.x, 2) + pow(plane->AB.y, 2));
    double dist = MAX(PLANE_WIDTH, PLANE_HEIGHT);
    head.x = plane->pos.x + dist * plane->AB.x / norm;
    head.y = plane->pos.y + dist * plane->AB.y / norm;
    return (head);
}

void assign_rectangle_pos_bis(plane_t *plane)
{
    switch (plane->position_case) {
        case CASE_5:
            plane->rectangle_pos.x = plane->pos.x;
            plane->rectangle_pos.y = plane->pos.y;
            return;
        case CASE_6:
            plane->rectangle_pos.x = plane->pos.x - PLANE_WIDTH;
            plane->rectangle_pos.y = plane->pos.y;
            return;
        case CASE_7:
            plane->rectangle_pos.x = plane->pos.x - PLANE_WIDTH;
            plane->rectangle_pos.y = plane->pos.y - PLANE_HEIGHT;
            return;
        case CASE_8:
            plane->rectangle_pos.x = plane->pos.x;
            plane->rectangle_pos.y = plane->pos.y - PLANE_HEIGHT;
            return;
    }
}

void assign_rectangle_pos(plane_t *plane)
{
    sfVector2f head = add_head(plane);
    switch (plane->position_case) {
        case CASE_1:
            plane->rectangle_pos.x = head.x - PLANE_WIDTH;
            plane->rectangle_pos.y = head.y;
            return;
        case CASE_2:
            plane->rectangle_pos.x = head.x - PLANE_WIDTH / 2;
            plane->rectangle_pos.y = head.y - PLANE_HEIGHT;
            return;
        case CASE_3:
            plane->rectangle_pos.x = head.x;
            plane->rectangle_pos.y = head.y - PLANE_HEIGHT / 2;
            return;
        case CASE_4:
            plane->rectangle_pos.x = head.x - PLANE_WIDTH / 2;
            plane->rectangle_pos.y = head.y;
            return;
    }
    assign_rectangle_pos_bis(plane);
}
