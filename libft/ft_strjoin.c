/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:13:29 by jjhang            #+#    #+#             */
/*   Updated: 2024/02/28 20:03:46 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_size;
	size_t	s2_size;
	char	*res_ptr;

	s1_size = 0;
	while (s1 != NULL && s1[s1_size] != '\0')
		s1_size++;
	s2_size = 0;
	while (s2 != NULL && s2[s2_size] != '\0')
		s2_size++;
	res_ptr = (char *)malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (!res_ptr)
		return (NULL);
	if (s1 != NULL)
		ft_memcpy(res_ptr, s1, s1_size);
	if (s2 != NULL)
		ft_memcpy(res_ptr + s1_size, s2, s2_size);
	res_ptr[s1_size + s2_size] = '\0';
	return (res_ptr);
}
