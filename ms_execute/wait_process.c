/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:58:13 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/09 21:23:47 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

t_env_lst	*get_last_execute_exit_code\
			(unsigned char exit_no, t_execute *ms_exe)
{
	t_env_lst	*node;
	char		*exit_str;

	node = ft_getenv_from_node(ms_exe->builtin_env_lst, "?");
	if (node == NULL)
	{
		node = ft_env_lstnew("?", NULL);
		ft_env_lstadd_back(&ms_exe->builtin_env_lst, node);
	}
	else
		free(node->content);
	exit_str = ft_itoa(exit_no);
	if (exit_str == NULL)
		error_handler("exitno", NULL, 12);
	node->content = exit_str;
	return (node);
}

static int	exit_msg(int res)
{
	if (res == SIGINT)
		ft_printf ("\n");
	else if (res == SIGQUIT)
		ft_printf ("Quit: %d\n", res);
	res = res + 128;
	return (res);
}

void	wait_process(t_execute *ms_exe, t_process *data)
{
	int				result_pid;
	int				status;
	int				res;
	unsigned int	idx;

	idx = 0;
	res = 0;
	close(data->ex_fd);
	status = 0;
	while (idx < data->process_num)
	{
		result_pid = wait(&status);
		if (data->pid == result_pid)
			g_signal = WEXITSTATUS(status);
		idx++;
	}
	if (WIFSIGNALED(status))
	{
		res = WTERMSIG(status);
		res = exit_msg(res);
	}
	get_last_execute_exit_code(res, ms_exe);
	init_process_data(data);
}
