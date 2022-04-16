NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
LIBFT = libft.a

FILES = push_swap.c parse.c sorting.c sort_big.c check.c moves.c

OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	$(CC) -o $(NAME) $(OBJS) -L. libft.a

$(LIBFT): 
	cd libft && make && mv libft.a ../

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJS)
	cd libft && make clean

normi: $(FILES)
	norminette $(FILES)

fclean: clean
	$(RM) $(NAME) libft.a

re: fclean all

.PHONY: all, clean, fclean, re, normi