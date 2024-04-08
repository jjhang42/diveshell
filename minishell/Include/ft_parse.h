/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:23:55 by jjhang            #+#    #+#             */
/*   Updated: 2024/04/07 11:50:58 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "libft.h"

# define READ 0
# define WRITE 1
# define EX 2

typedef struct s_token
{
	int		ac;
	int		ex_fd;
	int		pipe[2];
	char	**av;
	char	**env;
	int		flag;
	char	*temp_path;
}	t_token;

int		main(void);
char	*ft_getenv(char *envp[], char *name);
char	**ft_split(char const *s, char c);
void	error_handler(char *filename, char *msg, int err_no);
void	double_free(char **arr);
char	**bottom_up_parser(char *cmdline);

#endif