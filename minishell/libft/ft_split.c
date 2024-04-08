/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 01:12:46 by jjhang            #+#    #+#             */
/*   Updated: 2023/10/23 16:24:33 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**all_free(char **s, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		free(s[idx]);
		idx++;
	}
	free(s);
	return (NULL);
}

static size_t	ft_countword(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			cnt++;
		while (*s && *s != c)
			s++;
	}
	return (cnt);
}

static char	*ft_strndup(char const *s, size_t n)
{
	size_t	idx;
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (n + 1));
	if (!ptr)
		return (NULL);
	idx = 0;
	while (idx < n)
	{
		ptr[idx] = s[idx];
		idx++;
	}
	ptr[idx] = '\0';
	return (ptr);
}

static char	**ft_strdiv(size_t size, char **res, char const *s, char c)
{
	size_t	idx;
	size_t	set_len;
	size_t	wrd_len;

	idx = 0;
	set_len = 0;
	while (res && idx < size)
	{
		wrd_len = 0;
		while (*(s + set_len) && *(s + set_len) == c)
			set_len++;
		while (*(s + wrd_len + set_len) && *(s + wrd_len + set_len) != c)
			wrd_len++;
		res[idx] = ft_strndup(s + set_len, wrd_len);
		if (!res[idx])
			return (all_free(res, idx));
		set_len += wrd_len;
		idx++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	size;

	size = ft_countword(s, c);
	res = (char **)malloc(sizeof(char *) * (size + 1));
	if (!res)
		return (NULL);
	res[size] = NULL;
	return (ft_strdiv(size, res, s, c));
}
