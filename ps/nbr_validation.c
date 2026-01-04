#include "push_swap.h"

int	ft_atoi(char *nptr)
{
	int				sign;
	unsigned long	res;
	int i;
	
    i = 0;
	res = 0;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while(nptr[i])
	{
        if((nptr[i] >= '0' && nptr[i] <= '9'))
	    {	res = res * 10 + (nptr[i] - '0');
            if((sign == -1 && res >= 2147483648) || (sign == 1 && res >= 2147483647))
                exit_failure();
        }
        else
            exit_failure();
    i++;
        }
	return (res * sign);
}
void ft_check_nbr(t_stack *stack,char *str)
{
    int nbr;
    if (!stack)
        return;
    nbr = ft_atoi(str);    
 	while (stack)
 	{
        if(stack->nbr == nbr)
            exit_failure();
        stack = stack->next;
    }

}