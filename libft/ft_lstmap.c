/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:47:39 by jjhang            #+#    #+#             */
/*   Updated: 2023/10/23 16:24:01 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tem;
	void	*f_val;

	new = NULL;
	while (lst != NULL)
	{
		f_val = f(lst->content);
		tem = ft_lstnew(f_val);
		if (tem == NULL)
		{
			ft_lstclear(&new, del);
			del(f_val);
			return (NULL);
		}
		ft_lstadd_back(&new, tem);
		lst = lst->next;
	}
	return (new);
}
