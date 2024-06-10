/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_env_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:50:47 by jjhang            #+#    #+#             */
/*   Updated: 2024/05/28 21:41:27 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

void	delete_env_node(t_env_lst *node)
{
	if (node == NULL)
		return ;
	if (node->content != NULL)
		free(node->content);
	if (node->name != NULL)
		free(node->name);
	free(node);
}
