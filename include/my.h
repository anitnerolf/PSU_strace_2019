/*
** EPITECH PROJECT, 2020
** asdf
** File description:
** sdfg
*/

#ifndef MY_H_
#define MY_H_
#include <fcntl.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/reg.h>

#include <sys/types.h>
#include <unistd.h>
#include <sys/user.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/user.h>
#include <sys/syscall.h>
#include <errno.h>
#include <sys/ucontext.h>

typedef struct my_strace
{
    pid_t pid;
    int status;
    struct user_regs_struct regs;
    unsigned short return_value;
    unsigned short cd;
    unsigned short f;
} my_strace_t;

void	s_option(void);
int	p_option(int ac, char **av);
int	get_pid(int ac, char **av);
int main(int ac, char **av);
void print_system_calls(struct user_regs_struct regs, my_strace_t *s);
my_strace_t	*my_strace(void);
void	other_option(my_strace_t *s, char **av);
void	system_calls_loop(my_strace_t *s);
int	signal_handler(int status);

#endif /* MY_H_ */
