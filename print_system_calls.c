/*
** EPITECH PROJECT, 2020
** print system calls
** File description:
** strace
*/

#include "./include/my.h"
#include "./include/system_calls.h"

void	print_return_value(struct user_regs_struct regs, my_strace_t *s)
{
    if (strcmp(system_calls[regs.rax].return_value, "void") == 0) {
        printf("= ?\n");
        printf("+++ exited with 0 +++\n");
    } else {
        ptrace(PTRACE_SINGLESTEP, s->pid, NULL, NULL);
        waitpid(s->pid, &s->status, 0);
        ptrace(PTRACE_GETREGS, s->pid, NULL, &s->regs);
        printf(" = 0x%llx\n", s->regs.rax);
    }
}

void print_system_calls2(struct user_regs_struct regs, my_strace_t *s)
{
    if (system_calls[regs.rax].nb_args == 5)
        printf("0x%llx, 0x%llx, 0x%llx, 0x%llx, 0x%llx", regs.rdi, \
    regs.rsi, regs.rdx, regs.rcx, regs.r8);
    if (system_calls[regs.rax].nb_args == 6)
        printf("0x%llx, 0x%llx, 0x%llx, 0x%llx, 0x%llx, 0x%llx", \
    regs.rdi, regs.rsi, regs.rdx, regs.rcx, regs.r8, regs.r9);
    printf(") ");
    print_return_value(regs, s);
}

void print_system_calls3(struct user_regs_struct regs)
{
    printf("%s(", system_calls[regs.rax].name);
    if (system_calls[regs.rax].nb_args == 1)
        printf("0x%llx", regs.rdi);
    if (system_calls[regs.rax].nb_args == 2)
        printf("0x%llx, 0x%llx", regs.rdi, regs.rsi);
}

void print_system_calls(struct user_regs_struct regs, my_strace_t *s)
{
    print_system_calls3(regs);
    if (system_calls[regs.rax].nb_args == 3)
        printf("0x%llx, 0x%llx, 0x%llx", regs.rdi, regs.rsi, regs.rdx);
    if (system_calls[regs.rax].nb_args == 4)
        printf("0x%llx, 0x%llx, 0x%llx, 0x%llx", regs.rdi, regs.rsi, \
    regs.rdx, regs.rcx);
    print_system_calls2(regs, s);
}
