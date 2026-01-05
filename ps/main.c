#include "push_swap.h"
///////////////////////////////////
static void ft_fill_stack(int ac, char **av, t_stack **stack_A,t_stack **stack_B)
{
    char    **tmp = NULL;
    int     i = 1;
    int     j;
    int     nbr;
    while (i < ac)
    {
        tmp = ft_split(av[i]);
        if (!tmp)
            return(ft_free_stack(stack_A,stack_B),exit_failure());
        
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
// static void print_stacks(t_stack *stack_A, t_stack *stack_B)
// {
//     while (stack_A)
//     {
//         printf("%d\n", stack_A->nbr);
//         stack_A = stack_A->next;
//     }
//     while (stack_B)
//     {
//         printf("%d\n", stack_B->nbr);
//         stack_B = stack_B->next;
//     }
// }
int main(int ac, char **av)
{
    t_stack *stack_A = NULL;
    t_stack *stack_B = NULL;
    int     largest;
    int size;
    if (ac < 2)
		return (ft_free_stack(&stack_A,&stack_B) , exit_failure(),0);

    ft_fill_stack(ac, av, &stack_A,&stack_B);
    largest = check_latgest(stack_A);
    size =stack_size(stack_A); 
    if( size == 2)
        sort_two(&stack_A);
    else if( size == 3)
        sort_three(&stack_A);
    else if( size == 5 || size == 4)
        sort_five(&stack_A,&stack_B, size);
    else
        radix_sort(&stack_A, &stack_B, largest);

    // print_stacks(stack_A, stack_B);
    ft_free_stack(&stack_A,&stack_B);
    return (0);
}
