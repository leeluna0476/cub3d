CC=cc
CFLAGS=-Wall -Wextra -Werror -I $(HEADERS)
CLIB=-lmlx -L./srcs/mlx -framework OpenGL -framework Appkit
MAN_SRCS=\
	srcs/mandatory/parse/check_map_validity.c \
	srcs/mandatory/parse/dfs.c \
	srcs/mandatory/parse/discriminate.c \
	srcs/mandatory/parse/parse_map.c \
	srcs/mandatory/parse/parse_map_utils.c \
	srcs/mandatory/parse/parse_texture.c \
	srcs/mandatory/parse/utils.c \
	srcs/mandatory/exec/draw_utils.c \
	srcs/mandatory/exec/draw_raycast.c \
	srcs/mandatory/exec/draw_3d_cal.c \
	srcs/mandatory/exec/draw_3D.c \
	srcs/mandatory/exec/key_go_wasd.c \
	srcs/mandatory/exec/key_press_handler.c \
	srcs/mandatory/exec/mouse_handler.c \
	srcs/mandatory/exec/mini_map.c \
	srcs/mandatory/exec/init_info.c \
	srcs/mandatory/exec/exec_cub.c \
	srcs/mandatory/main.c
MAN_OBJS=$(MAN_SRCS:%.c=%.o)
MAN_HEADERS=./includes/mandatory



BONUS_SRCS=\
	srcs/bonus/parse/check_map_validity_bonus.c \
	srcs/bonus/parse/dfs_bonus.c \
	srcs/bonus/parse/discriminate_bonus.c \
	srcs/bonus/parse/parse_map_bonus.c \
	srcs/bonus/parse/parse_map_utils_bonus.c \
	srcs/bonus/parse/parse_texture_bonus.c \
	srcs/bonus/parse/utils_bonus.c \
	srcs/bonus/exec/draw_utils_bonus.c \
	srcs/bonus/exec/draw_raycast_bonus.c \
	srcs/bonus/exec/draw_3d_cal_bonus.c \
	srcs/bonus/exec/draw_3D_bonus.c \
	srcs/bonus/exec/key_go_wasd_bonus.c \
	srcs/bonus/exec/key_press_handler_bonus.c \
	srcs/bonus/exec/mouse_handler_bonus.c \
	srcs/bonus/exec/mini_map_bonus.c \
	srcs/bonus/exec/init_info_bonus.c \
	srcs/bonus/exec/exec_cub_bonus.c \
	srcs/bonus/main_bonus.c
BONUS_OBJS=$(BONUS_SRCS:%.c=%.o)
BONUS_HEADERS=./includes/bonus


ifeq ($(MAKECMDGOALS),bonus)
	HEADERS=$(BONUS_HEADERS)
	OBJS=$(BONUS_OBJS)
else
	HEADERS=$(MAN_HEADERS)
	OBJS=$(MAN_OBJS)
endif


NAME=cub3D
LIBFT= ./srcs/libft/libft.a

all :  $(NAME)

bonus: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(CLIB) $(LIBFT) $(OBJS) -o $@

$(LIBFT) :
	make -C ./srcs/libft

clean :
	make -C ./srcs/libft fclean
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re bonus
