/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_shell_level.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 07:18:46 by jjhang            #+#    #+#             */
/*   Updated: 2024/05/03 09:11:12 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

static void	get_shell_level_data(t_env_lst *shell_level)
{
	shell_level->name = ft_strdup("SHLVL");
	if (shell_level->name == NULL)
		error_handler("diveshell", NULL, 12);
	shell_level->content = ft_strdup("1");
	if (shell_level->content == NULL)
		error_handler("diveshell", NULL, 12);
}

static void	add_shell_level(t_env_lst *shell_level)
{
	int	level;

	level = ft_atoi(shell_level->content) + 1;
	if (level > 1000)
	{
		ft_printf("diveshell", \
				"warning: shell level (%s) too high, resetting to 1\n\n", \
													shell_level->content);
		level = 1;
	}
	else if (level < 0)
		level = 0;
	free(shell_level->content);
	shell_level->content = ft_itoa(level);
}

void	manage_shell_level(t_env_lst **env_lst)
{
	t_env_lst	*shell_level;

	shell_level = ft_getenv_from_node(*env_lst, "SHLVL");
	if (shell_level == NULL)
	{
		shell_level = ft_calloc(1, sizeof(t_env_lst));
		if (shell_level == NULL)
			error_handler("diveshell", NULL, 12);
		get_shell_level_data(shell_level);
		if (*env_lst == NULL)
			*env_lst = shell_level;
		else
			ft_env_lstadd_back(env_lst, shell_level);
	}
	else
		add_shell_level(shell_level);
}
