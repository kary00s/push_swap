#include"../push_swap.h"

void	ft_free_stack(t_stack **stack_A)
{
	t_stack *tmp = (*stack_A);
	while (tmp)
	{
		tmp->next = (*stack_A)->next ;
		free(*stack_A);
	}
}