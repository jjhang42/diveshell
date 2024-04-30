/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:07:51 by jjhang            #+#    #+#             */
/*   Updated: 2024/04/30 19:34:41 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

static t_pars_tree	*set_read_token_line(t_pars_tree *turn_out)
{
	if (turn_out->type < 64)
		return (turn_out);
	else if (turn_out->left != NULL && turn_out->left->type != INT_MAX)
		return (turn_out->left);
	else if (turn_out->right != NULL && turn_out->right->type != INT_MAX)
		return (turn_out->right);
	return (NULL);
}

static char	**alloc_return_strs(int mode, t_pars_tree *tree)
{
	char	**strs;
	int		idx;

	idx = 0;
	while (tree != NULL)
	{
		if (mode == 0 && (tree->type == 16 || tree->type == 2))
			idx++;
		else if (mode == 1 && !(tree->type == 16 || tree->type == 2))
			idx++;
		tree = tree->left;
	}
	strs = (char **)malloc(sizeof(char *) * (idx + 1));
	if (strs == NULL)
		error_handler(NULL, NULL, 12);
	strs[idx] = NULL;
	return (strs);
}

static void	str_ptr_collector(int mode, char ***strs, t_pars_tree *tree)
{
	int	idx;

	idx = 0;
	while (tree != NULL)
	{
		if (mode == 0 && (tree->type == 16 || tree->type == 2))
		{
			(*strs)[idx] = tree->word;
			tree->type = INT_MAX;
			idx++;
		}
		else if (mode == 1 && !(tree->type == 16 || tree->type == 2))
		{
			(*strs)[idx] = tree->word;
			tree->type = INT_MAX;
			idx++;
		}
		tree = tree->left;
	}
}

void	get_token_line(char ***fd_data, char ***argv, t_pars_tree *tree)
{
	t_pars_tree	*turn_out;
	char		**strs;

	turn_out = set_read_token_line(tree);
	strs = alloc_return_strs(1, turn_out);
	str_ptr_collector(1, &strs, turn_out);
	*argv = strs;
	strs = alloc_return_strs(0, turn_out);
	str_ptr_collector(0, &strs, turn_out);
	*fd_data = strs;
}

t_pars_tree	*get_token_ptr(t_pars_tree *tree)
{
	t_pars_tree	*temp;

	temp = tree;
	if (tree == NULL)
		return (NULL);
	else if (tree->left != NULL && tree->left->type < 64)
		return (tree);
	temp = get_token_ptr(tree->left);
	if (temp != NULL)
		return (temp);
	temp = get_token_ptr(tree->right);
	if (temp != NULL)
		return (temp);
	return (tree);
}
