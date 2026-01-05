#include"../push_swap.h"

void	ft_free_stack(t_stack **stack_A)
{
	t_stack *tmp;
	while (*stack_A)
	{
		tmp = (*stack_A)->next ;
		free(*stack_A);
		(*stack_A) = tmp;
	}
}