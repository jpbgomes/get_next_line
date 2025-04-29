NAME = get_next_line.a

BUFFER_SIZE ?= 42
BUFFER_DEF = -D BUFFER_SIZE=$(BUFFER_SIZE)
FLAGS = -Wall -Wextra -Werror $(BUFFER_DEF)

SRCFILES = get_next_line.c get_next_line_utils.c
OBJFILES = $(SRCFILES:.c=.o)

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJFILES)
	ar rcs $(NAME) $(OBJFILES)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES) a.out

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	cc main.c $(SRCFILES) $(FLAGS) -o a.out && ./a.out