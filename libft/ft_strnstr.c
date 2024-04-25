/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:07:41 by jjhang            #+#    #+#             */
/*   Updated: 2023/10/24 11:46:14 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	size;
	size_t	idx;

	size = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (size < len && *(haystack + size))
	{
		idx = 0;
		while (*(haystack + size + idx) == *(needle + idx) && idx < len - size)
		{
			idx++;
			if (!(*(needle + idx)))
				return ((char *)(haystack + size));
		}
		size++;
	}
	return (0);
}
