#include "push_swap.h"

// Function 1: Parse arguments and fill stack_A
static void ft_fill_stack(int ac, char **av, t_stack **stack_A)
{
    char    **tmp = NULL;
    int     i = 1;
    int     j;
    int     nbr;
    t_stack *tmp_stack;

    while (i < ac)
    {
        tmp = ft_split(av[i]);
        if (!tmp)
        {
            perror("split failure");
            exit(EXIT_FAILURE);
        }           
        j = 0;
        while (tmp[j])
        {
            ft_check_nbr(*stack_A, tmp[j]);
            nbr = ft_atoi(tmp[j]);
            tmp_stack = ft_lstnew(nbr);
            ft_lstadd_back(stack_A, tmp_stack);
            j++;
        }
        ft_free_all(tmp, j);
        i++;
    }
}

// Function 2: Assign indices to the stack (fill_index + calculate largest bit length)
static int prepare_indices(t_stack *stack_A)
{
    int largest = ft_fill_index(stack_A);
    largest = len_of_largest(largest);
    return (largest);
}

// Function 3: Perform the radix sort using the calculated bit length
static void radix_sort(t_stack **stack_A, t_stack **stack_B, int largest)
{
    int     i = 0;
    int     j;
    int     x;
    int     size = stack_size(*stack_A);
    t_stack *tmp_stack;
    int     cnt;

    while (i < largest)
    {
        j = 0;
        tmp_stack = *stack_B;
        cnt = 0;
        while (j < size - 1)
        {
            x = (*stack_A)->index >> i & 1;
            if (x == 1)
                ft_rotate(stack_A);
            if (x == 0)
                ft_push_b(stack_A, stack_B);
            j++;
        }
        while (*stack_B)
            ft_push_a(stack_A, stack_B);
        i++;
    }
}

// Optional: Print both stacks (kept separate for clarity, but you can merge if you want exactly 3)
static void print_stacks(t_stack *stack_A, t_stack *stack_B)
{
    while (stack_A)
    {
        printf("%d\n", stack_A->nbr);
        stack_A = stack_A->next;
    }
    while (stack_B)
    {
        printf("%d\n", stack_B->nbr);
        stack_B = stack_B->next;
    }
}

int main(int ac, char **av)
{
    t_stack *stack_A = NULL;
    t_stack *stack_B = NULL;
    int     largest;

    if (ac < 2)
    {
        perror("nbr of args failure");
        exit(EXIT_FAILURE);
    }

    // 1. Parse input and build stack A
    parse_and_fill_stack(ac, av, &stack_A);

    // 2. Fill indices and get the number of bits needed
    largest = prepare_indices(stack_A);

    // 3. Perform radix sort
    radix_sort(&stack_A, &stack_B, largest);

    // Print result (stack_B should be empty at the end)
    print_stacks(stack_A, stack_B);

    return (0);
}