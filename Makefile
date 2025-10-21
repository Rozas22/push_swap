NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

INCS		= -I include -I libft_
LIBFT_DIR	= libft_
LIBFT_A		= $(LIBFT_DIR)/libft.a

SRCS = src/main.c \
       src/read_args.c \
       src/stack.c \
       src/ops_swap.c \
       src/ops_push.c \
       src/ops_rotate.c \
       src/ops_rev_rotate.c \
       src/sort_small.c \
       src/sort_big.c \
       src/utils.c \
       src/free_stack.c \
	   src/errors.c

OBJS = $(SRCS:.c=.o)

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
