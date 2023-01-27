/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** add_data
*/
#include "../include/my.h"

sfFloatRect add_hitbox(void)
{
    sfFloatRect res = {0.0, 0.0, (float)PLANE_WIDTH, (float)PLANE_HEIGHT};
    return (res);
}

sfIntRect add_rect(void)
{
    sfIntRect res = {0, 0, PLANE_WIDTH, PLANE_HEIGHT};
    return (res);
}

void add_plane_data(launch_control_t **launch, char *data)
{
    (*launch)->plane_list[(*launch)->plane_nb] = malloc(sizeof(plane_t));
    (*launch)->plane_list[(*launch)->plane_nb]->pos.x =
        my_getnbr(line_extractor(data)[0]);
    (*launch)->plane_list[(*launch)->plane_nb]->pos.y =
        my_getnbr(line_extractor(data)[1]);
    (*launch)->plane_list[(*launch)->plane_nb]->target.x =
        my_getnbr(line_extractor(data)[2]);
    (*launch)->plane_list[(*launch)->plane_nb]->target.y =
        my_getnbr(line_extractor(data)[3]);
    (*launch)->plane_list[(*launch)->plane_nb]->speed =
        my_getnbr(line_extractor(data)[4]);
    (*launch)->plane_list[(*launch)->plane_nb]->delay =
        my_getnbr(line_extractor(data)[5]);
    (*launch)->plane_list[(*launch)->plane_nb]->outline_color = sfGreen;
    (*launch)->plane_list[(*launch)->plane_nb]->hitbox = add_hitbox();
    (*launch)->plane_list[(*launch)->plane_nb]->landed = FALSE;
    (*launch)->plane_list[(*launch)->plane_nb]->take_off = FALSE;
    (*launch)->plane_list[(*launch)->plane_nb]->plane_ID = (id_couple_t){0, -1};
    (*launch)->plane_list[(*launch)->plane_nb]->sprite_rect = add_rect();
    (*launch)->plane_nb++;
}

void add_tower_data(launch_control_t **launch, char *data)
{
    (*launch)->tower_list[(*launch)->tower_nb] = malloc(sizeof(tower_t));
    (*launch)->tower_list[(*launch)->tower_nb]->pos.x =
        my_getnbr(line_extractor(data)[0]);
    (*launch)->tower_list[(*launch)->tower_nb]->pos.y =
        my_getnbr(line_extractor(data)[1]);
    (*launch)->tower_list[(*launch)->tower_nb]->radius =
        (MAX(STD_WINDOW_WIDTH, STD_WINDOW_HEIGHT) *
        my_getnbr(line_extractor(data)[2]) / 100);
    (*launch)->tower_nb++;
}
