/*
** EPITECH PROJECT, 2019
** compute_result
** File description:
** compute_result
*/

#include "../../include/dante.h"

int back_corner(solver_t *solve, int pos)
{
    int line = solve->len;

    solve->map[pos] = 'x';
    if (solve->map[pos + line] && solve->map[pos + line] == '-')
        return (pos + line);
    if (solve->map[pos + 1] && solve->map[pos + 1] == '|')
        return (pos + 1);
    if (solve->map[pos - line] && solve->map[pos - line] == '-')
        return (pos - line);
    if (solve->map[pos - 1] && solve->map[pos - 1] == '|')
        return (pos - 1);
    return (-1);
}

int go_back(solver_t *solve, int pos)
{
    int line = solve->len;

    solve->map[pos] = 'x';
    if (solve->map[pos + line] && solve->map[pos + line] == '|')
        return (pos + line);
    if (solve->map[pos + 1] && solve->map[pos + 1] == '-')
        return (pos + 1);
    if (solve->map[pos - line] && solve->map[pos - line] == '|')
        return (pos - line);
    if (solve->map[pos - 1] && solve->map[pos - 1] == '-')
        return (pos - 1);
    return (back_corner(solve, pos));
}

int check_rooms(solver_t *solve, int pos)
{
    int line = solve->len;

    if (solve->map[pos + line] && solve->map[pos + line] == '*') {
        solve->map[pos + line] = '|';
        return (pos + line);
    }
    if (solve->map[pos + 1] && solve->map[pos + 1] == '*') {
        solve->map[pos + 1] = '-';
        return (pos + 1);
    }
    if (solve->map[pos - line] && solve->map[pos - line] == '*') {
        solve->map[pos - line] = '|';
        return (pos - line);
    }
    if (solve->map[pos - 1] && solve->map[pos - 1] == '*') {
        solve->map[pos - 1] = '-';
        return (pos - 1);
    }
    return (-1);
}

bool compute_result(solver_t *solve)
{
    int pos = 0;
    bool can_move = true;
    int test = 0;

    if (solve->map && solve->map[pos] && solve->map[pos] == '*')
        solve->map[pos] = 'o';
    else
        return (false);
    for (; pos != solve->total - 1 && can_move;) {
        if ((test = check_rooms(solve, pos)) >= 0)
            pos = test;
        else if ((pos = go_back(solve, pos)) < 0)
            can_move = false;
    }
    return (can_move);
}
