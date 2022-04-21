NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

FILES = push_swap.c parse.c sorting.c sort_big.c check.c moves.c utils.c utils2.c

OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) -o $(NAME) $(OBJS)

%.o:%.c push_swap.h
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJS)

normi: $(FILES)
	norminette $(FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, normi