/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** plane_list_swap
*/

#include "../include/my.h"

int plane_list_swap(launch_control_t *src, launch_control_t *dest, int index,
    id_couple_t new_ID)
{
    if (index >= src->plane_nb)
        return (-1);
    dest->plane_list[dest->plane_nb] = src->plane_list[index];
    dest->plane_list[dest->plane_nb++]->plane_ID = (id_couple_t){0, 0};
    for (int i = index; i < src->plane_nb - 1; i++) {
        src->plane_list[i] = src->plane_list[i + 1];
    }
    src->plane_list[src->plane_nb--] = NULL;
    return (0);
}
