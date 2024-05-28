CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRCS = algorithm.c algorithm_rest.c errors.c list.c push.c reverse_rotate.c swap.c utils.c \
		free.c main.c rotate.c

OBJS = $(SRCS:.c=.o)

LIB = libft.a
LIBRARY_DIR = Libft

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBRARY_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBRARY_DIR) -lft

clean:
	rm -f $(OBJS)
	make -C $(LIBRARY_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBRARY_DIR) fclean

re: fclean all