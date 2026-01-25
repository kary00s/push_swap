/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:51:07 by kanahiz           #+#    #+#             */
/*   Updated: 2026/01/25 06:04:49 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_fill_index(t_stack *head)
{
	t_stack	*back;
	t_stack	*front;
	int		index;
	int		largest;

	largest = 0;
	back = head;
	while (back)
	{
		index = 0;
		front = head;
		while (front)
		{
			if (back->nbr > front->nbr)
				index++;
			if (index > largest)
				largest = index;
			front = front->next;
		}
		back->index = index;
		back = back->next;
	}
	return (largest);
}

int	len_of_largest(int nbr)
{
	int	cnt;

	cnt = 0;
	while (nbr > 0)
	{
		nbr = nbr / 2;
		cnt++;
	}
	return (cnt);
}
