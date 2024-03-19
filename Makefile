.DEFAULT_GOAL := all

CC=cc
CFLAGS=-Wall -Wextra -Werror -g
CLIB=-lmlx -framework OpenGL -framework Appkit
SRCS=\
	parse/dfs.c \
	parse/discriminate.c \
	parse/parse_map_utils.c \
	parse/check_map_validity.c \
	parse/parse_map.c \
	parse/parse_texture.c \
	parse/utils.c \
	2D/draw_2d_ray.c \
	2D/draw_2d.c \
	2D/draw_line.c \
	2D/draw_utils_2d.c \
	draw_utils.c \
	draw_raycast.c \
	draw_3d_cal.c \
	draw_3d.c \
	key_go_wasd.c \
	key_press_handler.c \
	init_info.c \
	exec_cub.c \
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
