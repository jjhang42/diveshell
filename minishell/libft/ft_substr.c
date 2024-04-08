/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:23:00 by jjhang            #+#    #+#             */
/*   Updated: 2023/11/06 22:18:34 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;
	size_t	idx;

	s_len = ft_strlen(s);
	if (s_len < start)
	{
		start = 0;
		len = 0;
	}
	if (s_len < len + start)
		len = s_len - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		ptr[idx] = s[start + idx];
		idx++;
	}
	ptr[idx] = '\0';
	return (ptr);
}
