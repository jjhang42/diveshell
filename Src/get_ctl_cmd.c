/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ctl_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:28:10 by jjhang            #+#    #+#             */
/*   Updated: 2024/04/24 16:19:20 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

void	get_ctl_cmd(int *lexer, char **cursor, t_pars_tree **ptr)
{
	t_pars_tree	*temp;
	char		*ctl_cmd;

	 if (is_control_cmd(*cursor) == 0)
	 	return ;
	ctl_cmd = ft_substr(*cursor, 0, 2);
	if (ctl_cmd == NULL)
		error_handler(*cursor, NULL, 12);
	(*cursor) += 2;
	*lexer = 128;
	if (*ptr == NULL)
		syntax_error(ctl_cmd);
	else
	{
		temp = new_tree_node(*lexer, ctl_cmd);
		(*ptr) = add_tree_front(*ptr, temp);
	}
}
