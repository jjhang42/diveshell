/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redireaction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:20:22 by jjhang            #+#    #+#             */
/*   Updated: 2024/04/24 16:16:04 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

static int	read_redirection(int *lexer, char **cursor)
{
	char	end_char;
	int		idx;

	end_char = **cursor;
	*lexer = 16;
	idx = 0;
	while (**cursor != '\0' && end_char == **cursor && idx < 2)
	{
		(*cursor)++;
		idx++;
	}
	return (idx);
}

void	get_redirection(int *lexer, char **cursor, t_pars_tree **ptr)
{
	t_pars_tree	*temp;
	char		*redirection;
	int			idx;

	if (!(**cursor == '>' || **cursor == '<'))
		return ;
	redirection = *cursor;
	idx = read_redirection(lexer, cursor);
	redirection = ft_substr(redirection, 0, idx);
	if (redirection == NULL)
		error_handler(*cursor, NULL, 12);
	if (*ptr == NULL)
		*ptr = new_tree_node(*lexer, redirection);
	else if ((*ptr)->type < 32)
	{
		temp = get_last_node(LEFT, *ptr);
		temp->left = new_tree_node(*lexer, redirection);
	}
	else
	{
		temp =get_last_node(RIGHT, *ptr);
		temp->right = new_tree_node(*lexer, redirection);
	}
}
