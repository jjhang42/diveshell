/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:58:06 by jjhang            #+#    #+#             */
/*   Updated: 2024/04/24 16:32:06 by jjhang           ###   ########.fr       */
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

void	get_pipe(int *lexer, char **cursor, t_pars_tree **ptr)
{
	t_pars_tree	*temp;
	char		*pipe;
	int			idx;

	if (**cursor != '|')
		return ;
	pipe = *cursor;
	idx = 0;
	while ((*cursor)[idx] != '\0' && (*cursor)[idx] == '|')
		idx++;
	if (idx != 1)
		return ;
	(*cursor)++;
	(*lexer) = 64;
	pipe = ft_substr(pipe, 0, idx);
	if (pipe == NULL)
		error_handler(*cursor, NULL, 12);
	if (*ptr == NULL)
		syntax_error("|");
	else
	{
		temp = new_tree_node(*lexer, pipe);
		if ((*ptr)->type > 64 && (*ptr)->left != NULL)
		{
			temp->left = (*ptr)->right;
			(*ptr)->right =	temp;
		}
		else
			(*ptr) = add_tree_front(*ptr, temp);
	}
}
