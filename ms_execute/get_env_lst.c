/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:04:52 by inryu             #+#    #+#             */
/*   Updated: 2024/05/28 21:45:23 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

t_env_lst	*ft_env_lstlast(t_env_lst *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_env_lstadd_back(t_env_lst **lst, t_env_lst *new)
{
	t_env_lst	*tem;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tem = ft_env_lstlast(*lst);
		tem->next = new;
	}
}

t_env_lst	*ft_env_lstnew(char *name, char *content)
{
	t_env_lst	*new;

	new = ft_calloc(1, sizeof(t_env_lst));
	if (new == NULL)
		error_handler("diveshell", NULL, 12);
	new->name = name;
	new->content = content;
	return (new);
}

t_env_lst	*ft_env_splitnew(char *string)
{
	t_env_lst	*env;
	int			flag;
	int			len;
	int			max;

	flag = 0;
	if (string == NULL)
		return (NULL);
	max = ft_strlen(string);
	len = 0;
	while (string[len] != '\0' && string[len] != '=')
	{
		if (string[len + 1] == '=')
			flag = 1;
		len++;
	}
	env = ft_env_lstnew(NULL, NULL);
	env->name = ft_substr(string, 0, len);
	if (flag == 1)
		env->content = ft_substr(string, len + 1, max - len + 1);
	return (env);
}

t_env_lst	*get_env_lst(char *envp[])
{
	t_env_lst	*head;
	t_env_lst	*new;
	int			idx;

	new = NULL;
	head = NULL;
	idx = 0;
	while (envp[idx] != NULL)
	{
		new = ft_env_splitnew(envp[idx]);
		if (head == NULL)
			head = new;
		else
			ft_env_lstadd_back(&head, new);
		idx++;
	}
	return (head);
}
