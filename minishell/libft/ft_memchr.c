/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:07:22 by jjhang            #+#    #+#             */
/*   Updated: 2023/10/24 11:38:39 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	chr;
	char			*str;

	str = (char *)s;
	chr = (unsigned char)c;
	while (n != 0)
	{
		if ((unsigned char)*str == chr)
			return (str);
		str++;
		n--;
	}
	return (0);
}
