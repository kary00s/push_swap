#include "push_swap.h"

//============ swap A / B=================//
void ft_swap(t_stack **head)
{
    t_stack *first;
    t_stack *second;
    first = *head;
    second = first->next;
    first->next  = second->next ;
    second->next = first;
    *head = second ; 
}
//============ rotate A / B =================//
void ft_rotate(t_stack **head)
{
    t_stack *new_stak;
    t_stack *tmp;
    tmp = *head;
    new_stak = tmp->next;
    *head = new_stak;
    ft_lstadd_back(head,tmp);
}
//============== push B ==============//
void ft_push(t_stack **stack_A,t_stack **stack_B)
{
    t_stack *new_stack_a = *stack_A;
    t_stack *new_stack_b = *stack_B;
    *stack_A = new_stack_a->next;
    ft_lstadd_front(stack_B, new_stack_a);
}
//======= rotate reverse A ==========//
void ft_rotate_reverse(t_stack **stack)
{
    t_stack *alo ;
    t_stack *tmp = *stack;
    while (tmp->next->next)
        tmp = tmp->next;
    alo = tmp->next;
    tmp->next = NULL;
    ft_lstadd_front(stack,alo);
}
//========= 