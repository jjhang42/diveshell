#ifndef HEADER_H
# define HEADER_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"

int	exitno;

char	**ft_ddup(char **env);

#endif
