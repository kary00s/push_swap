#include "push_swap.h"
///////////////////////////////////
static void ft_fill_stack(int ac, char **av, t_stack **stack_A)
{
    char    **tmp = NULL;
    int     i = 1;
    int     j;
    int     nbr;
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
            ft_lstadd_back(stack_A, ft_lstnew(nbr));
            j++;
        }
        ft_free_all(tmp, j);
        i++;
    }
}
static int check_latgest(t_stack *stack_A)
{
    int largest = ft_fill_index(stack_A);
    largest = len_of_largest(largest);
    return (largest);
}
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
        while (j < size)
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

    ft_fill_stack(ac, av, &stack_A);

    largest = check_latgest(stack_A);

    radix_sort(&stack_A, &stack_B, largest);

    print_stacks(stack_A, stack_B);

    return (0);
}