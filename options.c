/*
** EPITECH PROJECT, 2020
** options
** File description:
** strace
*/

#include "./include/my.h"

void	s_option(void)
{
    printf("-s\n");
}

int	p_option(int ac, char **av)
{
    int pid = get_pid(ac, av);
    if (pid == 84)
        return (84);
    else
        return (pid);
}
