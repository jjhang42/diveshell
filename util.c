#include "header.h"

char	**ft_ddup(char **env)
{
	char	**dup;
	int		i;
	int		j;

	i = 0;
	if (env[i])
		i++;
	dup = ft_calloc(sizeof(char *), i + 1);
	j = 0;
	while (j < i)
	{
		dup[j] = ft_strdup(env[j]);
		j++;
	}
	return (dup);
}
