/*
** EPITECH PROJECT, 2019
** free_all
** File description:
** free_all
*/

#include "../../include/dante.h"

void free_all(solver_t *solver)
{
    if (solver && solver->map)
        free(solver->map);
    if (solver)
        free(solver);
}
