#include "header.h"

int	ft_env(t_list *cpenv, int fd)
{
	t_list	*cur;

	cur = cpenv;
	while (cur)
	{
		if (ft_strchr(cur->content, '=') != NULL)
			ft_putstr_fd(cur->content, fd);
		write(fd, "\n", 1);
		cur = cur->next;
	}
	return (1);
}
