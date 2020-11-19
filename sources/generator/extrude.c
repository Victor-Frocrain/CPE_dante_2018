/*
** EPITECH PROJECT, 2019
** extrude
** File description:
** extrude
*/

#include "../../include/generator.h"

bool make_imperfect(int *line, int cols)
{
    bool wall = false;

    for (int i = 1; i < cols - 1; i++)
        if (line[i] < 0) {
            wall = true;
            line[i] = line[i - 1];
        }
    return (wall);
}

void extrude_cols(int *line, int cols, int nb_line, bool perfect)
{
    int cutter = 0;
    static bool loop = false;

    for (int i = 1; i < cols && line[i]; i += 2) {
        cutter = rand() % 2;
        if (cutter == 1 && i < cols - 1 && line[i + 1] &&
        line[i - 1] != line[i + 1] && line[i - 1] > 0 && line[i + 1] > 0) {
            line[i] = choose_min(line[i - 1], line[i + 1]);
            replace_name(line, line[i - 1], line[i + 1], cols);
        }
    }
    if (nb_line > 0 && perfect == false && loop == false)
        loop = make_imperfect(line, cols);
}

void extrude_lines(int *prev, int *line, int cols)
{
    int cutter = 0;

    for (int i = 0; i < cols; i++)
        line[i] = -1;
    for (int i = 0; i < cols && line[i]; i++) {
        cutter = rand() % 2;
        if (cutter == 1 && (i == 0 || (line[i - 1] &&
        line[i - 1] != prev[i]))) {
            line[i] = prev[i];
            i++;
        }
        else if (verify_if_online(prev, line, i, cols) == false) {
            line[i] = prev[i];
            i++;
        }
    }
}
