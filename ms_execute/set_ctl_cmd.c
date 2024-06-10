/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ctl_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 04:53:55 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/08 16:21:11 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

static void	set_visit_node(t_pars_tree *node)
{
	if (node == NULL)
		return ;
	node->type = INT_MAX;
	if (node->left != NULL)
		set_visit_node(node->left);
	if (node->right != NULL)
		set_visit_node(node->right);
}

int	set_ctl_cmd(t_pars_tree *tree, t_execute *ms_exe)
{
	t_env_lst	*exit_code;
	int			ctl_cmd_type;
	int			exit_flag;
	int			result;

	result = TRUE;
	if (tree == NULL)
		return (-1);
	exit_code = ft_getenv_from_node(ms_exe->builtin_env_lst, "?");
	exit_flag = strtol(exit_code->content, NULL, 10);
	ctl_cmd_type = OR;
	if (ft_strcmp(tree->word, "&&") == 0)
		ctl_cmd_type = AND;
	if (!(!!exit_flag ^ ctl_cmd_type))
	{
		result = FALSE;
		if (tree->right != NULL)
			set_visit_node(tree->right);
	}
	return (result);
}
