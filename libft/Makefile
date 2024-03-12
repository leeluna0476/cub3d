.DEFAULT_GOAL := all

CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCS=\
	 ft_abs.c \
	 ft_atoi.c \
	 ft_isalpha.c \
	 ft_memchr.c \
	 ft_memset.c \
	 ft_strncmp.c \
	 ft_toupper.c \
	 ft_bzero.c \
	 ft_isascii.c \
	 ft_memcmp.c \
	 ft_strlcat.c \
	 ft_strnstr.c \
	 ft_calloc.c \
	 ft_isdigit.c \
	 ft_memcpy.c \
	 ft_strchr.c \
	 ft_strlcpy.c \
	 ft_strrchr.c \
	 ft_isalnum.c \
	 ft_isprint.c \
	 ft_memmove.c \
	 ft_strdup.c \
	 ft_strlen.c \
	 ft_tolower.c \
	 ft_substr.c \
	 ft_strjoin.c \
	 ft_strjoin_div.c \
	 ft_strtrim.c \
	 ft_split.c \
	 ft_itoa.c \
	 ft_unitoa.c \
	 ft_strmapi.c \
	 ft_striteri.c \
	 ft_putchar_fd.c \
	 ft_putstr_fd.c \
	 ft_putendl_fd.c \
	 ft_putnbr_fd.c \
	 ft_lstnew.c \
	 ft_lstadd_front.c \
	 ft_lstsize.c \
	 ft_lstlast.c \
	 ft_lstadd_back.c \
	 ft_lstdelone.c \
	 ft_lstclear.c \
	 ft_lstiter.c \
	 ft_lstmap.c \
	 ft_quick_sort.c \
	 ft_print_char.c \
	 ft_print_str.c \
	 ft_print_int.c \
	 ft_print_unint.c \
	 ft_print_hexsm.c \
	 ft_print_hexlg.c \
	 ft_print_ptr.c \
	 ft_print_per.c \
	 ft_print_conversion.c \
	 ft_printf.c \
	 get_next_line.c
OBJS=$(SRCS:.c=.o)
NAME=libft.a

all :  $(NAME)

.o .c : $(SRCS)
	$(CC) $(CFLAGES) -c $^ -o $@

$(NAME) : $(OBJS)
	ar -rcs $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
