/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:08:59 by jjhang            #+#    #+#             */
/*   Updated: 2024/05/04 19:05:33 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

static void	get_pwd_data(char *name, t_env_lst *pwd_node)
{
	int	idx;

	pwd_node->name = ft_strdup(name);
	if (pwd_node->name == NULL)
		error_handler("diveshell", NULL, 12);
	pwd_node->content = getcwd(NULL, 0);
	if (pwd_node->content == NULL)
	{
		idx = 1;
		while (pwd_node->content == NULL && idx < 5)
			pwd_node->content = getcwd(NULL, idx * 1024);
		if (pwd_node->content == NULL)
			error_handler("diveshell", name, 12);
	}
}

void	manage_pwd(char *name, t_env_lst **env_lst)
{
	t_env_lst	*pwd_node;

	pwd_node = ft_getenv_from_node(*env_lst, name);
	if (pwd_node == NULL)
	{
		pwd_node = ft_calloc(1, sizeof(t_env_lst));
		if (pwd_node == NULL)
			error_handler("diveshell", name, 12);
		get_pwd_data(name, pwd_node);
		if (*env_lst == NULL)
			*env_lst = pwd_node;
		else
			ft_env_lstadd_back(env_lst, pwd_node);
	}
}
