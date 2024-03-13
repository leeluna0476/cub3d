.DEFAULT_GOAL := all

CC=cc
CFLAGS=-Wall -Wextra -Werror -g
CLIB=-lmlx -framework OpenGL -framework Appkit
SRCS=\
	parse/discriminate.c \
	parse/parse_map_utils.c \
	parse/check_map_effect.c \
	parse/parse_map.c \
	parse/parse_texture.c \
	parse/utils.c \
	draw_line.c \
	draw_utils1.c \
	draw_utils2.c \
	key_press_handler.c \
	exec_cub.c \
	draw_2D.c \
	main.c
OBJS=$(SRCS:%.c=%.o)
NAME=cub3D
LIBFT= ./libft/libft.a

all :  $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(CLIB) $(LIBFT) $(OBJS) -o $@

$(LIBFT) :
	make -C ./libft

clean :
	make -C ./libft fclean
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
