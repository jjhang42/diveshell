/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:56:52 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/09 20:10:35 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

int	word_symbol(char c)
{
	if (c == '>' || c == '<' || c == '|' || c == '&' || c == ' ')
		return (1);
	return (0);
}

char	token_start(int *lexer, char c)
{
	if (c == '"')
	{
		*lexer = DOUBLE_QUOTE;
		return ('"');
	}
	if (c == '\'')
	{
		*lexer = QUOTE;
		return ('\'');
	}
	*lexer = WORD;
	return (' ');
}

static void	add_new_word(int lexer, char *word, \
									t_pars_tree **end_ptr, t_pars_tree **ptr)
{
	t_pars_tree	*temp;

	if ((*ptr) == NULL)
	{
		(*ptr) = new_tree_node(lexer, word);
		*end_ptr = *ptr;
	}
	else if ((*ptr)->type < 64)
	{
		temp = get_last_node(LEFT, *ptr);
		temp->left = new_tree_node(lexer, word);
		*end_ptr = temp->left;
	}
	else
	{
		temp = get_last_node(RIGHT, *ptr);
		if (temp->type < PIPE)
		{
			temp = get_last_node(LEFT, temp);
			temp->left = new_tree_node(lexer, word);
		}
		else
			temp->right = new_tree_node(lexer, word);
		*end_ptr = temp->right;
	}
}

int	get_word(int lexer, char **cursor, \
									t_pars_tree **end_ptr, t_pars_tree **ptr)
{
	char	*word;
	int		new_lexer;

	new_lexer = 0;
	if (is_limited_control_operator(*cursor) || lexer == INT_MIN)
		return (lexer);
	word = read_word(&new_lexer, cursor);
	if (lexer == SUB_SHELL)
	{
		syntax_error(&lexer, word);
		return (INT_MIN);
	}
	if (word == NULL)
		error_handler(*cursor, NULL, 12);
	add_new_word(new_lexer, word, end_ptr, ptr);
	return (new_lexer);
}
