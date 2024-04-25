/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:56:52 by jjhang            #+#    #+#             */
/*   Updated: 2024/04/24 21:31:24 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

static char	token_start(int *lexer, char c)
{
	if (c == '"')
	{
		*lexer = 4;
		return ('"');
	}
	if (c == '\'')
	{
		*lexer = 8;
		return ('\'');
	}
	if (c == '(')
	{
		*lexer = 32;
		return (')');
	}
	*lexer = 1;
	return (' ');
}

static void	read_word(int *lexer, char end_char, char **cursor)
{
	if (end_char != ' ')
		(*cursor)++;
	while (**cursor != '\0' && **cursor != end_char)
	{
		(*cursor)++;
		if (token_start(lexer, **cursor) != ' ')
		{
			end_char = token_start(lexer, **cursor);
			(*cursor)++;
		}
	}
	if (**cursor != '\0' && end_char != ' ')
		(*cursor)++;
}

static void	add_new_word(int *lexer, char *word, t_pars_tree **ptr)
{
	t_pars_tree	*temp;

	if ((*ptr) == NULL)
		(*ptr) = new_tree_node(*lexer, word);
	else if ((*ptr)->type < 32)
	{
		temp = get_last_node(LEFT, *ptr);
		temp->left = new_tree_node(*lexer, word);
	}
	else
	{
		temp = get_last_node(RIGHT, *ptr);
		temp->right = new_tree_node(*lexer, word);
	}
}

void	get_word(int *lexer, char **cursor, t_pars_tree **ptr)
{
	char		end_char;
	char		*word;

	if (is_control_oprator(*cursor))
		return ;
	end_char = token_start(lexer, **cursor);
	word = *cursor;
	read_word(lexer, end_char, cursor);
	if ((*cursor - word) == 0)
		return ;
	word = ft_substr(word, 0, (*cursor) - word);
	if (word == NULL)
		error_handler(*cursor, NULL, 12);
	add_new_word(lexer, word, ptr);
}
