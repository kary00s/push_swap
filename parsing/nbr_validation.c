#include "push_swap.h"

int	ft_atoi(char *nptr)
{
    // printf("-----------");
	int				sign;
	unsigned long	res;

	res = 0;
	int i;
    i = 0;
	
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
            {
                perror("overflow failure");
                exit(EXIT_FAILURE);    
            }
        }
        else
        {
            perror("arg failure");
            exit(EXIT_FAILURE);    
        }
        i++;
    }
	return (res * sign);
}
void ft_check_nbr(t_stack *stack,char *str)
{
    int nbr;
 
    nbr = ft_atoi(str);
    if (!stack)
        return;    
 	while (stack)
 	{
        if(stack->nbr == nbr)
        {
            printf("double failure");
            exit(EXIT_FAILURE);
        }
        stack = stack->next;
    }

}