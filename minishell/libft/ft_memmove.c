/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:01:23 by jjhang            #+#    #+#             */
/*   Updated: 2023/10/23 16:24:24 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	size_t			idx;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	if (dst_ptr < src_ptr)
		ft_memcpy(dst, src, len);
	if (dst_ptr > src_ptr)
	{
		idx = 0;
		while (idx < len)
		{
			dst_ptr[len - idx - 1] = src_ptr[len - idx - 1];
			idx++;
		}
	}
	return (dst);
}
