/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:55:10 by kanahiz           #+#    #+#             */
/*   Updated: 2026/01/21 20:34:10 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_fill_stack(int ac, char **av, t_stack **stack_a)
{
	char	**tmp;
	int		i;
	int		j;
	int		nbr;

	tmp = NULL;
	i = 1;
	while (i < ac)
	{
		tmp = ft_split(av[i]);
		if (!tmp)
			return (ft_exit_failure());
		j = 0;
		while (tmp[j])
		{
			nbr = ft_atoi(tmp[j]);
			ft_check_nbr(*stack_a, tmp[j]);
			ft_lstadd_back(stack_a, ft_lstnew(nbr));
			j++;
		}
		ft_free_all(tmp, j);
		i++;
	}
}

int	check_latgest(t_stack *stack_A)
{
	int	largest;

	largest = ft_fill_index(stack_A);
	largest = len_of_largest(largest);
	return (largest);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		largest;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	ft_fill_stack(ac, av, &stack_a);
	largest = check_latgest(stack_a);
	size = stack_size(stack_a);
	if (size == 2)
		sort_two(&stack_a);
	else if (size == 3)
		sort_three(&stack_a);
	else if (size == 5 || size == 4)
		sort_five(&stack_a, &stack_b, size);
	else
		radix_sort(&stack_a, &stack_b, largest);
	ft_free_stack(&stack_a);
	exit(EXIT_SUCCESS);
}
