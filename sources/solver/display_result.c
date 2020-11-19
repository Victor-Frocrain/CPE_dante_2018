/*
** EPITECH PROJECT, 2019
** display_map
** File description:
** display_map
*/

#include "../../include/dante.h"

void replace_chars(solver_t *solve)
{
    for (int i = 0; solve->map && solve->map[i]; i++) {
        if (solve->map[i] == 'x')
            solve->map[i] = '*';
        else if (solve->map[i] == '|' || solve->map[i] == '-')
            solve->map[i] = 'o';
    }
}

void display_result(solver_t *solve)
{
    replace_chars(solve);
    write(1, solve->map, solve->total);
}
