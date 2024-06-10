/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_subshell2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:58:33 by jjhang            #+#    #+#             */
/*   Updated: 2024/05/28 14:15:59 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

t_pars_tree	*add_new_subshell(t_pars_tree *new_node, t_pars_tree **ptr)
{
	t_pars_tree	*temp;

	if ((*ptr) == NULL)
		(*ptr) = new_node;
	else if ((*ptr)->type < 64)
	{
		temp = get_last_node(LEFT, *ptr);
		temp->left = new_node;
	}
	else
	{
		temp = get_last_node(RIGHT, *ptr);
		if (temp->type < PIPE)
		{
			temp = get_last_node(LEFT, temp);
			temp->left = new_node;
		}
		else
			temp->right = new_node;
	}
	return (new_node);
}
