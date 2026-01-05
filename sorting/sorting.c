#include "../push_swap.h"
void radix_sort(t_stack **stack_A, t_stack **stack_B, int largest)
{
    int     i = 0;
    int     j;
    int     x;
    int     size = stack_size(*stack_A);

    while (i < largest)
    {
        j = 0;
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
void sort_two(t_stack **stack)
{
    t_stack *second = (*stack)->next;
    if (second->index < (*stack)->index)
        ft_swap(stack);
    else
        return;    
}
void sort_three(t_stack **stack)
{
    t_stack *second = (*stack)->next;
    t_stack *third = ((*stack)->next)->next;
   
    if ((second->index < (*stack)->index) && ((*stack)->index < third->index)) // 2 1 3
        return (ft_swap(stack));

    else if ( (third->index < (*stack)->index) && ((*stack)->index < second->index)) // 2 3 1
        return (ft_rotate_reverse(stack));

    else if ( (third->index < second->index) && (second->index < (*stack)->index)) // 3 2 1
        return (ft_swap(stack),ft_rotate_reverse(stack));
    
    else if (((*stack)->index < third->index) && ( third->index < second->index)) //  1 3 2
        return (ft_rotate_reverse(stack),ft_swap(stack));

    else if ((second->index < third->index) && (third->index < (*stack)->index )) //  3 1 2
        return (ft_rotate_reverse(stack),ft_rotate_reverse(stack));

    else if (((*stack)->index < second->index) && (second->index < third->index)) //1 2 3
         return ;
}
void sort_five(t_stack **stack_A,t_stack **stack_B,int size)
{
    while ((*stack_A)->index != 0)
        ft_rotate(stack_A);
    ft_push_b(stack_A,stack_B);
    if(size == 5)
    {
        while ((*stack_A)->index != 1)
            ft_rotate(stack_A);
        ft_push_b(stack_A,stack_B);
    }
    sort_three(stack_A);
    ft_push_a(stack_A,stack_B);
    if (size == 5)
        ft_push_a(stack_A,stack_B);

}