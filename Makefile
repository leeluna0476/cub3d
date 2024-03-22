.DEFAULT_GOAL := all

CC=cc
CFLAGS=-Wall -Wextra -Werror -I $(HEADERS)
CLIB=-lmlx -L./srcs/mlx -framework OpenGL -framework Appkit
SRCS=\
	srcs/parse/check_map_validity.c \
	srcs/parse/dfs.c \
	srcs/parse/discriminate.c \
	srcs/parse/parse_map.c \
	srcs/parse/parse_map_utils.c \
	srcs/parse/parse_texture.c \
	srcs/parse/utils.c \
	srcs/exec/draw_utils.c \
	srcs/exec/draw_raycast.c \
	srcs/exec/draw_3d_cal.c \
	srcs/exec/draw_3D.c \
	srcs/exec/key_go_wasd.c \
	srcs/exec/key_press_handler.c \
	srcs/exec/mouse_handler.c \
	srcs/exec/mini_map.c \
	srcs/exec/init_info.c \
	srcs/exec/exec_cub.c \
	srcs/main.c
OBJS=$(SRCS:%.c=%.o)
HEADERS=./includes
NAME=cub3D
LIBFT= ./srcs/libft/libft.a
MLX= ./srcs/mlx/mlx.a

all :  $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) : $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(CLIB) $(LIBFT) $(OBJS) -o $@

$(LIBFT) :
	make -C ./srcs/libft

$(MLX) :
	make -C ./srcs/mlx

clean :
	make -C ./srcs/mlx clean
	make -C ./srcs/libft fclean
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
