/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:37:37 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/09 23:49:39 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

static char	*mk_strpath(char *path, char *cmd)
{
	int		path_len;
	int		cmd_len;
	int		idx;
	char	*res_path;

	path_len = ft_strlen(path);
	cmd_len = ft_strlen(cmd);
	res_path = (char *)malloc(sizeof(char) * (path_len + cmd_len + 2));
	if (res_path == NULL)
	{
		error_handler ("malloc failed", NULL, 12);
		exit (errno);
	}
	ft_memcpy(res_path, path, path_len);
	res_path[path_len] = '/';
	idx = 0;
	while (idx < cmd_len)
	{
		res_path[idx + path_len + 1] = cmd[idx];
		idx++;
	}
	res_path[idx + path_len + 1] = '\0';
	return (res_path);
}

static char	**ft_getpath(t_env_lst *env)
{
	t_env_lst	*path_node;
	char		*path;
	char		**div_path;

	div_path = NULL;
	path_node = ft_getenv_from_node(env, "PATH");
	if (path_node != NULL)
		path = path_node->content;
	else
		path = NULL;
	if (path != NULL)
	{
		div_path = ft_split(path, ':');
		free(path);
		path = NULL;
	}
	return (div_path);
}

static char	*get_absolute_path(char *cmd, t_env_lst *env)
{
	char	*path;
	char	**div_path;
	int		idx;

	div_path = ft_getpath(env);
	if (div_path == NULL)
		return (NULL);
	idx = 0;
	while (div_path[idx] != NULL)
	{
		path = mk_strpath(div_path[idx], cmd);
		if (access(path, F_OK) != -1)
		{
			double_free(div_path);
			return (path);
		}
		free(path);
		path = NULL;
		idx++;
	}
	double_free(div_path);
	error_handler(cmd, "command not found", 127);
	return (NULL);
}

static char	*is_relative_cmd(char *cmd)
{
	struct stat	file_stat;
	int			flag;
	char		*path;

	path = NULL;
	flag = 0;
	if (stat(cmd, &file_stat) == 0 && (file_stat.st_mode & S_IFMT) == S_IFDIR)
	{
		error_handler (cmd, "is a directory", 126);
		return (NULL);
	}
	if (access(cmd, X_OK) == 0)
	{
		if (flag == 1)
			return (NULL);
		path = ft_strdup(cmd);
		return (path);
	}
	return (NULL);
}

// error_handler && exit will be
char	*is_cmd(char *cmd, t_env_lst *env)
{
	char	*path;

	path = is_relative_cmd(cmd);
	if (path == NULL)
		path = get_absolute_path(cmd, env);
	if (path == NULL)
		error_handler(cmd, NULL, 127);
	return (path);
}
