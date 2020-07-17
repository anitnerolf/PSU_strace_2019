/*
** EPITECH PROJECT, 2020
** signal
** File description:
** strace
*/

#include "./include/my.h"

int	signal_handler(int status)
{
    int i = 0;
    if ((WSTOPSIG(status) == SIGTRAP
    || WSTOPSIG(status) == SIGSTOP)
    && WIFSTOPPED(status))
        i = 1;
    else
        i = 0;
    return (i);
}
