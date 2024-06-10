/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:07:51 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/07 22:27:29 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

static int	is_redirection(t_pars_tree *tree)
{
	int	flag;

	flag = get_type_flag(tree->type);
	if (flag == REDIRECTION || flag == FILENAME \
		|| flag == JUST_FILENAME)
		return (1);
	if (tree->type == SKIP)
		return (-1);
	return (0);
}

static char	**alloc_return_strs(int mode, int *max, t_pars_tree *tree)
{
	char	**strs;
	int		idx;

	idx = 0;
	while (tree != NULL)
	{
		if (mode == 0 && (is_redirection(tree) == 1))
			idx++;
		if (mode == 1 && (is_redirection(tree) == 0))
			idx++;
		tree = tree->left;
	}
	*max = idx;
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
		if (mode == 0 && (is_redirection(tree) == 1))
		{
			(*strs)[idx] = tree->word;
			if (tree->type != 2)
				tree->type = INT_MAX;
			idx++;
		}
		if (mode == 1 && (is_redirection(tree) == 0))
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
	char	**strs;
	int		idx;

	if (tree == NULL)
		return ;
	idx = 0;
	strs = alloc_return_strs(1, &idx, tree);
	str_ptr_collector(1, &strs, tree);
	*argv = strs;
	strs = alloc_return_strs(0, &idx, tree);
	str_ptr_collector(0, &strs, tree);
	*fd_data = strs;
}
