/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:25:14 by jjhang            #+#    #+#             */
/*   Updated: 2023/10/24 11:46:12 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*last;
	char	tem;

	ptr = (char *)s;
	tem = (char)c;
	last = NULL;
	while (*ptr)
	{
		if (*ptr == tem)
			last = ptr;
		ptr++;
	}
	if (*ptr == tem)
		return (ptr);
	return (last);
}
