/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** event
*/

#include "../include/my.h"

void speed_update(sfEvent evt, float *speed_multiplier)
{
    if (evt.type == sfEvtKeyPressed && evt.key.code == sfKeyUp)
        if ((*speed_multiplier) >= 0.25 && (*speed_multiplier) < 4) {
            (*speed_multiplier) = (*speed_multiplier >= 1)
                ? *(speed_multiplier) + 1 : (*speed_multiplier) * 2;
            return;
        }
    if (evt.type == sfEvtKeyPressed && evt.key.code == sfKeyDown)
        if ((*speed_multiplier) > 0.25 && (*speed_multiplier) <= 4) {
            (*speed_multiplier) = (*speed_multiplier > 1)
                ? *(speed_multiplier) - 1 : (*speed_multiplier) / 2;
            return;
        }
    if (evt.type == sfEvtKeyPressed && evt.key.code == sfKeyRight)
        (*speed_multiplier) = 1;
}

void event_selector(sfRenderWindow *window, sfEvent evt, map_t **map,
    float *speed_multiplier)
{
    (evt.type == sfEvtClosed) ? sfRenderWindow_close(window) : "";
    if (evt.type == sfEvtKeyPressed && evt.key.code == 11)
        (*map)->outline_visible = ((*map)->outline_visible == TRUE)
            ? FALSE : TRUE;
    if (evt.type == sfEvtKeyPressed && evt.key.code == 18)
        (*map)->is_visible = ((*map)->is_visible == TRUE) ? FALSE : TRUE;
    if (evt.type == sfEvtKeyPressed && evt.key.code == 16)
        sfRenderWindow_close(window);
    if (evt.type == sfEvtKeyPressed && evt.key.code == 57)
        (*map)->paused = ((*map)->paused == TRUE) ? FALSE : TRUE;
    if (evt.type == sfEvtKeyPressed && evt.key.code == 1) {
        (*map)->background_ = ((*map)->background_ == TRUE) ? FALSE : TRUE;
        (*map)->boundary_color = ((*map)->background_ == TRUE)
            ? sfBlack : sfYellow;
    }
    if (evt.type == sfEvtKeyPressed && evt.key.code == sfKeyG)
        (*map)->grid_ = ((*map)->grid_ == TRUE) ? FALSE : TRUE;
    speed_update(evt, speed_multiplier);
}
