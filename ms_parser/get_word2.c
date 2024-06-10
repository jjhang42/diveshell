/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:07:19 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/09 18:10:32 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

static char	read_normal_string(int *lexer, char **cursor);
static char	read_quote_lev_string(int *lexer, char **cursor);

static char	read_quote_lev_string(int *lexer, char **cursor)
{
	char	end_char;
	char	flag;
	char	res;

	flag = 0;
	res = 0;
	end_char = token_start(lexer, **cursor);
	(*cursor)++;
	while (**cursor != '\0' && (**cursor) != end_char)
	{
		(*cursor)++;
		if (**cursor == end_char)
			flag = 1;
	}
	if (**cursor != '\0')
		(*cursor)++;
	else if (**cursor == '\0' && flag != 1)
		return (end_char);
	if (**cursor != '\0' && (**cursor == '\'' || **cursor == '\"'))
		res += read_quote_lev_string(lexer, cursor);
	else if (**cursor != '\0' && **cursor != ' ')
		res += read_normal_string(lexer, cursor);
	return (res);
}

static char	read_normal_string(int *lexer, char **cursor)
{
	char	end_char;
	int		res;

	res = 0;
	end_char = token_start(lexer, **cursor);
	while (**cursor != '\0' && \
			(**cursor) != end_char && word_symbol(**cursor) != 1 \
			&& (**cursor) != '\'' && (**cursor) != '\"')
		(*cursor)++;
	if (word_symbol(**cursor) == 1)
		return (res);
	if (**cursor != '\0' && ((**cursor) == '\"' || (**cursor) == '\''))
		res += read_quote_lev_string(lexer, cursor);
	else if (**cursor != '\0' && **cursor != ' ')
		res += read_normal_string(lexer, cursor);
	return (res);
}

static int	read_string_and_check(char end_char, char *str)
{
	int	flag;
	int	idx;
	int	cnt;

	flag = 0;
	cnt = 1;
	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] == end_char)
			cnt++;
		idx++;
	}
	if (cnt % 2 == 0 && (str[idx] == '\'' || str[idx] == '\"'))
	{
		cnt = 1;
		end_char = str[idx];
	}
	return (cnt % 2);
}

static char	*word_read_more(int *lexer, char end_char, char *word)
{
	char	*add_str;
	char	*read_str;
	int		cnt;
	int		tem;

	cnt = 1;
	tem = *lexer;
	*lexer = INT_MIN;
	while (cnt % 2 != 0)
	{
		read_str = readline(">");
		if (read_str == NULL || g_signal == 1)
			break ;
		cnt = read_string_and_check(end_char, read_str);
		add_str = ft_strjoin(word, read_str);
		free(word);
		free(read_str);
		word = add_str;
	}
	*lexer = tem;
	return (word);
}

char	*read_word(int *lexer, char **cursor)
{
	char	end_char;
	char	*word;
	int		res;

	word = *cursor;
	end_char = token_start(lexer, **cursor);
	if (end_char != ' ')
		res = read_quote_lev_string(lexer, cursor);
	else
		res = read_normal_string(lexer, cursor);
	if ((*cursor - word) == 0)
		return (NULL);
	word = ft_substr(word, 0, (*cursor) - word);
	if (res != 0)
		word = word_read_more(lexer, res, word);
	return (word);
}
