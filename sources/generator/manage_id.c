/*
** EPITECH PROJECT, 2019
** manage_id
** File description:
** manage_id
*/

#include "../../include/dante.h"

int choose_min(int first, int second)
{
    if (first < second && first > 0)
        return (first);
    return (second);
}

void replace_name(int *line, int new, int old, int cols)
{
    for (int i = 0; i < cols && line[i]; i++) {
        if (line[i] == old && new < old && new > 0)
            line[i] = new;
        else if (line[i] == new && old < new && old > 0)
            line[i] = old;
    }
}

void my_intcpy(int *second, int *line, int cols)
{
    for (int i = 0; i < cols && line[i]; i++)
        second[i] = line[i];
}

bool verify_if_online(int *prev, int *line, int i, int cols)
{
    int id = prev[i];

    for (i++; i < cols && prev[i]; i++)
        if (prev[i] == id)
            return (true);
    for (i = 0; i < cols && line[i]; i++)
        if (line[i] == id)
            return (true);
    return (false);
}
