/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:04:21 by inryu             #+#    #+#             */
/*   Updated: 2024/04/27 20:04:22 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_env(t_list *cpenv, int fd)
{
	t_list	*cur;

	cur = cpenv;
	while (cur)
	{
		if (ft_strchr(cur->content, '=') != NULL)
			ft_putendl_fd(cur->content, fd);
		cur = cur->next;
	}
	return (1);
}
