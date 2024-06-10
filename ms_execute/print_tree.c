/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 01:50:06 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/07 12:21:47 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

static void	print_node(t_pars_tree *node)
{
	ft_printf("[%s](type:%d)", node->word, node->type);
}

static void	print_tree_helper(int type, t_pars_tree *root, int level)
{
	int	i;

	if (root == NULL)
		return ;
	i = 0;
	while (i < level)
	{
		if (i + 1 == level)
		{
			ft_printf("└---");
			if (type == 0)
				ft_printf ("[L]:");
			else
				ft_printf ("[R]:");
		}
		else
			ft_printf ("	");
		i++;
	}
	print_node(root);
	ft_printf("\n");
	print_tree_helper(0, root->left, level + 1);
	print_tree_helper(1, root->right, level + 1);
}

void	print_tree(t_pars_tree *head)
{
	print_tree_helper(0, head, 0);
}
