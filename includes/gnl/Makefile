NAME = gnl.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3


SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar rc $(NAME) $^

all: $(NAME)

clean:
	@rm -f *o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
