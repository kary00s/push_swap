/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:54:57 by kanahiz           #+#    #+#             */
/*   Updated: 2026/01/25 05:47:11 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_stack(t_stack **stack_A)
{
	t_stack	*tmp;

	if (!(*stack_A) || (!stack_A))
		return ;
	while (*stack_A)
	{
		tmp = (*stack_A)->next;
		free(*stack_A);
		(*stack_A) = tmp;
	}
}

char	**ft_free_all(char **strall)
{
	char	**tmp;

	tmp = strall;
	if (!tmp)
		return (NULL);
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(strall);
	return (NULL);
}

void	ft_exit_failure(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	ft_free_and_exit(t_stack **stack, char **splited)
{
	ft_free_all(splited);
	ft_free_stack(stack);
	ft_exit_failure();
}
