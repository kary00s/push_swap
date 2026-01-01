#include "push_swap.h"
//////========== sa ===========
void ft_sa(t_stack **head)
{
    t_stack *first;
    t_stack *second;
    first = *head;
    second = first->next;
    first->next  = second->next ;
    second->next = first;
    *head = second ; 
}
//////============ pa =============

void ft_pb(t_stack **stack_A,t_stack **stack_B)
{
    t_stack *head_a;
    t_stack *head_b;

    head_a = *stack_A;
    head_b = *stack_B;
    ft_lstadd_back(&head_b, head_a);
    head_a = head_a->next;
    *stack_A = head_a;
    *stack_B = head_b;

}
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
            free(tmp[j]);

            j++;
        }
        i++;
    }   
    free(tmp);

    // ft_sa(&stack_A);
    
    //===  write nbrs stored on stack ==//
    while (stack_A)
    {
        printf("%d\n",stack_A->nbr);
        stack_A = stack_A->next;
    }
    
    // ft_pb(&stack_A,&stack_B);
    //  while (stack_B)
    // {
    //     printf("%d\n",stack_B->nbr);
    //     stack_B = stack_B->next;
    // }

    
    return (0);
}
