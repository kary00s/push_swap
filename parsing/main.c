#include "push_swap.h"

//////===========================
int main(int ac, char **av)
{
    t_stack *stack_A = NULL;
    t_stack *tmp_stack = NULL;
    t_stack *stack_B = NULL;

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
            ft_check_nbr(stack_A,tmp[j]);
            nbr = ft_atoi(tmp[j]);
            tmp_stack = ft_lstnew(nbr);
            
            ft_lstadd_back(&stack_A, tmp_stack);
            j++;
        }
        i++;
    }   
    ft_free_all(tmp,j);
    // ft_sa(&stack_A);
    
    //===  write nbrs stored on stack ==//
    
    printf("=====stack a=====\n");
    // ft_push(&stack_A,&stack_B);
    // ft_push(&stack_A,&stack_B);
    // ft_push(&stack_A,&stack_B);
    // ft_push(&stack_A,&stack_B);
    // ft_push(&stack_A,&stack_B);

    // ft_rotate(&stack_A);
    // ft_rotate_reverse(&stack_B);
    ft_fill_index(stack_A);
    while (stack_A)
    {
        printf("%d\n",stack_A->index);
        stack_A = stack_A->next;
    }
    printf("=====stack b=====\n");
    while (stack_B)
    {
        printf("%d\n",stack_B->nbr);
        stack_B = stack_B->next;
    }

    
    return (0);
}
