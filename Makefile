##
## Makefile for  in /home/yohan/Graphical_Prog/Bootstrap_Raytracer/raytracer1
## 
## Made by Yohan
## Login   <yohan.le-quere@epitech.eu>
## 
## Started on  Thu Mar  9 18:01:11 2017 Yohan
## Last update Sun Mar 19 23:34:55 2017 Yohan
##

SRC	=	src/graph.c			\
		src/calc_dir_vector.c		\
		src/draw_sphere.c		\
		src/cylinder.c		\
		src/plane.c			\
		src/sphere.c			\
		src/my_put_pixel.c		\
		src/rotate.c			\
		src/translate.c		\
		src/parser.c			\
		src/my_str_to_wordtab.c	\
		src/my_strcmp.c		\
		src/get_next_line.c		\
		src/my_get_nbr.c		\
		src/check_init.c		\
		src/my_color.c		\
		src/cone.c			\
		src/make_shad.c		\
		src/my_light.c		\
		src/free_tab.c		\
		src/light.c

OBJ	=       $(SRC:.c=.o)

NAME	=       raytracer1

CC	=       gcc

CPPFLAGS=	-I./include

CFLAGS  =      -Wall -Wextra -g3 -pedantic 

LDFLAGS	=	 -lc_graph_prog -lm

all: 		$(NAME)

$(NAME):        $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re
