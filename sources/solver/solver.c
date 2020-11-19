/*
** EPITECH PROJECT, 2019
** solver
** File description:
** solver
*/

#include "../../include/dante.h"

solver_t *init_solver(void)
{
    solver_t *solve = malloc(sizeof(solver_t));

    if (solve == NULL)
        return (NULL);
    solve->len = 0;
    solve->map = NULL;
    solve->move = 0;
    solve->total = 0;
    return (solve);
}

bool check_map(solver_t *solve)
{
    int i = 0;

    for (; solve->map && solve->map[solve->len] &&
    solve->map[solve->len] != '\n'; solve->len++);
    solve->len++;
    for (int lines = -1; solve->map && solve->map[i]; i++) {
        if (solve->map[i] != '*' && solve->map[i] != 'X' &&
            solve->map[i] != '\n')
            return (false);
        if (solve->map[i] == '\n' && (lines + solve->len != i ||
            (solve->map[i + 1] && solve->map[i + 1] == '\n')))
            return (false);
        else if (solve->map[i] == '\n')
            lines += solve->len;
    }
    if (i == 0)
        return (false);
    if (solve->map[i - solve->len] && solve->map[i - solve->len] != '\n')
        return (false);
    return (true);
}

bool parse_map(int ac, char **av, solver_t *solve)
{
    int fd = 0;
    struct stat info;

    if (ac != 2)
        return (false);
    fd = open(av[1], O_RDONLY);
    if (fd < 0 || stat(av[1], &info) < 0)
        return (false);
    if ((solve->map = malloc(sizeof(char) * (info.st_size + 1))) == NULL) {
        close(fd);
        return (false);
    }
    read(fd, solve->map, info.st_size);
    solve->map[info.st_size] = 0;
    solve->total = info.st_size;
    close(fd);
    return (check_map(solve));
}

int solver(int ac, char **av)
{
    solver_t *solve = init_solver();

    if (solve == NULL)
        return (MY_EXIT_ERROR);
    if (parse_map(ac, av, solve) == false) {
        free_all(solve);
        return (MY_EXIT_ERROR);
    }
    if (compute_result(solve))
        display_result(solve);
    else
        write(1, "no solution found", 17);
    free_all(solve);
    return (MY_EXIT_SUCCESS);
}
