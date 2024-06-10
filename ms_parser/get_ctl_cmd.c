/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ctl_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:28:10 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/09 19:13:05 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

int	get_ctl_cmd(int lexer, char **cursor, \
									t_pars_tree **end_ptr, t_pars_tree **ptr)
{
	t_pars_tree	*temp;
	char		*ctl_cmd;

	if (is_control_cmd(*cursor) == 0 || lexer == INT_MIN)
		return (lexer);
	ctl_cmd = ft_substr(*cursor, 0, 2);
	if (ctl_cmd == NULL)
		error_handler(*cursor, NULL, 12);
	(*cursor) += 2;
	if (*ptr == NULL || lexer == 64 || lexer == 128)
		syntax_error(&lexer, ctl_cmd);
	else
	{
		lexer = CTL_CMD;
		temp = new_tree_node(lexer, ctl_cmd);
		(*ptr) = add_tree_front(*ptr, temp);
		*end_ptr = temp;
	}
	return (lexer);
}
