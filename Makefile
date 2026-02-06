NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I includes -I libft

SRCS = src/main.c \
				src/operation.c \
				src/operation2.c \
				src/operation3.c \
				src/parser.c \
				src/stack.c \
				src/utils.c \
				src/sort_small.c \
				src/sort_big.c

OBJS = $(SRCS:.c=.o)

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/ft_printf.a
LIBFT_DIR = $(PRINTF_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

all:$(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
