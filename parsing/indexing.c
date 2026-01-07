#include"../push_swap.h"

int ft_fill_index(t_stack *head)
{
    t_stack *back;
    t_stack *front;
    int index;
    int largest ;

    largest = 0;
    back = head;
    while (back)
    {
        index = 0;
        front = head;
        while (front)
        {
            if (back->nbr > front->nbr)
                index++;
            if (index > largest)
                largest = index;
            front = front->next;
        }
        back->index = index;
        back = back->next;
    }
    return (largest);
}
int len_of_largest(int nbr)
{
    int cnt;

    cnt = 0;
    while (nbr > 0)
    {
        nbr = nbr / 2;
        cnt++;
    }
    return (cnt);
}