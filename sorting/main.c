#include "push_swap.h"
///////////////////////////////////

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
    //===  write nbrs stored on stack ==//
    int largest = ft_fill_index(stack_A);
    largest = len_of_largest(largest);
    int x = 0;
    i = 0; 
    int cnt ;
    int size = stack_size(stack_A);
    while (i < largest)
    {
        int j = 0;
        tmp_stack = stack_B;
        cnt = 0;
        while (j < size - 1)
        {
            x = stack_A->index >> i & 1;
            // printf("shift by %d the number %d: %d\n", i,stack_A->index, x);
            if (x==1)
                ft_rotate(&stack_A);
                
            if (x==0)
            {   
                ft_push_b(&stack_A,&stack_B);
            }
                j++;
        }
        while (stack_B)
            ft_push_a(&stack_A,&stack_B);
        i++;
    }   

     while (stack_A)
     {
         printf("%d\n",stack_A->nbr);
         stack_A = stack_A->next;
     }
     while (stack_B)
     {
         printf("%d\n",stack_B->nbr);
         stack_B = stack_B->next;
     }
    return (0);
}
