/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redireaction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:20:22 by jjhang            #+#    #+#             */
/*   Updated: 2024/05/31 20:58:27 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

static int	read_redirection(char **cursor)
{
	char	end_char;
	int		idx;

	end_char = **cursor;
	idx = 0;
	while (**cursor != '\0' && end_char == **cursor && idx < 2)
	{
		(*cursor)++;
		idx++;
	}
	return (idx);
}

static void	add_new_rediriection(char *redirection, \
								t_pars_tree **end_ptr, t_pars_tree **tree)
{
	t_pars_tree	*temp;

	if (*tree == NULL)
	{
		*tree = new_tree_node(REDIRECTION, redirection);
		*end_ptr = *tree;
	}
	else if ((*tree)->type < PIPE)
	{
		temp = get_last_node(LEFT, *tree);
		temp->left = new_tree_node(REDIRECTION, redirection);
		*end_ptr = temp->left;
	}
	else
	{
		temp = get_last_node(RIGHT, *tree);
		if (temp->type < PIPE)
		{
			temp = get_last_node(LEFT, temp);
			temp->left = new_tree_node(REDIRECTION, redirection);
		}
		else
			temp->right = new_tree_node(REDIRECTION, redirection);
		*end_ptr = temp->right;
	}
}

int	get_redirection(int lexer, char **cursor, \
									t_pars_tree **end_ptr, t_pars_tree **tree)
{
	char		*redirection;
	int			idx;

	if ((**cursor != '>' && **cursor != '<') || lexer == INT_MIN)
		return (lexer);
	redirection = *cursor;
	idx = read_redirection(cursor);
	redirection = ft_substr(redirection, 0, idx);
	if (lexer == REDIRECTION)
	{
		syntax_error(&lexer, redirection);
		return (INT_MIN);
	}
	if (redirection == NULL)
		error_handler(*cursor, NULL, 12);
	lexer = REDIRECTION;
	add_new_rediriection(redirection, end_ptr, tree);
	return (lexer);
}
