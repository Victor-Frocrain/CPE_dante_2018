/*
** EPITECH PROJECT, 2019
** generator
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include "dante.h"

typedef struct generator_s {
    bool perfect;
    int lines;
    int cols;
} generator_t;

int generator(int ac, char **av);
bool init_generator(generator_t *gen, char **av);
int choose_min(int first, int second);
void copy_line(int *second, int *line, int cols);
void fill_line(int *line, int cols);
void fill_last_line(int *line, char *result, generator_t *gen, int *prev);
void extrude_cols(int *line, int cols, int nb_line, bool perfect);
void extrude_lines(int *prev, int *line, int cols);
void replace_name(int *line, int new, int old, int cols);
void my_intcpy(int *second, int *line, int cols);
bool verify_if_online(int *prev, int *line, int i, int cols);
void display_line(int *line, char *result, int cols, bool end);
bool compute_lines(generator_t *gen);
bool make_imperfect(int *line, int cols);

#endif /* GENERATOR_H_ */
