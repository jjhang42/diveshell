/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 03:28:00 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/09 21:27:41 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

volatile sig_atomic_t	g_signal = 0;

void	init_process_data(t_process *data)
{
	data->argv = NULL;
	data->redirection = NULL;
	data->here_doc_path = NULL;
	data->ex_fd = -1;
	data->fd[READ] = READ;
	data->fd[WRITE] = WRITE;
	data->std_fd[READ] = -1;
	data->std_fd[WRITE] = -1;
	data->process_num = 0;
	data->pipe_num = 0;
	data->last_process = FALSE;
}

void	cmd_turn_out(char *cmdline, t_process *data, t_execute *ms_exe)
{
	t_pars_tree	*tree;
	t_pars_tree	*end_ptr;
	int			lexer;

	tree = NULL;
	tree = minishell_parser(&lexer, cmdline, &end_ptr, &tree);
	if (tree == NULL)
	{
		get_last_execute_exit_code(255, ms_exe);
		return ;
	}
	if (check_here_doc(0, tree, data) != 0)
	{
		get_last_execute_exit_code(1, ms_exe);
		delete_tree_node(&tree);
		return ;
	}
	if ((tree->type & LAST_PROCESS) != LAST_PROCESS)
		tree->type += LAST_PROCESS;
	if (DEBUG)
		print_tree(tree);
	recur_node_cir(tree, data, ms_exe);
	wait_process(ms_exe, data);
	delete_tree_node(&tree);
}

static void	get_std_fd(t_process *data)
{
	data->std_fd[WRITE] = dup(WRITE);
	data->std_fd[READ] = dup(READ);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_execute	ms_exe;
	t_process	data;
	t_env_lst	*exit_code;
	char		*cmdline;

	minishell_preprocess(&ms_exe, argc, argv, envp);
	get_std_fd(&data);
	while (1)
	{
		signal_on(0);
		cmdline = readline("dive-1.8$ ");
		if (cmdline == NULL)
			break ;
		add_history(cmdline);
		init_process_data(&data);
		cmd_turn_out(cmdline, &data, &ms_exe);
		free(cmdline);
		cmdline = NULL;
	}
	printf ("\033[A%s exit\n", "dive-1.8$");
	exit_code = ft_getenv_from_node(ms_exe.builtin_env_lst, "?");
	return (ft_strtol(exit_code->content, NULL, 10));
}
