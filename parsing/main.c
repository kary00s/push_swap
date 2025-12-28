#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack = NULL;
    t_stack *tmp_stack = NULL;

    char    **tmp=NULL;
    int     i;
    int     j;
    int nbr;
    if (ac < 2)
    {
        perror("nbr of args failure");
        exit(EXIT_FAILURE);
    }
    
    i = 1;
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
            ft_check_nbr(stack,tmp[j]);
            nbr = ft_atoi(tmp[j]);
            tmp_stack = ft_lstnew(nbr);
            ft_lstadd_back(&stack, tmp_stack);
            free(tmp[j]);

            j++;
        }
        i++;
    }
    //===  write nbrs stored on stack ==//
    while (stack)
    {
        printf("%d\n",stack->nbr);
        stack = stack->next;
    }
    
    return (0);
}
