/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:23:07 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/09 19:14:11 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

int	get_cmd_list(int lexer, char **cursor, \
									t_pars_tree **end_ptr, t_pars_tree **tree)
{
	while (**cursor != '\0' && lexer != INT_MIN)
	{
		while (is_whitespace(**cursor) && **cursor != '\0')
			(*cursor)++;
		lexer = get_word(lexer, cursor, end_ptr, tree);
		while (is_whitespace(**cursor) && **cursor != '\0')
			(*cursor)++;
		lexer = get_subshell(lexer, cursor, end_ptr, tree);
		while (is_whitespace(**cursor) && **cursor != '\0')
			(*cursor)++;
		lexer = get_redirection(lexer, cursor, end_ptr, tree);
		while (is_whitespace(**cursor) && **cursor != '\0')
			(*cursor)++;
		lexer = get_pipe(lexer, cursor, end_ptr, tree);
		while (is_whitespace(**cursor) && **cursor != '\0')
			(*cursor)++;
		lexer = get_ctl_cmd(lexer, cursor, end_ptr, tree);
		is_another_ctl_cmd(&lexer, cursor);
	}
	return (lexer);
}

t_pars_tree	*minishell_parser(int *res, char *cmdline, \
								t_pars_tree **end_ptr, t_pars_tree **tree)
{
	int	lexer;

	lexer = 0;
	if (cmdline == NULL)
		return (NULL);
	if (cmdline[0] == '\0')
		return (NULL);
	lexer = get_cmd_list(lexer, &cmdline, end_ptr, tree);
	if (lexer != INT_MIN)
		get_additional_input(&lexer, end_ptr, tree);
	if (lexer == INT_MIN)
	{
		g_signal = 258;
		delete_tree_node(tree);
		*tree = NULL;
	}
	*res = lexer;
	return (*tree);
}
