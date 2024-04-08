/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:27:36 by jjhang            #+#    #+#             */
/*   Updated: 2024/02/27 14:27:09 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pathcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (s2[idx] != '\0' && s2[idx] != '=')
	{
		if (s1[idx] != s2[idx])
			break ;
		idx++;
	}
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}

char	*ft_getenv(char *envp[], char *name)
{
	char	*arr;
	int		idx;
	int		len;

	idx = 0;
	while (envp[idx] != NULL)
	{
		if (!ft_pathcmp(name, envp[idx]))
			break ;
		idx++;
	}
	if (envp[idx] == NULL)
		return (NULL);
	len = ft_strlen(name);
	arr = ft_substr(envp[idx], len, ft_strlen(envp[idx]));
	if (arr == NULL)
	{
		perror("Error: malloc failed!\n");
		exit (12);
	}
	return (arr);
}
