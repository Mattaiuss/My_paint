##
## EPITECH PROJECT, 2024
## Compile mylib
## File description:
## Makefile that compiles the lib
##

NAME	=	my_paint

SRCS	=	$(wildcard *.c)

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lm -g3

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(CSFML)

clean:
	rm -f $(OBJS)
	rm -f *~

fclean:	clean
	rm -f $(NAME_TEST)
	rm -f $(NAME)

re:	fclean all
