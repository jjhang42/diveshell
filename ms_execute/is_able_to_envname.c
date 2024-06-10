/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_able_to_envname.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:39:57 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/07 22:02:18 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

int	is_able_to_envname(char *name)
{
	int	flag;
	int	idx;

	idx = 0;
	flag = 0;
	while (name[idx] != '\0' && name[idx] != '=')
	{
		if (ft_isdigit(name[idx]) == 1)
		{
			flag = 0;
			if (idx == 0)
				flag = 1;
		}
		else if (ft_isalpha(name[idx]) == 1)
			flag = 0;
		else
			flag = 1;
		if (flag == 1)
			break ;
		idx++;
	}
	if (idx == 0)
		flag = 1;
	return (flag);
}
