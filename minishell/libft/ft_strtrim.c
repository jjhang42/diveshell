/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:52:35 by jjhang            #+#    #+#             */
/*   Updated: 2023/10/24 19:35:15 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(int c, char *set)
{
	size_t	idx;

	idx = 0;
	while (*(set + idx))
	{
		if (c == set[idx])
			return (1);
		idx++;
	}
	return (0);
}

static char	*ft_strrstr(char *s, char *set)
{
	char	*last;
	size_t	idx;

	last = s;
	while (*s)
	{
		idx = 0;
		if (*s && !ft_isset(*s, set))
			last = s;
		s++;
	}
	return (last);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*srt_ptr;
	char	*last;
	size_t	len;

	srt_ptr = (char *)s1;
	while (*srt_ptr && ft_isset(*srt_ptr, (char *)set))
		srt_ptr++;
	last = ft_strrstr(srt_ptr, (char *)set);
	len = (unsigned long long)last - (unsigned long long)srt_ptr + 1;
	last = (char *)malloc(sizeof(char) * (len + (len != 1)));
	if (!last)
		return (NULL);
	ft_strlcpy(last, srt_ptr, len + (len != 1));
	return (last);
}
