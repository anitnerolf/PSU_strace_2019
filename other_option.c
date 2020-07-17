/*
** EPITECH PROJECT, 2020
** other
** File description:
** option
*/

#include "./include/my.h"

void	system_calls_loop(my_strace_t *s)
{
    waitpid(s->pid, &s->status, 0);
    while (signal_handler(s->status)) {
        if (ptrace(PTRACE_GETREGS, s->pid, NULL, &s->regs) == -1)
            perror("ptrace-PTRACE_GETREGS");
        s->return_value = ptrace(PTRACE_PEEKTEXT, s->pid, s->regs.rip, NULL);
        if (s->return_value == s->cd || s->return_value == s->f)
            print_system_calls(s->regs, s);
        if (ptrace(PTRACE_SINGLESTEP, s->pid, NULL, NULL) == -1)
            perror("ptrace-SINGLESTEP");
        waitpid(s->pid, &s->status, 0);
    }
}

void	other_option(my_strace_t *s, char **av)
{
    pid_t p;

    if (s->pid == 0) {
        if (ptrace(PTRACE_TRACEME, 0, 0, 0) == -1)
            perror("ptrace-TRACEME");
        if (execvp(av[1], av) == -1) {
            printf("strace: Can't stat '%s': ", av[1]);
            printf("No such file or directory\n");
            exit(1);
        }
        p = getpid();
        if (kill(p, SIGSTOP) == -1)
            perror("kill");
    } else {
        system_calls_loop(s);
    }
}
