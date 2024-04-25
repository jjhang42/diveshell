/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:53:47 by jjhang            #+#    #+#             */
/*   Updated: 2024/02/27 14:30:40 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_file	*ft_lstfind(t_file **head, int fd)
{
	t_file	*tem;
	t_file	*new;

	tem = *head;
	while (tem != NULL)
	{
		if (fd == tem->fd)
			return (tem);
		tem = tem->next;
	}
	new = (t_file *)malloc(sizeof(t_file));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->data = (char *)malloc(1);
	if (new->data == NULL)
	{
		free(new);
		new = NULL;
		return (NULL);
	}
	new->data[0] = '\0';
	new->next = *head;
	*head = new;
	return (new);
}
