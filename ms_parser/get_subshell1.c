/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_subshell1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:47:49 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/10 00:12:34 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

static char	*get_additional_string(int *op_count, int *cl_count, char *word)
{
	char	*str;
	char	*res;
	int		idx;

	while (*op_count - *cl_count != 0)
	{
		idx = 0;
		str = readline(">");
		if (str == NULL)
			break ;
		while (str[idx] != '\0')
		{
			if (str[idx] == '(')
				(*op_count)++;
			if (str[idx] == ')')
				(*cl_count)++;
			idx++;
		}
		res = ft_strjoin(word, str);
		free(word);
		free(str);
		word = res;
	}
	return (word);
}

static int	read_subshell(char **word, char **cursor)
{
	int	open_count;
	int	close_count;

	open_count = 1;
	close_count = 0;
	while (**cursor != '\0' && (open_count - close_count))
	{
		if (**cursor == '(')
			open_count++;
		if (**cursor == ')')
			close_count++;
		(*cursor)++;
	}
	if (open_count - close_count != 0)
	{
		rl_catch_signals = 0;
		*word = ft_strdup(*word);
		*word = get_additional_string(&open_count, &close_count, *word);
		rl_catch_signals = 1;
	}
	else
		*word = ft_substr(*word, 1, (*cursor) - *word - 2);
	return (open_count - close_count);
}

void	check_subshell(t_pars_tree *tree)
{
	if (tree == NULL)
		return ;
	if (tree->type == REDIRECTION && \
		ft_strcmp(tree->word, "<<") == 0 && tree->left != NULL)
		tree->left->type = FILENAME;
	if (tree->type == REDIRECTION && \
		ft_strcmp(tree->word, "<<") != 0 && tree->left != NULL)
		tree->left->type = JUST_FILENAME;
	if ((tree->type & SUB_SHELL) != SUB_SHELL)
		tree->type += SUB_SHELL;
	if (tree->left != NULL)
		check_subshell(tree->left);
	if (tree->right != NULL)
		check_subshell(tree->right);
}

int	get_subshell(int lexer, char **cursor, \
								t_pars_tree **end_ptr, t_pars_tree **tree)
{
	t_pars_tree	*sub_tree;
	char		*word;
	int			flag;
	int			tem;

	if (tree == NULL)
		return (lexer);
	if (**cursor != '(' || lexer == INT_MIN)
		return (lexer);
	if (lexer == WORD || lexer == SUB_SHELL)
	{
		syntax_error(&lexer, ft_strdup("("));
		return (INT_MIN);
	}
	word = *cursor;
	(*cursor)++;
	flag = read_subshell(&word, cursor);
	if (lexer != INT_MIN)
		lexer = SUB_SHELL;
	sub_tree = NULL;
	tem = 0;
	sub_tree = minishell_parser(&tem, word, end_ptr, &sub_tree);
	free (word);
	check_subshell(sub_tree);
	add_new_subshell(sub_tree, tree);
	return (lexer);
}
