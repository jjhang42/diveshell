/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bottom_up_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:23:07 by jjhang            #+#    #+#             */
/*   Updated: 2024/04/07 11:48:36 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

static void	recursive_parse(int *cnt, char *cmdline, char ***strs);

static char	symbol_check(char c)
{
	if (c == '\"')
		return ('\"');
	if (c == '\'')
		return ('\'');
	return (' ');
}

static void	token_len(char **cmdline, char **str, char start_symbol)
{
	if (**cmdline != '\0' && start_symbol != ' ')
		(*cmdline)++;
	(*str) = (*cmdline);
	while (**str != '\0' && !(**str == start_symbol))
		(*str)++;
}

static void	ft_gettoken(int *cnt, char start_symbol, \
						char *cmdline, char ***strs)
{
	char	*str;
	int		idx;

	if (*cmdline == '\0')
		return ;
	idx = (*cnt);
	start_symbol = symbol_check(start_symbol);
	str = cmdline;
	token_len(&cmdline, &str, start_symbol);
	if (0 < str - cmdline)
		(*cnt)++;
	recursive_parse(cnt, str, strs);
	if (0 < str - cmdline && (*strs)[idx] != NULL)
		(*strs)[idx] = ft_substr(cmdline, 0, str - cmdline);
}

static void	recursive_parse(int *cnt, char *cmdline, char ***strs)
{
	char	*str;

	str = cmdline;
	while ((*str != '\0') && (*str == ' ' || (9 <= *str && *str <= 13)))
		str++;
	if (*str == '\0')
	{
		*strs = (char **)malloc(sizeof(char *) * (*cnt + 1));
		if (strs == NULL)
			error_handler("malloc failed", NULL, 12);
		(*strs)[*cnt] = NULL;
		return ;
	}
	while ((*str != '\0') && (*str == ' ' || (9 <= *str && *str <= 13)))
		str++;
	ft_gettoken(cnt, *str, str, strs);
}

char	**bottom_up_parser(char *cmdline)
{
	char	**res;
	int		cnt;
	int		idx;

	cnt = 0;
	recursive_parse(&cnt, cmdline, &res);
	if (res[0] == NULL)
	{
		idx = 0;
		while (idx < cnt)
		{
			free(res[idx]);
			idx++;
		}
		free(res);
		res = NULL;
	}
	return (res);
}
