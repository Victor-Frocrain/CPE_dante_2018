/*
** EPITECH PROJECT, 2019
** init_generator
** File description:
** init_generator
*/

#include "../../include/dante.h"

bool init_generator(generator_t *gen, char **av)
{
    gen->cols = my_getnbr(av[1]);
    gen->lines = my_getnbr(av[2]);
    return (compute_lines(gen));
}
