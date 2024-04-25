/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:30:08 by jjhang            #+#    #+#             */
/*   Updated: 2024/03/01 14:32:14 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*zero_src(size_t size)
{
	char	*src_ptr;

	src_ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (src_ptr == NULL)
		return (NULL);
	src_ptr[size] = '\0';
	return (src_ptr);
}

void	*ft_realloc(void *src, size_t size)
{
	char	*src_ptr;
	char	*dst_ptr;
	size_t	idx;

	src_ptr = (char *)src;
	if (src == NULL)
		src_ptr = zero_src(size);
	dst_ptr = (char *)malloc(size + 1);
	if (dst_ptr == NULL)
	{
		free(src_ptr);
		return (NULL);
	}
	idx = 0;
	while (idx < size)
	{
		dst_ptr[idx] = src_ptr[idx];
		idx++;
	}
	dst_ptr[idx] = 0;
	free(src_ptr);
	return ((void *)dst_ptr);
}
