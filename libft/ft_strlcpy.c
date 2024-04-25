/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:28:08 by jjhang            #+#    #+#             */
/*   Updated: 2023/10/24 11:46:03 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	src_len;

	idx = 0;
	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	while (src[idx] && idx < dstsize - 1)
	{
		dst[idx] = src[idx];
		idx++;
	}
	if (0 < dstsize)
		dst[idx] = '\0';
	return (src_len);
}
