/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:54:57 by kanahiz           #+#    #+#             */
/*   Updated: 2026/01/07 20:56:30 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_stack(t_stack **stack_A)
{
	t_stack	*tmp;

	while (*stack_A)
	{
		tmp = (*stack_A)->next;
		free(*stack_A);
		(*stack_A) = tmp;
	}
}
