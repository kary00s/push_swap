/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:55:30 by kanahiz           #+#    #+#             */
/*   Updated: 2026/01/27 13:16:26 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ft_lstadd_front(t_stack **stack, t_stack *new)
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

int	stack_size(t_stack *stack)
{
	int	cnt;

	cnt = 0;
	while (stack)
	{
		stack = stack->next;
		cnt++;
	}
	return (cnt);
}

int	ft_check_stack(t_stack *head)
{
	t_stack	*curr;
	t_stack	*next;

	curr = head;
	next = curr->next;
	while (curr && next)
	{
		if (curr->nbr < next->nbr)
		{
			curr = curr->next;
			next = next->next;
		}
		else
			return (1);
	}
	return (-1);
}
