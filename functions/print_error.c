/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** print_error
*/

#include "../include/my.h"

char *make_error_message(char *path)
{
    char *message = malloc((my_strlen(path) + 55) * sizeof(char));
    my_strcpy(message, "cannot access '");
    my_strcat(message, path);
    my_strcat(message, "': No such file or directory\n");
    return (message);
}

int print_error(int error_type, char *path)
{
    switch (error_type) {
        case ERR_ARG :
            write(2, ERR_ARG_MSG, 34);
            break;
        case ERR_FILE :
            write(2, ERR_FILE_MSG, 39);
            break;
        case ERR_OPN :
            write(2, make_error_message(path), 45 + my_strlen(path));
            break;
    }
    return (84);
}
