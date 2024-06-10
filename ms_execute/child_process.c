/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:45:46 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/10 00:06:46 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

static void	do_programs(t_execute *ms_exe, t_process *data)
{
	char	*path;
	char	**envp;

	path = is_cmd(data->argv[0], ms_exe->env_lst);
	envp = get_env_arr(ms_exe->env_lst);
	execve(path, data->argv, envp);
	exit(1);
}

static void	recover_stdio(t_process *data)
{
	if (data->std_fd[READ] != -1)
	{
		if (dup2(data->std_fd[READ], STDIN_FILENO) < 0)
			error_handler (data->argv[0], NULL, 9);
		close(data->std_fd[READ]);
	}
	if (data->std_fd[WRITE] != -1)
	{
		if (dup2(data->std_fd[WRITE], STDOUT_FILENO) < 0)
			error_handler (data->argv[0], NULL, 9);
		close(data->std_fd[WRITE]);
	}
}

void	child_process(int pid, t_execute *ms_exe, t_process *data)
{
	int	is_builtin;
	int	result;

	result = 0;
	is_builtin = FALSE;
	redirection_process(data);
	if (is_builtin_function(data->argv[0]))
	{
		is_builtin = TRUE;
		is_cmd_turn_out(data->argv, ms_exe);
		get_last_execute_exit_code(result, ms_exe);
		if (data->process_num != 0)
			exit(result);
		recover_stdio(data);
	}
	if (pid == 0 && is_builtin == FALSE)
		do_programs(ms_exe, data);
	free(data->argv);
	free(data->redirection);
}
