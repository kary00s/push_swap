#include"push_swap.h"
int stack_lentgh(t_stack *list)
{
    int cnt;
    while(list)
    {
        list =  list->next;
        cnt++;
    }
    return cnt;
}

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
///
//////============ pa =============
void ft_pb(t_stack **stack_A, t_stack **stack_B)
{
    t_stack *tmp;

    if (!stack_A || !*stack_A)
        return;

    tmp = *stack_A;              
    *stack_A = tmp->next;        
    tmp->next = NULL;            
    ft_lstadd_front(stack_B, tmp);
}