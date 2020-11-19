/*
** EPITECH PROJECT, 2019
** display_line
** File description:
** dispaly_line
*/

#include "../../include/dante.h"

void display_line(int *line, char *result, int cols, bool end)
{
    int i = 0;

    for (; i < cols && line[i]; i++) {
        if (line[i] > 0)
            result[i] = '*';
        else
            result[i] = 'X';
    }
    if (end == false)
        result[i] = '\n';
    else
        result[i] = 0;
    result[i + 1] = 0;
    write(1, result, cols + 1);
}
