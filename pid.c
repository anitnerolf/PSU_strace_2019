/*
** EPITECH PROJECT, 2020
** strace
** File description:
** -p
*/

#include "./include/my.h"

int	get_pid(int ac, char **av)
{
    int pid;

    if (ac != 3)
        return (84);
    else {
        pid = atoi(av[2]);
        if (pid < 0)
            return (84);
        else
            return (pid);
    }
    return (0);
}
