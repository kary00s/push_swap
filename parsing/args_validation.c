#include "../push_swap.h"

static int	ft_count_words(const char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != ' ')
			i++;
		count++;
		while (s[i] && s[i] == ' ')
			i++;
	}
	return (count);
}

void	ft_free_all(char **strall, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strall[i]);
		i++;
	}
	free (strall);
}

static char	*ft_fil(char const *s, int *index)
{
	int		i;
	char	*out;
	int		j;

	i = (*index);
	j = 0;
	while (s[i++] == ' ')
		(*index)++;

	while (s[i] != ' ' && s[i])
		i++;
	out = malloc(i - (*index) + 1);
	if (!out)
	return (NULL);
	while ((*index) < i)
	{
		out[j] = s[(*index)];
		(*index)++;
		j++;
	}
	out[j] = '\0';
	return (out);
}
char	**ft_split(char const *s)
{
	int		index;
	int		i;
	int		len;
	char	**strall;

	index = 0;
	i = 0;
	len = ft_count_words(s);
	if (len == 0)
		ft_exit_failure();

	strall = malloc(sizeof(char *) * (len + 1));
	if (!strall)
		return (NULL);
	while (i < len)
	{ 
		strall[i] = ft_fil(s, &index);
		if (strall[i] == NULL)
			return (ft_free_all(strall, i),NULL);
		i++;
	}
	strall[i] = NULL;
	return (strall);
}
