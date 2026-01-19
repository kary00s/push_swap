/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:15:35 by kanahiz           #+#    #+#             */
/*   Updated: 2026/01/19 20:26:20 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct l_stack
{
	int				nbr;
	struct l_stack	*next;
	int				index;
}	t_stack;

void	ft_exit_failure(void);
void	ft_free_all(char **strall, int count);
char	**ft_split(char const *s);
int		main(int ac, char **av);
int		ft_atoi(char *nptr);
void	ft_check_nbr(t_stack *stack, char *str);

t_stack	*ft_lstnew(int nbr);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		stack_size(t_stack *stack);
void	ft_lstadd_front(t_stack **stack, t_stack *new);
void	radix_sort(t_stack **stack_A, t_stack **stack_B, int largest);
void	ft_free_stack(t_stack **stack_A);
int		ft_fill_index(t_stack *head);
int		len_of_largest(int nbr);
void	ft_swap(t_stack **head);
void	ft_rotate(t_stack **head);
void	ft_push_b(t_stack **stack_A, t_stack **stack_B);
void	ft_push_a(t_stack **stack_A, t_stack **stack_B);
void	ft_rotate_reverse(t_stack **stack);

void	sort_two(t_stack **stack);
void	sort_three(t_stack **stack);
void	sort_five(t_stack **stack_A, t_stack **stack_B, int size);

#endif
