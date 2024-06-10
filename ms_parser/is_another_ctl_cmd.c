/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_another_ctl_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 01:02:25 by jjhang            #+#    #+#             */
/*   Updated: 2024/05/01 19:43:50 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

void	is_another_ctl_cmd(int *lexer, char **cursor)
{
	char	*str;
	int		val;

	if (*lexer == INT_MIN)
		return ;
	val = is_control_oprator(*cursor);
	if (val != 0)
	{
		str = ft_substr(*cursor, 0, val);
		syntax_error(lexer, str);
	}
}
