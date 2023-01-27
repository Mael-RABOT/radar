/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** menu
*/

#include "include/my.h"

void menu_event(sfRenderWindow *window, sfEvent event, int *window_status)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyQ) {
        *window_status = -1;
        return;
    }
    if (event.type == sfEvtKeyPressed || event.type == sfEvtMouseButtonPressed)
        *window_status = 0;
}

int menu(sfRenderWindow *window)
{
    sfEvent evt;
    sfTexture *texture = sfTexture_createFromFile(BACKGROUND_BLUR, NULL);
    sfSprite *background = sfSprite_create();
    sfSprite_setTexture(background, texture, sfFalse);
    int window_status = 1;
    while (window_status) {
        while (sfRenderWindow_pollEvent(window, &evt))
            menu_event(window, evt, &window_status);
        if (window_status == -1) {
            sfTexture_destroy(texture);
            sfSprite_destroy(background);
            return (1);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, background, NULL);
        sfRenderWindow_display(window);
    }
    sfTexture_destroy(texture);
    sfSprite_destroy(background);
    return (EXIT_SUCCESS);
}
