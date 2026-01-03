#include<stdio.h>
#include"push_swap.h"
#include "push_swap.h"

void ft_fill_index(t_stack *head)
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

}
