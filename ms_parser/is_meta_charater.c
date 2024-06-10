/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_meta_charater.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:59:50 by jjhang            #+#    #+#             */
/*   Updated: 2024/04/24 18:26:03 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

int	is_meta_charater(char c)
{
	if (c == '|')
		return (1);
	if (c == '&')
		return (1);
	if (c == '(')
		return (1);
	if (c == ')')
		return (1);
	if (c == '<')
		return (1);
	if (c == '>')
		return (1);
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	return (0);
}
