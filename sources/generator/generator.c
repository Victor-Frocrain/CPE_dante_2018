/*
** EPITECH PROJECT, 2019
** generator
** File description:
** generator
*/

#include "../../include/dante.h"

bool check_args(char *str)
{
    int i = 0;

    for (i = 0; str && str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return (false);
    if (i == 0)
        return (false);
    return (true);
}

bool parse_generator(int ac, char **av, generator_t *gen)
{
    gen->perfect = false;
    if (ac < 3)
        return (false);
    if (check_args(av[1]) == false || check_args(av[2]) == false)
        return (false);
    if (ac == 4 && my_strcmp(av[3], "perfect") == 0)
        gen->perfect = true;
    else if (ac >= 4)
        return (false);
    return (true);
}

int generator(int ac, char **av)
{
    generator_t *gen = malloc(sizeof(generator_t));

    if (gen == NULL)
        return (MY_EXIT_ERROR);
    if (parse_generator(ac, av, gen) == false ||
    init_generator(gen, av) == false) {
        free(gen);
        return (MY_EXIT_ERROR);
    }
    free(gen);
    return (MY_EXIT_SUCCESS);
}
