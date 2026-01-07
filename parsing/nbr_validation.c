/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 20:54:07 by kanahiz           #+#    #+#             */
/*   Updated: 2026/01/07 20:54:42 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(char *nptr)
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
		if ((sign == -1 && res >= 2147483648) || (sign == 1
				&& res >= 2147483647))
			ft_exit_failure();
	}
	if (temp == i)
		return (ft_exit_failure(), 0);
	return (res * sign);
}

void	ft_check_nbr(t_stack *stack, char *str)
{
	int	nbr;

	if (!str)
		ft_exit_failure();
	nbr = ft_atoi(str);
	while (stack)
	{
		if (stack->nbr == nbr)
			ft_exit_failure();
		stack = stack->next;
	}
}
