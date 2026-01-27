/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:55:18 by kanahiz           #+#    #+#             */
/*   Updated: 2026/01/27 13:13:10 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
	write(1, "sa\n", 3);
}

void	ft_rotate(t_stack **head)
{
	t_stack	*new_stak;
	t_stack	*tmp;

	tmp = *head;
	new_stak = tmp->next;
	*head = new_stak;
	ft_lstadd_back(head, tmp);
	write(1, "ra\n", 3);
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new_stack_a;

	new_stack_a = *stack_a;
	*stack_a = new_stack_a->next;
	ft_lstadd_front(stack_b, new_stack_a);
	write(1, "pb\n", 3);
}

void	ft_push_a(t_stack **stack_A, t_stack **stack_B)
{
	t_stack	*new_stack_b;

	new_stack_b = *stack_B;
	*stack_B = new_stack_b->next;
	ft_lstadd_front(stack_A, new_stack_b);
	write(1, "pa\n", 3);
}

void	ft_rotate_reverse(t_stack **stack)
{
	t_stack	*alo;
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	alo = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(stack, alo);
	write(1, "rra\n", 4);
}
