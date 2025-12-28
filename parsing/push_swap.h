
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct l_stack
{
	int nbr;
	struct l_stack *next;
}t_stack;


void	ft_free_all(char **strall, int count);
char	**ft_split(char const *s);
int	ft_atoi(char *nptr);
int main(int ac, char **av);
void ft_check_nbr(t_stack *stack,char *str);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int nbr);
#endif