/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_preprocess.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:48:21 by jjhang            #+#    #+#             */
/*   Updated: 2024/05/31 11:46:54 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

DIR	*wildcard_preprocess(t_pars_tree *tree)
{
	char	*dirbuf;
	DIR		*ptr;

	if (tree == NULL)
		return (NULL);
	dirbuf = getcwd(NULL, 0);
	if (dirbuf == NULL)
		error_handler("wildcard", NULL, 12);
	ptr = opendir(dirbuf);
	free(dirbuf);
	return (ptr);
}

int	get_wildcard_type(char *str)
{
	int	res;
	int	idx;

	idx = 0;
	res = 0;
	while (str[idx] != '\0')
	{
		if (idx == 0 && str[idx] == '.')
		{
			res = 1;
			break ;
		}
		idx++;
	}
	return (res);
}
