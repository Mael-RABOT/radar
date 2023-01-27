/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** sprite_generation
*/

#include "../include/my.h"

sfRectangleShape *plane_outline(void)
{
    sfRectangleShape *res = sfRectangleShape_create();
    sfVector2f size = {PLANE_HEIGHT, PLANE_WIDTH};
    sfRectangleShape_setSize(res, size);
    sfRectangleShape_setOutlineThickness(res, 1);
    sfRectangleShape_setOutlineColor(res, sfGreen);
    sfRectangleShape_setOrigin(res,
        (sfVector2f){PLANE_HEIGHT / 2, PLANE_WIDTH / 2});
    sfRectangleShape_setFillColor(res, sfTransparent);
    return (res);
}

sfSprite *plane_sprite(void)
{
    sfIntRect rect = {0, 0, 47, 50};
    sfTexture *plane_texture =
        sfTexture_createFromFile(DRAGON, NULL);
    sfSprite *plane_sprite = sfSprite_create();
    sfSprite_setTexture(plane_sprite, plane_texture, sfFalse);
    sfSprite_setOrigin(plane_sprite,
        (sfVector2f){PLANE_HEIGHT / 2, PLANE_WIDTH / 2});
    sfSprite_setTextureRect(plane_sprite, rect);
    return (plane_sprite);
}

sfSprite *tower_sprite(void)
{
    sfTexture *tower_texture =
        sfTexture_createFromFile(TOWER, NULL);
    sfSprite *tower_sprite = sfSprite_create();
    sfSprite_setTexture(tower_sprite, tower_texture, sfFalse);
    sfSprite_setOrigin(tower_sprite,
        (sfVector2f){TOWER_HEIGHT / 2, TOWER_WIDTH / 2});
    return (tower_sprite);
}
