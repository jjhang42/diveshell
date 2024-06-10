/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:11:47 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/09 06:56:09 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

/*int chdir(const char *path)*/
static int	cd_preprocess(int *flag, char **argv)
{
	int	idx;

	idx = 0;
	while (argv[idx] != NULL)
	{
		if (idx == 1 && ft_strcmp(argv[idx], "-") == 0)
			*flag = 2;
		idx++;
	}
	if (idx == 1)
		*flag = 1;
	if (idx > 2)
		return (-1);
	return (*flag);
}

static t_env_lst	*renew_pwd(char *env_name, char *path, t_execute *ms_exe)
{
	t_env_lst	*temp;
	char		*name;

	name = ft_strdup(env_name);
	if (name == NULL)
		error_handler(NULL, NULL, 12);
	temp = ft_getenv_from_node(ms_exe->builtin_env_lst, name);
	if (temp == NULL)
	{
		temp = ft_env_lstnew(name, NULL);
		ft_env_lstadd_back(&ms_exe->builtin_env_lst, temp);
	}
	else if (temp != NULL)
		free(name);
	if (temp != NULL && temp->content != NULL)
	{
		free(temp->content);
		temp->content = NULL;
	}
	temp->content = path;
	return (temp);
}

static int	go_to_pwd(char *path, t_execute *ms_exe)
{
	char		*cur_path;

	cur_path = getcwd(NULL, 0);
	if (cur_path == NULL)
		builtin_error_handler("cd", "No such file or directory", 12);
	if (chdir(path) != 0)
	{
		free(cur_path);
		return (builtin_error_handler("cd", "failed to change directory", 1));
	}
	renew_pwd("OLDPWD", cur_path, ms_exe);
	cur_path = NULL;
	cur_path = getcwd(NULL, 0);
	if (cur_path == NULL)
		builtin_error_handler("cd", "No such file or directory", 12);
	renew_pwd("PWD", cur_path, ms_exe);
	return (0);
}

int	ft_cd(char **argv, t_execute *ms_exe)
{
	int			flag;
	int			check;

	flag = 0;
	if (cd_preprocess(&flag, argv) < 0)
		return (builtin_error_handler("cd", "too many arguments", 1));
	check = cd_flag_processer(flag, argv, ms_exe);
	if (check != 0)
		return (1);
	check = go_to_pwd(argv[1], ms_exe);
	if (check != 0)
		return (1);
	cd_after_organize(flag, argv, ms_exe);
	return (0);
}
