/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:28:20 by jjhang            #+#    #+#             */
/*   Updated: 2023/10/24 11:46:48 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			idx;

	ptr = (unsigned char *)malloc(size * count);
	if (!ptr)
		return (NULL);
	idx = 0;
	while (idx < count * size)
	{
		ptr[idx] = 0;
		idx++;
	}
	return ((void *)ptr);
}
