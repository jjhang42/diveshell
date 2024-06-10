/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:02:34 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/05 21:26:32 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

/* redirection flag
* pipe: last_node = 128;
* pipe: ex_fd = 64
* pipe: fd[WRITE] = 32
* pipe: fd[READ] = 16
* >> : 8
* << : 4
* >  : 2
* <  : 1
*/
static int	*redirection_open_squence(t_process *data)
{
	char	**array_lst;
	int		idx;

	idx = 0;
	array_lst = data->redirection;
	while (array_lst[idx] != NULL)
	{
		if (array_lst[idx + 1] != NULL && ft_strcmp(array_lst[idx], "<<") == 0)
			input_redirection(array_lst[idx + 1], data);
		if (array_lst[idx + 1] != NULL && ft_strcmp(array_lst[idx], "<") == 0)
			input_redirection(array_lst[idx + 1], data);
		if (array_lst[idx + 1] != NULL && ft_strcmp(array_lst[idx], ">>") == 0)
			appending_output(array_lst[idx + 1], data);
		if (array_lst[idx + 1] != NULL && ft_strcmp(array_lst[idx], ">") == 0)
			output_redirection(array_lst[idx + 1], data);
		idx++;
	}
	return (0);
}

static void	set_open_process(t_process *data)
{
	if (data->last_process == TRUE)
	{
		if (data->fd[WRITE] != WRITE)
			close(data->fd[WRITE]);
		data->fd[WRITE] = WRITE;
		if (data->process_num > 1)
			return ;
	}
	if (data->fd[READ] != READ && data->ex_fd != -1)
	{
		if (data->ex_fd != data->fd[READ])
			close(data->fd[READ]);
		data->fd[READ] = data->ex_fd;
	}
	else if (data->fd[READ] != READ && data->ex_fd == -1)
	{
		close(data->fd[READ]);
		data->fd[READ] = READ;
	}
}

static void	dup2_process(t_process *data)
{
	if (data->fd[READ] != READ)
	{
		if (dup2(data->fd[READ], STDIN_FILENO) < 0)
			error_handler(data->argv[0], NULL, 9);
		close(data->fd[READ]);
	}
	if (data->fd[WRITE] != WRITE)
	{
		if (dup2(data->fd[WRITE], STDOUT_FILENO) < 0)
			error_handler(data->argv[0], NULL, 9);
		close(data->fd[WRITE]);
	}
}

static void	dup1_process(t_process *data)
{
	if (data->fd[READ] != READ)
	{
		data->std_fd[READ] = dup(STDIN_FILENO);
		if (dup2(data->fd[READ], STDIN_FILENO) < 0)
			error_handler(data->argv[0], NULL, 9);
		close(data->fd[READ]);
	}
	if (data->fd[WRITE] != WRITE)
	{
		data->std_fd[WRITE] = dup(STDOUT_FILENO);
		if (dup2(data->fd[WRITE], STDOUT_FILENO) < 0)
			error_handler(data->argv[0], NULL, 9);
		close(data->fd[WRITE]);
	}
}

void	redirection_process(t_process *data)
{
	set_open_process(data);
	redirection_open_squence(data);
	if (data->process_num != 0)
		dup2_process(data);
	else
		dup1_process(data);
}
