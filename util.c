/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:04:52 by inryu             #+#    #+#             */
/*   Updated: 2024/04/27 20:04:57 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*ms_lstnew(void *content)
{
	t_list	*ret;

	ret = ft_calloc(1, sizeof(t_list));
	if (!ret)
		exit(1);
	ret->content = content;
	return (ret);
}

t_list	*ft_ddup(char **env)
{
	t_list	*head;
	t_list	*new;
	char	*s;
	int		i;

	new = NULL;
	i = 0;
	while (env[i])
	{
		s = ft_strdup(env[i]);
		if (new == NULL)
		{
			new = ft_lstnew(s);
			head = new;
		}
		else
		{
			new = ft_lstnew(s);
			ft_lstadd_back(&head, new);
		}
		i++;
	}
	return (head);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}