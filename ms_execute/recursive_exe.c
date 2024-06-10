/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_exe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:10:34 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/08 15:53:10 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

void	recur_node_call(t_pars_tree *tree, t_process *data, t_execute *ms_exe)
{
	int		flag;

	flag = get_type_flag(tree->type);
	if (tree == NULL)
		return ;
	if ((tree->type & LAST_PROCESS) == LAST_PROCESS)
		data->last_process = TRUE;
	open_pipe(data);
	execute_cmd(tree, ms_exe, data);
}

void	recur_node_pipe(t_pars_tree *tree, t_process *data, t_execute *ms_exe)
{
	int	flag;

	flag = get_type_flag(tree->type);
	if (tree == NULL)
		return ;
	if (flag != PIPE)
		return ;
	if (tree->left != NULL)
		recur_node_cir(tree->left, data, ms_exe);
	if (tree->right != NULL)
	{
		if ((tree->type & LAST_PROCESS) == LAST_PROCESS)
			tree->right->type = add_last_process_flag(tree->right->type);
		recur_node_cir(tree->right, data, ms_exe);
	}
	set_tree_to_int_max(tree);
}

void	recur_node_ctl(t_pars_tree *tree, t_process *data, t_execute *ms_exe)
{
	if (tree == NULL)
		return ;
	if (tree->left != NULL)
	{
		tree->left->type = add_last_process_flag(tree->left->type);
		recur_node_cir(tree->left, data, ms_exe);
	}
	wait_process(ms_exe, data);
	set_ctl_cmd(tree, ms_exe);
	if (tree->right != NULL && tree->right->type != INT_MAX)
	{
		if ((tree->type & LAST_PROCESS) == LAST_PROCESS)
			tree->right->type = add_last_process_flag(tree->right->type);
		recur_node_cir(tree->right, data, ms_exe);
	}
	set_tree_to_int_max(tree);
}

void	recur_node_cir(t_pars_tree *tree, t_process *data, t_execute *ms_exe)
{
	int	flag;

	if (tree == NULL)
		return ;
	flag = get_type_flag(tree->type);
	if (flag == CTL_CMD)
		recur_node_ctl(tree, data, ms_exe);
	else if (flag == PIPE)
		recur_node_pipe(tree, data, ms_exe);
	else if (0 < flag && flag < PIPE)
		recur_node_call(tree, data, ms_exe);
}
