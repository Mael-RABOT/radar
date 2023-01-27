/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** print_man
*/

#include "../include/my.h"

int print_man(void)
{
    int fd = open("README.txt", O_RDONLY);
    if (fd == -1)
        return (84);
    char buff[MAN_BUFFER_SIZE + 1];
    read(fd, buff, MAN_BUFFER_SIZE);
    my_printf("%s", buff);
    return (0);
}
