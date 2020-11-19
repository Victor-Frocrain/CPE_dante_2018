/*
** EPITECH PROJECT, 2019
** manage_lines
** File description:
** manage_lines
*/

#include "../../include/generator.h"

void manage_lines(generator_t *gen, int *line, int *second, char *result)
{
    for (int i = 0; i < gen->lines; i++) {
        copy_line(second, line, gen->cols);
        fill_line(line, gen->cols);
        if (i == gen->lines - 1) {
            fill_last_line(line, result, gen, second);
            return;
        }
        extrude_cols(line, gen->cols, i, gen->perfect);
        display_line(line, result, gen->cols, false);
        i++;
        my_intcpy(second, line, gen->cols);
        if (i == gen->lines - 1) {
            fill_last_line(second, result, gen, line);
            return;
        }
        extrude_lines(line, second, gen->cols);
        display_line(second, result, gen->cols, false);
    }
}

bool compute_lines(generator_t *gen)
{
    int *line = malloc(sizeof(int) * (gen->cols));
    int *second = malloc(sizeof(int) * (gen->cols));
    char *result = malloc(sizeof(char) * (gen->cols + 2));

    srand(time(NULL));
    if (line == NULL || second == NULL || result == NULL)
        return (false);
    for (int i = 0; i < gen->cols; i++)
        second[i] = -1;
    manage_lines(gen, line, second, result);
    free(line);
    free(second);
    free(result);
    return (true);
}

