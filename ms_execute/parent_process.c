/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:26:49 by jjhang            #+#    #+#             */
/*   Updated: 2024/05/27 16:43:26 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

int	parent_process(t_process *data)
{
	if (data->fd[WRITE] != WRITE)
		close(data->fd[WRITE]);
	if (data->ex_fd != -1)
		close(data->ex_fd);
	if (data->fd[READ] != READ)
		data->ex_fd = data->fd[READ];
	if (data->argv != NULL)
	{
		free(data->argv);
		data->argv = NULL;
	}
	if (data->redirection != NULL)
	{
		free(data->redirection);
		data->redirection = NULL;
	}
	return (0);
}
