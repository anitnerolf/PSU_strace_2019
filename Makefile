##
## EPITECH PROJECT, 2020
## strace
## File description:
## makefile
##

SRC	=	main.c			\
		pid.c			\
		options.c		\
		other_option.c		\
		print_system_calls.c	\
		signal.c

OBJ	=	$(SRC:.c=.o)

NAME	=	strace

CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME) message

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) -I ./include

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f *~ $(NAME)

re:		fclean all

message:
		@echo "Successfully compiled!"
