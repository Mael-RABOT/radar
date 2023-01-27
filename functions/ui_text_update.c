/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** ui_text_update
*/

#include "../include/my.h"

char *time_to_char(int nb)
{
    char *res = malloc(10);
    my_strcpy(res, "");
    if (nb < 10)
        my_strcat(res, "0");
    my_strcat(res, int_to_str(nb));
    return (res);
}

char *convert_time(int time_int)
{
    char *time_str = malloc(100);
    my_strcpy(time_str, "");
    int seconds = time_int % 60;
    int minutes = time_int / 60;
    my_strcat(time_str, time_to_char(minutes));
    my_strcat(time_str, " : ");
    my_strcat(time_str, time_to_char(seconds));
    return (time_str);
}

char *convert_speed(float speed_mult)
{
    if (speed_mult == 4.0)
        return ("x4.0");
    if (speed_mult == 3.0)
        return ("x3.0");
    if (speed_mult == 2.0)
        return ("x2.0");
    if (speed_mult == 1.0)
        return ("x1.0");
    if (speed_mult == 0.5)
        return ("x0.5");
    if (speed_mult == 0.25)
        return ("x0.25");
    return ("x1.0");
}

void speed_time_upd(sfText *text, float speed_mult, bool_t background)
{
    if (background == FALSE)
        sfText_setFillColor(text, sfWhite);
    else
        sfText_setFillColor(text, sfBlack);
    sfText_setString(text, convert_speed(speed_mult));
}

void time_text_upd(map_t *map)
{
    if (map->paused == TRUE) {
        sfClock_restart(map->TIME->ui);
        return;
    }
    if (map->background_ == FALSE)
        sfText_setFillColor(map->ui_time, sfWhite);
    else
        sfText_setFillColor(map->ui_time, sfBlack);
    if (sfClock_getElapsedTime(map->TIME->ui).microseconds / 1000000.0 >
        (1.0 / map->speed_mult)) {
        sfClock_restart(map->TIME->ui);
        map->TIME->time_int += 1;
        sfText_setString(map->ui_time, convert_time(map->TIME->time_int));
    }
}
