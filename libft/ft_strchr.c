/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:04:03 by jjhang            #+#    #+#             */
/*   Updated: 2023/10/28 01:20:51 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	tem;

	ptr = (char *)s;
	tem = (char)c;
	while (*ptr && *ptr != tem)
		ptr++;
	if (*ptr == tem)
		return (ptr);
	return (NULL);
}
