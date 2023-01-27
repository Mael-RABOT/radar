/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** make_timer
*/

#include "../include/my.h"

timers_t *make_timers(void)
{
    timers_t *res = malloc(sizeof(timers_t));
    res->global = sfClock_create();
    res->movement = sfClock_create();
    res->animation = sfClock_create();
    res->ui = sfClock_create();
    res->time_int = 0;
    return (res);
}
