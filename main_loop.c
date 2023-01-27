/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** main_loop
*/

#include "include/my.h"

int visibility_check(plane_t *plane)
{
    if (plane->take_off == FALSE)
        return (FALSE);
    if (plane->destroyed == TRUE)
        return (FALSE);
    if (plane->landed == TRUE)
        return (FALSE);
    return (TRUE);
}

void plane_update_functions(sfRenderWindow *window, map_t *map,
    launch_control_t *launch)
{
    if (launch->plane_nb == 0)
        return;
    move_list(map, launch, -1);
    animation(launch, map->TIME->animation, map->paused);
    take_off(launch, map->TIME->global, map->paused);
    update_position(launch, map->TIME->movement, map->paused, map->speed_mult);
    check_tower(&(launch));
    check_collision(launch);
    render_plane(window, map, launch);
}

void plane_update(sfRenderWindow *window, map_t *map)
{
    for (int i = 0; i < GRID_NUMBER; i++) {
        plane_update_functions(window, map, map->corners[i]->objects);
        for (int j = 0; j < GRID_NUMBER; j++) {
            plane_update_functions(window, map,
                map->corners[i]->sub_corners[j]->objects);
        }
    }
    plane_update_functions(window, map, map->objects);
}

void function_call(sfRenderWindow *window, map_t *map)
{
    time_text_upd(map);
    speed_time_upd(map->ui_speed, map->speed_mult, map->background_);
    update_render(window, map);
    plane_update(window, map);
}

int main_loop(sfRenderWindow *window, map_t *map)
{
    sfEvent evt;
    map->ui_time = create_ui_text((sfVector2f){STD_WINDOW_WIDTH - 150, 40});
    map->ui_speed = create_ui_text((sfVector2f){STD_WINDOW_WIDTH - 150, 80});
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &evt))
            event_selector(window, evt, &map, &(map->speed_mult));
        function_call(window, map);
        sfRenderWindow_display(window);
    }
    return (EXIT_SUCCESS);
}
