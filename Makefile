
NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

HEADER = push_swap.h
	
SRCS = args_validation.c nbr_validation.c stack_file.c indexing.c  main.c  moves.c 

OBJECTS = $(SRCS:.c=.o) 

OBJ_BONUS =$(SRCS_BONUS:.c=.o)
	
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJECTS) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)


re: fclean all