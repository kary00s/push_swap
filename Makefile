
NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

HEADER = push_swap.h
	
SRCS = ./sorting/stack_file.c ./parsing/args_validation.c ./parsing/nbr_validation.c  ./parsing/indexing.c  ./sorting/main.c  ./sorting/moves.c ./sorting/sorting.c ./sorting/free.c

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