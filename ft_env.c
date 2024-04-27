/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:19:17 by codespace         #+#    #+#             */
/*   Updated: 2024/04/27 15:19:18 by codespace        ###   ########.fr       */
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
