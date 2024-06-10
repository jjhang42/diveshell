/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:58:06 by jjhang            #+#    #+#             */
/*   Updated: 2024/05/24 15:20:41 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

t_pars_tree	*add_tree_front(t_pars_tree *old, t_pars_tree *new)
{
	t_pars_tree	*temp;

	temp = old;
	if (new->left == NULL)
		new->left = old;
	else
		new->right = old;
	return (new);
}

static char	*read_pipe(int *lexer, char **cursor)
{
	char	*pipe;
	int		idx;

	pipe = *cursor;
	idx = 0;
	while ((*cursor)[idx] != '\0' && (*cursor)[idx] == '|')
		idx++;
	if (idx != 1)
		return (NULL);
	(*cursor)++;
	pipe = ft_substr(pipe, 0, idx);
	if (pipe == NULL)
		error_handler(*cursor, NULL, 12);
	if (*lexer == 128 || *lexer == 64)
		syntax_error(lexer, pipe);
	*lexer = PIPE;
	return (pipe);
}

int	get_pipe(int lexer, char **cursor, \
									t_pars_tree **end_ptr, t_pars_tree **tree)
{
	t_pars_tree	*temp;
	char		*pipe;

	if (**cursor != '|' || lexer == INT_MIN)
		return (lexer);
	pipe = read_pipe(&lexer, cursor);
	if (pipe == NULL)
		return (lexer);
	if (*tree == NULL)
		syntax_error(&lexer, pipe);
	else
	{
		temp = new_tree_node(lexer, pipe);
		*end_ptr = temp;
		if ((*tree)->type > PIPE && (*tree)->left != NULL)
		{
			temp->left = (*tree)->right;
			(*tree)->right = temp;
		}
		else
			(*tree) = add_tree_front(*tree, temp);
	}
	return (lexer);
}
