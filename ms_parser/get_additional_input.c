/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_additional_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:57:53 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/09 18:10:15 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

static int	is_syntax_error(int *lexer, t_pars_tree **end_ptr)
{
	if (end_ptr == NULL || *end_ptr == NULL || \
					((*end_ptr) != NULL && (*end_ptr)->type < 4))
		return (1);
	if ((*end_ptr) != NULL && (*end_ptr)->type == REDIRECTION)
	{
		syntax_error(lexer, ft_strdup("newline"));
		return (1);
	}
	return (0);
}

int	get_additional_input(int *lexer, \
									t_pars_tree **end_ptr, t_pars_tree **tree)
{
	char	*str;

	if (is_syntax_error(lexer, end_ptr) == 1)
		return (1);
	if (*lexer != INT_MIN && \
		((*end_ptr)->type == 64 || (*end_ptr)->type == 128))
	{
		rl_catch_signals = 0;
		str = readline(">");
		if (str == NULL)
			return (g_signal);
		while (*str == '\0')
		{
			free(str);
			str = readline(">");
		}
		minishell_parser(lexer, str, end_ptr, tree);
		free(str);
		rl_catch_signals = 1;
		return (0);
	}
	return (0);
}
