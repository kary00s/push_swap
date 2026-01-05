#include "push_swap.h"


t_stack	*ft_lstnew(int nbr)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nbr = nbr;
	node->next = NULL;
	return (node);
}
void ft_lstadd_front(t_stack **stack, t_stack *new )
{
    new->next = *stack;
    *stack = new;
}
void	ft_lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}
int stack_size(t_stack *stack)
{
    int cnt = 0;
    while (stack)
    {
        stack = stack->next;
        cnt ++;
    }
    return cnt;
}
void exit_failure(void)
{
	write(2,"Error\n",6);
	exit(EXIT_FAILURE);
}