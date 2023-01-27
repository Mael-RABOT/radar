/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** file_checker
*/

#include "../include/my.h"

int check_line(char *line)
{
    for (int i = 0; i < my_strlen(line); i++) {
        switch (line[i]) {
            case 'A' : break;
            case 'T' : break;
            case ' ' : break;
            case '\n': break;
            case '0' : break;
            case '1' : break;
            case '2' : break;
            case '3' : break;
            case '4' : break;
            case '5' : break;
            case '6' : break;
            case '7' : break;
            case '8' : break;
            case '9' : break;
            default: return (EXIT_FAILURE);
        }
    }
    return (EXIT_SUCCESS);
}

int file_checker(char *path)
{
    FILE *stream = fopen(path, "r");
    if (!stream)
        return (EXIT_FAILURE);
    size_t len = 0;
    char *line = NULL;
    while (getline(&line, &len, stream) != -1)
        if (check_line(line) == EXIT_FAILURE)
            return (EXIT_FAILURE);
    fclose(stream);
    return (EXIT_SUCCESS);
}
