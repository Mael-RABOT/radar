##
## EPITECH PROJECT, 2022
## B-MUL-100-LYN-1-1-myradar-mael.rabot
## File description:
## Makefile
##

SRC	=	main.c	\
		main_loop.c	\
		rendering.c	\
		collision.c	\
		landing.c	\
		take_off.c	\
		animation.c	\
		movement.c	\
		init_map.c	\
		tower_in_range.c	\
		menu.c	\
		move_plane_list.c	\
		functions/launch_control_generation.c	\
		functions/data_extraction.c	\
		functions/print_man.c	\
		functions/sprite_generation.c	\
		functions/add_data.c	\
		functions/event.c	\
		functions/obj_position.c	\
		functions/field_completion.c	\
		functions/rotation.c	\
		functions/make_timer.c	\
		functions/outline_position.c	\
		functions/render_grid.c	\
		functions/init_map_make_functions.c	\
		functions/make_background.c	\
		functions/init_ui_text.c	\
		functions/ui_text_update.c	\
		functions/plane_list_swap.c	\
		functions/file_checker.c	\
		functions/print_error.c	\
		functions/garbage.c	\

NAME	=	my_radar

LIBS = -L./lib/ -lmy

CSFML = -lcsfml-graphics -lcsfml-system -lm

FLAGS = -Wall

MSG_START = "COMPILING ..."

MSG_END = "COMPILATION ENDED"

MSG_EXE = "EXECUTING ..."

$(NAME):	$(SRC) cpl
	gcc -o $(NAME) $(SRC) $(LIBS) $(CSFML)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *.out

cpl:
	cd lib && make && cd ..

re: cpl fclean all

run:
	echo $(MSG_START)
	gcc -o $(NAME) $(SRC) $(LIBS) $(CSFML)
	echo $(MSG_END) && echo $(MSG_EXE)
	./$(NAME) $(ARGS)
