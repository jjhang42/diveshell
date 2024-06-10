/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_exe_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:56:01 by jjhang            #+#    #+#             */
/*   Updated: 2024/05/28 20:25:36 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

void	set_tree_to_int_max(t_pars_tree *tree)
{
	if (tree->left != NULL && tree->right != NULL && \
		tree->left->type == INT_MAX && tree->right->type == INT_MAX)
		tree->type = INT_MAX;
}

int	get_type_flag(int type)
{
	if ((type & SUB_SHELL) == SUB_SHELL)
		type -= SUB_SHELL;
	type = move_last_process_flag(type);
	return (type);
}

int	move_last_process_flag(int type)
{
	if ((type & LAST_PROCESS) == LAST_PROCESS)
		type -= LAST_PROCESS;
	return (type);
}

int	add_last_process_flag(int type)
{
	if ((type & LAST_PROCESS) != LAST_PROCESS)
		type += LAST_PROCESS;
	return (type);
}
