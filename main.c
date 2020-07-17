/*
** EPITECH PROJECT, 2020
** sdg
** File description:
** sdfg
*/

#include "./include/my.h"

my_strace_t	*my_strace(void)
{
    my_strace_t *mystrace = malloc(sizeof(my_strace_t));
    mystrace->pid = fork();
    mystrace->status = 0;
    mystrace->return_value = 0;
    mystrace->f = 0x50f;
    mystrace->cd = 0x080CD;
    return (mystrace);
}

int	main(int ac, char **av)
{
    if (ac == 1) {
        printf("strace: must have PROG [ARGS] or -p PID\n");
        printf("Try 'strace -h' for more information.\n");
        return (84);
    } else if (ac == 2 && av[1][0] == '-' && av[1][1] == '-' && \
    av[1][2] == 'h' && av[1][3] == 'e' && av[1][4] == 'l' && \
    av[1][5] == 'p' && !av[1][6]) {
        printf("USAGE: %s [-s] [-p <pid>|<command>]\n", av[0]);
    } else if (ac == 3 && av[1][0] == '-' && av[1][1] == 's' && !av[1][2]) {
        s_option();
    } else if (ac == 3 && av[1][0] == '-' && av[1][1] == 'p' && !av[1][2]) {
        return (p_option(ac, av));
    } else {
        my_strace_t *s = my_strace();
        other_option(s, av);
        return (0);
    }
}
