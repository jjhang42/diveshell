/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 23:49:01 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/09 05:58:05 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

static int	flag_env_manager(char *type, char **argv, t_execute *ms_exe)
{
	t_env_lst	*curpwd;

	curpwd = ft_getenv_from_node(ms_exe->builtin_env_lst, type);
	if (curpwd != NULL && curpwd->content != NULL)
		argv[1] = ft_strdup(curpwd->content);
	else if (curpwd == NULL)
	{
		ft_fprintf (2, "cd: %s no set\n", type);
		return (1);
	}
	return (0);
}

int	cd_flag_processer(int flag, char **argv, t_execute *ms_exe)
{
	int	res;

	res = 0;
	if (flag == 0 && access(argv[1], X_OK) != 0)
		return (builtin_error_handler("cd", "No such file or directory", 1));
	if (flag == 1)
		res = flag_env_manager("HOME", argv, ms_exe);
	else if (flag == 2)
		res = flag_env_manager("OLDPWD", argv, ms_exe);
	return (res);
}

static t_env_lst	*pathcpy(char *name, t_execute *ms_exe)
{
	t_env_lst	*builtin_lev;
	t_env_lst	*env_lev;

	builtin_lev = ft_getenv_from_node(ms_exe->builtin_env_lst, name);
	if (builtin_lev == NULL)
		return (NULL);
	env_lev = ft_getenv_from_node(ms_exe->env_lst, builtin_lev->name);
	if (env_lev == NULL)
		return (builtin_lev);
	free (env_lev->content);
	env_lev->content = NULL;
	env_lev->content = ft_strdup(builtin_lev->content);
	return (builtin_lev);
}

void	cd_after_organize(int flag, char **argv, t_execute *ms_exe)
{
	t_env_lst	*cur_pwd;

	cur_pwd = NULL;
	cur_pwd = pathcpy("PWD", ms_exe);
	pathcpy("OLDPWD", ms_exe);
	if (flag == 2 && cur_pwd != NULL && cur_pwd->content != NULL)
		printf ("%s\n", cur_pwd->content);
	if (flag != 0)
		free(argv[1]);
}
