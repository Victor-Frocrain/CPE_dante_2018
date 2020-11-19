/*
** EPITECH PROJECT, 2019
** fill_lines
** File description:
** fill_lines
*/

#include "../../include/dante.h"

void copy_line(int *second, int *line, int cols)
{
    for (int i = 0; i < cols; i++)
        line[i] = second[i];
}

void fill_line_other(int *line, int cols, int i)
{
    if (i > 0 && line[i - 1] > 0 && (i == cols - 1 || line[i + 1] < 0))
        line[i] = line[i - 1];
    else if (line[i + 1] && line[i + 1] > 0 && (i == 0 || line[i - 1] < 0))
        line[i] = line[i + 1];
}

void fill_line(int *line, int cols)
{
    static int id = 1;

    for (int i = 0; i < cols; i += 2) {
        if (line[i] < 0 && (i == cols - 1 || i == 0 || line[i - 1] < 0 ||
        line[i + 1] < 0 || (line[i - 1] != line[i + 1]))) {
            line[i] = id;
            id++;
        }
        if (i > 0 && line[i - 1] > 0 && line[i + 1] &&
        line[i + 1] > 0 && line[i - 1] != line[i + 1]) {
            line[i] = choose_min(line[i - 1], line[i + 1]);
            replace_name(line, line[i - 1], line[i + 1], cols);
        }
        else
            fill_line_other(line, cols, i);
    }
}

void fill_last_other(int *line, int cols, int *prev, int i)
{
    if (i < cols - 1 && ((prev[i] == prev[i - 1]) || (prev[i] == prev[i + 1])))
        line[i] = -1;
    else if (i == cols - 1)
        line[i] = 1;
}

void fill_last_line(int *line, char *result, generator_t *gen, int *prev)
{
    int cols = gen->cols;

    for (int i = 1; i < cols && line[i]; i += 2) {
        if (i < cols - 1 && line[i - 1] != line[i + 1] && (line[i - 1] > 0 ||
        line[i + 1] > 0)) {
            line[i] = choose_min(line[i - 1], line[i + 1]);
            replace_name(line, line[i - 1], line[i + 1], cols);
        }
        else
            fill_last_other(line, cols, prev, i);
    }
    if (gen->perfect == false)
        make_imperfect(line, cols);
    display_line(line, result, cols, true);
}
