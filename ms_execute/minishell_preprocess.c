/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_preprocess.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 06:39:21 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/09 23:57:45 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

void	get_builtin_val(t_env_lst **builtin_env)
{
	t_env_lst	*temp;
	char		*name;
	char		*content;

	name = ft_strdup("PWD");
	if (name == NULL)
		error_handler("get_builtin_env", NULL, 12);
	content = getcwd(NULL, 0);
	if (content == NULL)
		error_handler("get_builtin_env", NULL, 12);
	temp = ft_env_lstnew(name, content);
	ft_env_lstadd_back(builtin_env, temp);
	temp = ft_env_splitnew("HOME=/Users/jjhang");
	ft_env_lstadd_back(builtin_env, temp);
	name = ft_strdup("~");
	if (name == NULL)
		error_handler("get_builtin_env", NULL, 12);
	temp = ft_env_lstnew(name, "/Users/jjhang");
	ft_env_lstadd_back(builtin_env, temp);
}

void	minishell_preprocess(t_execute *ms_exe, \
										int argc, char *argv[], char *envp[])
{
	if ((argc != 1 && argv))
	{
		ft_printf ("This behavior is not supported.\n");
		exit (255);
	}
	signal(SIGPIPE, SIG_IGN);
	ms_exe->builtin_env_lst = NULL;
	ms_exe->env_lst = NULL;
	ms_exe->env_lst = get_env_lst(envp);
	get_last_execute_exit_code(0, ms_exe);
	manage_pwd("PWD", &ms_exe->env_lst);
	manage_shell_level(&ms_exe->env_lst);
	get_builtin_val(&ms_exe->builtin_env_lst);
}
