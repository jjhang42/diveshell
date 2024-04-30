/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:01:08 by codespace         #+#    #+#             */
/*   Updated: 2024/04/27 20:04:37 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	del(void *content)
{
	free(content);
}

int ft_find_envkey(char *key, t_list *cpenv)
{
	t_list	*cur;
	t_list	*pre;
	size_t	key_len;

	cur = cpenv;
	pre = NULL;
	key_len = ft_strlen(key);
	while (cur)
	{
		if (ft_strncmp(key, cur->content, key_len) == 0 && cur->content[key_len] == '=')
		{
			if (pre == NULL)
				cpenv = cur->next;
			else
				pre->next = cur->next;
			ft_lstdelone(cur, (*del));
		}
		pre = cur;
		cur = cur->next;
	}
	return (-1);
}

void	ft_valid_key(char *key)
{
	int i;

	i = 0;
	if (ft_strlen(key) == 0)
		return (0);
	while (key[i])
	{
		if (ft_isdigit(key[0]))
			return (0);
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int ft_unset(t_pars_tree *cmd, t_list cpenv, int fd)
{
	if (cmd->cmd && cmd->redir_flag == 0)
	{
		if (ft_valid_key(cmd->cmd[1]))
			ft_find_envkey(cmd->cmd[1], cpenv);
		else
			ft_putendl_fd("bash: unset: `a=': not a valid identifier", 2);
			return (-1);
	}
	open(fd, O_WRONLY);
	return (1);
}