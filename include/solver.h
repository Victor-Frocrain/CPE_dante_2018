/*
** EPITECH PROJECT, 2019
** solver
** File description:
** solver
*/

#ifndef SOLVER_H_
#define SOLVER_H_

#include "dante.h"

typedef struct solver_s {
    char *map;
    int len;
    int move;
    int total;
} solver_t;

int solver(int ac, char **av);
void free_all(solver_t *solve);
void display_result(solver_t *solve);
bool compute_result(solver_t *solve);

#endif /* SOLVER_H_ */
