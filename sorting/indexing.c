#include<stdio.h>
#include"push_swap.h"

int  ft_fill_index(t_stack *head)
{
    t_stack *current;
    t_stack *compare;
    int index;
    int largest = 0;
    current = head;
    while (current)
    {
        index = 0;
        compare = head;
        while (compare)
        {
            if (current->nbr > compare->nbr)
                index++;
            if (index > largest)
                largest = index;
            compare = compare->next;
        }
        current->index = index;
        current = current->next;
    }
    return (largest);
}
int len_of_largest(int nbr)
{
    int cnt = 0;
    while (nbr > 0)
    {
        nbr = nbr / 2;
        cnt++;
    }
    return (cnt);
}
void ft_shifting(t_stack *stack)
{
    int len_largest=ft_fill_index(stack);
    len_largest = len_of_largest(len_largest);
    while (stack)
    {
        while (len_largest > 0)
        {
            stack->nbr >> len_largest--;
            printf("%d\n",stack->nbr >> len_largest);
        }
        stack = stack->next;
    }
    
}