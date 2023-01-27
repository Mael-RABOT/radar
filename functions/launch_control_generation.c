/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** generate_launch_control
*/

#include "../include/my.h"

int add_data(launch_control_t **launch, char *data)
{
    switch (data[0]) {
        case 'A':
            add_plane_data(launch, data);
            break;
        case 'T':
            add_tower_data(launch, data);
            break;
        default:
            return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

launch_control_t *extract_data(char *path, settings_t *setting)
{
    launch_control_t *res = malloc(sizeof(launch_control_t));
    res->plane_nb = 0;
    res->tower_nb = 0;
    res->plane_list = malloc(sizeof(plane_t) * 100000);
    res->tower_list = malloc(sizeof(tower_t) * 100);
    FILE *stream = fopen(path, "r");
    if (!stream)
        return (NULL);
    size_t len = 0;
    char *line = NULL;
    while (getline(&line, &len, stream) != -1)
        add_data(&res, line);
    fclose(stream);
    add_sprite(&res);
    add_direction(&res);
    add_rotation(&res, setting->rotation);
    return (res);
}
