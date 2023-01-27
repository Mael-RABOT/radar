/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** make_background
*/

#include "../include/my.h"

sfSprite *make_background(void)
{
    sfTexture *bg_texture = sfTexture_createFromFile(BACKGROUND, NULL);
    sfSprite *bg_sprite = sfSprite_create();
    sfSprite_setTexture(bg_sprite, bg_texture, 0);
    return (bg_sprite);
}
