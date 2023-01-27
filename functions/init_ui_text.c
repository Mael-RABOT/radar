/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** init_text_ui
*/

#include "../include/my.h"

sfText *create_ui_text(sfVector2f position)
{
    sfText *ui_text = sfText_create();
    sfFont *font = sfFont_createFromFile(FONT);
    sfText_setPosition(ui_text, position);
    sfText_setFont(ui_text, font);
    return (ui_text);
}
