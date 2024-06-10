/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_pipe.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:44:55 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/09 21:46:57 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PIPE_H
# define MINISHELL_PIPE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include "ft_parse.h"

# define READ 0
# define WRITE 1
# define EX 2

# define AND 1
# define OR 0

typedef struct s_process
{
	int				pid;
	int				ex_fd;
	int				fd[2];
	int				std_fd[2];
	unsigned int	process_num;
	unsigned int	pipe_num;
	int				last_process;
	char			**argv;
	char			**redirection;
	char			*here_doc_path;
	t_pars_tree		*ex_node;
}	t_process;

/* input redirection func */
int		check_here_doc(int trap, t_pars_tree *tree, t_process *data);
void	input_redirection(char *filename, t_process *data);

/* output redirection func */
void	output_redirection(char *filename, t_process *data);
void	appending_output(char *filename, t_process *data);

/* redirection utils */
void	input_redirection_flag_ctl(t_process *data);
void	output_redirection_flag_ctl(t_process *data);
#endif