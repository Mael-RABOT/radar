/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** obj_position
*/

#include "../include/my.h"

sfVector2f rectangle_pos(plane_t *plane)
{
    sfVector2f res;
    res.x = plane->pos.x;
    res.y = plane->pos.y;
    return (res);
}

sfVector2f plane_pos(plane_t *plane)
{
    sfVector2f res;
    res.x = plane->pos.x;
    res.y = plane->pos.y;
    return (res);
}

sfVector2f tower_pos(tower_t *tower)
{
    sfVector2f res;
    res.x = tower->pos.x;
    res.y = tower->pos.y;
    return (res);
}

sfVector2f circle_pos(tower_t *tower)
{
    sfVector2f res;
    res.x = tower->pos.x - tower->radius;
    res.y = tower->pos.y - tower->radius;
    return (res);
}
