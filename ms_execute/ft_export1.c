/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:11:43 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/09 06:00:01 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

static int	export_preprocess(int *flag, char **argv)
{
	int	idx;

	idx = 0;
	while (argv[idx] != NULL)
		idx++;
	if (idx == 1)
		*flag = 1;
	return (idx);
}

static void	renew_envlst(char *option, t_execute *ms_exe)
{
	t_env_lst	*new;
	char		*name;
	char		*content;

	name = get_env_name(option);
	new = ft_getenv_from_node(ms_exe->env_lst, name);
	if (new != NULL)
	{
		content = get_env_content(option);
		if (content != NULL)
		{
			free(new->content);
			new->content = content;
		}
	}
	else
	{
		new = ft_env_splitnew(option);
		ft_env_lstadd_back(&ms_exe->env_lst, new);
	}
	free(name);
}

static int	get_new_env_lst(char *argv[], t_execute *ms_exe)
{
	int	check;
	int	idx;
	int	result;

	idx = 1;
	result = 0;
	while (argv[idx] != NULL)
	{
		check = is_able_to_envname(argv[idx]);
		if (check == 0)
			renew_envlst(argv[idx], ms_exe);
		else
		{
			result = 1;
			ft_fprintf \
			(2, "diveshell: export: '%s': not a valid identifier\n", argv[idx]);
		}
		idx++;
	}
	return (result);
}

int	ft_export(char *argv[], t_execute *ms_exe)
{
	int	flag;
	int	result;

	flag = 0;
	result = 0;
	export_preprocess(&flag, argv);
	if (flag == 1)
		print_ft_export(ms_exe);
	else
		result = get_new_env_lst(argv, ms_exe);
	return (result);
}
