/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** main
*/

#include "include/my.h"

sfRenderWindow *init_window(void)
{
    sfVideoMode mode = {STD_WINDOW_WIDTH, STD_WINDOW_HEIGHT, 32};
    sfRenderWindow *res = sfRenderWindow_create(mode, "My Radar",
        sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(res, 60);
    return (res);
}

void setting_upd(char const *arg, char *value, settings_t **settings)
{
    if (arg[0] != '-')
        return;
    switch (arg[1]) {
        case 'R': (*settings)->rotation = FALSE;
            break;
        case 'L': (*settings)->outline = FALSE;
            break;
        case 'S': (*settings)->visible = FALSE;
            break;
        case 'B': (*settings)->bg = FALSE;
            break;
        case 'G': (*settings)->grid = TRUE;
            break;
        case 'M': (*settings)->speed = my_getnbr(value);
    }
}

settings_t *init_settings(int ac, char **av)
{
    settings_t *sett = malloc(sizeof(settings_t));
    sett->bg = TRUE;
    sett->outline = TRUE;
    sett->visible = TRUE;
    sett->rotation = TRUE;
    sett->grid = FALSE;
    sett->speed = 1;
    if (ac <= 1)
        return (NULL);
    for (int i = 0; i < ac - 1; i++)
        setting_upd(av[i], av[i + 1], &sett);
    if (sett->speed < 1 || sett->speed > 4)
        sett->speed = 1;
    return (sett);
}

void launch_main_loop(sfRenderWindow *window, map_t *map)
{
    main_loop(window, map);
    garbage(window, map);
}

int main(int ac, char **av)
{
    settings_t *setting = init_settings(ac, av);
    if (setting == NULL)
        return (print_error(ERR_ARG, av[ac - 1]));
    if (av[1][0] == '-' && av[1][1] == 'h')
        return (print_man());
    if (open(av[ac - 1], O_RDONLY) != -1 &&
    file_checker(av[ac - 1]) == EXIT_FAILURE)
        return (print_error(ERR_FILE, av[ac - 1]));
    launch_control_t *launch = extract_data(av[ac - 1], setting);
    if (launch == NULL)
        return (print_error(ERR_OPN, av[ac - 1]));
    sfRenderWindow *window = init_window();
    map_t *map = init_map(setting);
    if (map == NULL)
        return (84);
    map->objects = launch;
    if (menu(window) == 1)
        return (0);
    launch_main_loop(window, map);
    return (EXIT_SUCCESS);
}
