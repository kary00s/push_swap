*This project has been created as part of the 42 curriculum by **kanahiz***.

## Description

Push_swap is a core algorithmic project, where i can create a C program that sorts a list of integers using two stacks (A and B) and a very limited set of allowed operations (push, swap, rotate, reverse rotate).


## Instructions

1. **Compilation:**

The push_swap project is compiled using the provided Makefile. The Makefile includes the following standard rules:

- make or make all: Compiles the project and creates the static library push_swap.a.
- make clean: Removes object files (.o).
- make fclean: Removes object files and the library  push_swap.a.
- make re: Performs a full recompile (fclean followed by all).


2. **Running the Project:**
- Once compiled into an executable, run your program as usual:
```
    - ./push_swap       | put the args separeted by ' ' | 
```
3. **allowed moves:**
- sa (swap a): Swap the first 2 elements at the top of the stack a. Does nothing if there is only one or none. 

- sb (swap b) : Swap the first 2 elements at the top of the stack b. Does nothing if there is only one or none. 

- ss : sa and sb at the same time. 

- pa (push a): Takes the first element on top of b and puts it on a. Does nothing if b is empty. 

- pb (push b): Takes the first element on top of a and puts it on b. Does nothing if a is empty. 

- ra (rotate a): Shifts all the elements of the stack a up by one position. The first element becomes the last. 

- rb (rotate b) : Shifts all the elements of the stack b one position upwards. The first element becomes the last one. 

- rr : ra and rb at the same time. 

- rra (reverse rotate a): Shifts all elements of the stack down one position. the stack a. The last element becomes the first. 

- rrb (reverse rotate b): Shifts all the elements of the stack b one position downwards. the stack b. The last element becomes the first. 

- rrr : rra and rrb at the same time.

## Resources

- [Radix sorting](https://www.geeksforgeeks.org/dsa/radix-sort/)
- [Stack implementation](https://www.geeksforgeeks.org/dsa/introduction-to-stack-data-structure-and-algorithm-tutorials/)
- [Time and Space Complexity](https://www.geeksforgeeks.org/dsa/time-complexity-and-space-complexity/)
- I created a summary for this project that includes all the necessary information and the knowledge I gained - [View the summary](https://www.tldraw.com/f/1R3ycDjL_3AGT1mKvcYuh?d=v-1804.-568.3500.3525.page)


## Result
- This project helped me strengthen my understanding of :

    - Better mastery of C fundamentals
Especially pointers, memory management, and string manipulation, and linked-lists.

    - Cleaner and more modular code
Using helper functions, structured logic, and readable code.

    - Attention to edge cases.

    - Stronger debugging skills
Using tools , gdb, or valgrind to find and fix errors.
