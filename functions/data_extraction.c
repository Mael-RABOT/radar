/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-mael.rabot
** File description:
** data_extraction
*/

#include "../include/my.h"

char *extract_line_nbr(char *data, int i)
{
    char *res = malloc(20);
    my_strcpy(res, "");
    int count = 0;
    for (int j = i; data[j] != ' ' && data[j] != '\n' && data[j] != '\0'; j++)
        res[count++] = data[j];
    return (res);
}

char **line_extractor(char *data)
{
    char **res = malloc(sizeof(char) * 6);
    int i = 1;
    int count = 0;
    while (data[i] != '\0') {
        if (data[i] != ' ' && data[i - 1] == ' ') {
            res[count] = malloc(20);
            res[count++] = extract_line_nbr(data, i);
        }
        i++;
    }
    return (res);
}
