/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:54:07 by kanahiz           #+#    #+#             */
/*   Updated: 2026/01/25 05:37:06 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

signed long	ft_atoi(char *nptr)
{
	unsigned long	res;
	int				sign;
	int				i;
	int				temp;

	i = 0;
	res = 0;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	temp = i;
	while ((nptr[i] >= '0' && nptr[i] <= '9') && (nptr[i]))
	{
		res = res * 10 + (nptr[i++] - '0');
		if ((sign == -1 && res > 2147483648) || (sign == 1
				&& res > 2147483647))
			return (2147483649);
	}
	if ((!(nptr[i] >= '0' && nptr[i] <= '9') && nptr[i] != '\0') || temp == i)
		return (2147483649);
	return (res * sign);
}

int	ft_check_nbr(t_stack *stack, int nbr)
{	
	if (!stack)
		return (1);
	while (stack)
	{
		if (stack->nbr == nbr)
			return (-1);
		stack = stack->next;
	}
	return (1);
}
