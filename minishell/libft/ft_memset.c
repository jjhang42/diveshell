/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:24:39 by jjhang            #+#    #+#             */
/*   Updated: 2023/10/23 16:24:23 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_ptr;
	size_t			idx;

	idx = 0;
	b_ptr = (unsigned char *)b;
	while (idx < len)
	{
		b_ptr[idx] = (unsigned char)c;
		idx++;
	}
	return (b);
}
