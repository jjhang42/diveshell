/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:01:08 by codespace         #+#    #+#             */
/*   Updated: 2024/06/09 06:47:30 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

static void	unset_node(char *name, t_env_lst **lst)
{
	t_env_lst	*cur;
	t_env_lst	*pre;
	t_env_lst	*next;

	if (*lst == NULL || ft_getenv_from_node((*lst), name) == NULL)
		return ;
	cur = (*lst);
	if (ft_strcmp((*lst)->name, name) == 0)
	{
		next = (*lst)->next;
		delete_env_node(cur);
		(*lst) = next;
		return ;
	}
	while (cur != NULL)
	{
		if (cur->next != NULL && ft_strcmp(cur->next->name, name) == 0)
			break ;
		cur = cur->next;
	}
	pre = cur;
	next = cur->next->next;
	delete_env_node(cur->next);
	pre->next = next;
}

static void	unset_sequence(char *name, t_execute *ms_exe)
{
	unset_node(name, &ms_exe->env_lst);
	unset_node(name, &ms_exe->builtin_env_lst);
}

int	ft_unset(char *argv[], t_execute *ms_exe)
{
	int	result;
	int	check;
	int	idx;

	idx = 1;
	result = 0;
	while (argv[idx] != NULL)
	{
		check = is_able_to_envname(argv[idx]);
		if (check == 0)
			unset_sequence(argv[idx], ms_exe);
		else
		{
			result = 1;
			printf \
			("diveshell: unset:'%s': not a valid identifier\n", argv[idx]);
		}
		idx++;
	}
	return (result);
}
