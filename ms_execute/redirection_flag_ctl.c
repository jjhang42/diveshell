/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_flag_ctl.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:25:46 by jjhang            #+#    #+#             */
/*   Updated: 2024/05/23 14:08:04 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_pipe.h"

void	input_redirection_flag_ctl(t_process *data)
{
	ssize_t	fd;

	fd = read(data->fd[READ], NULL, 0);
	if (fd != -1 && data->fd[READ] != READ)
		close(data->fd[READ]);
}

void	output_redirection_flag_ctl(t_process *data)
{
	ssize_t	fd;

	fd = read(data->fd[WRITE], NULL, 0);
	if (fd != -1 && data->fd[WRITE] != WRITE)
		close(data->fd[WRITE]);
}
