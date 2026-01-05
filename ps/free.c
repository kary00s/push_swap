#include"push_swap.h"

void	ft_free_stack(t_stack **stack_A,t_stack **stack_B)
{
	while ((*stack_A))
	{
		free(*stack_A);
		*stack_A = (*stack_A)->next ;
	}
	free (stack_A);

    while ((*stack_B))
	{
		free(*stack_B);
		*stack_B = (*stack_B)->next ;
	}
	free (stack_B);
}