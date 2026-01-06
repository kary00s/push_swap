
NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

HEADER = push_swap.h
	
SRCS = 	./sorting/stack_file.c 	./parsing/args_validation.c	 \
	   	./sorting/main.c       	./parsing/nbr_validation.c 	 \
	   	./sorting/moves.c		./parsing/indexing.c  		 \
		./sorting/sorting.c 	./sorting/free.c			 \

OBJECTS = $(SRCS:.c=.o) 

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME)
	
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@	
clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)


re: fclean all