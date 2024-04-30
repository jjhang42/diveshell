#include "header.h"
/*char *getcwd (char *buff, size_t buff_size)*/

int	ft_pwd(int fd)
{
	char	*s;

	s = getcwd(NULL, 0);
	if (!s)
		exit(1);
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
	free(s);
	return (1);
}
