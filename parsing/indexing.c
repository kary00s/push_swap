#include"../push_swap.h"

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