#include "header.h"

int	ft_env(char **envp, int fd)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strchr(envp[i], '=') != NULL)
			ft_putstr_fd(envp[i], fd);
		write(fd, "\n", 1);
		i++;
	}
	return (1);
}
