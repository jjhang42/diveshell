/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:16:26 by jjhang            #+#    #+#             */
/*   Updated: 2023/10/23 16:23:51 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tem;
	t_list	*cur;

	if (*lst == NULL)
		return ;
	cur = *lst;
	tem = NULL;
	while (cur != NULL)
	{
		tem = cur->next;
		ft_lstdelone(cur, (*del));
		cur = tem;
	}
	*lst = NULL;
}
