/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_control_oprator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:02:14 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/09 20:09:39 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

int	is_control_oprator(char *ptr)
{
	if (ft_strncmp("||", ptr, 2) == 0)
		return (2);
	if (ft_strncmp("&&", ptr, 2) == 0)
		return (2);
	if (ft_strncmp("&", ptr, 1) == 0)
		return (1);
	if (ft_strncmp(";;&", ptr, 3) == 0)
		return (3);
	if (ft_strncmp(";;", ptr, 2) == 0)
		return (2);
	if (ft_strncmp(";&", ptr, 2) == 0)
		return (2);
	if (ft_strncmp(";", ptr, 1) == 0)
		return (1);
	if (ft_strncmp("|&", ptr, 2) == 0)
		return (2);
	if (ft_strncmp("|", ptr, 1) == 0)
		return (1);
	return (0);
}

int	is_limited_control_operator(char *ptr)
{
	if (ft_strncmp("||", ptr, 2) == 0)
		return (1);
	if (ft_strncmp("&&", ptr, 2) == 0)
		return (1);
	if (ft_strncmp("|", ptr, 1) == 0)
		return (1);
	if (ft_strncmp("(", ptr, 1) == 0)
		return (1);
	if (ft_strncmp(")", ptr, 1) == 0)
		return (1);
	if (ft_strncmp("&", ptr, 1) == 0)
		return (1);
	if (ft_strncmp(";", ptr, 1) == 0)
		return (1);
	if (*ptr == '<')
		return (1);
	if (*ptr == '>')
		return (1);
	return (0);
}
