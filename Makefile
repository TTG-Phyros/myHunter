##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Build the whole project
##

NAME	=		my_hunter

CFLAGS	= 		-W -Wall -Wextra

SRC		=		./src/main.c					\
				./src/game.c					\
				./src/display_functions.c		\
				./src/mobs.c					\
				./src/settings.c				\
				./src/scoreboard.c				\
				./src/policeman.c				\
				./src/flag_h.c					\
				./src/mob_death.c				\
				./src/transformations.c 		\

OBJ		=		$(SRC:.c=.o)

CSFML	=		-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all:	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(CFLAGS) $(CSFML)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
