/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:03:54 by jjhang            #+#    #+#             */
/*   Updated: 2024/02/27 13:19:52 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int	check_flag(t_format *data, char n, char mode)
{
	if (mode == 'd' && ((*data).flag & n) == n)
	{
		(*data).flag -= n;
		return (1);
	}
	if (mode == 'n' && ((*data).flag & n) != n)
	{
		(*data).flag += n;
		return (1);
	}
	if (mode == 'c' && ((*data).flag & n) == n)
		return (1);
	return (0);
}

int	flag_manager(t_format *data, char c, char mode)
{
	if (c == '-')
		return (check_flag(data, 1, mode));
	if (c == '+')
		return (check_flag(data, 2, mode));
	if (c == '#')
		return (check_flag(data, 4, mode));
	if (c == ' ')
		return (check_flag(data, 8, mode));
	if (c == '0')
		return (check_flag(data, 16, mode));
	if (c == '.')
		return (check_flag(data, 32, mode));
	if (c == 'f')
		return (check_flag(data, 64, mode));
	return (0);
}

int	init_flag_n_format(int fd, t_format *data)
{
	(*data).flag = 0;
	(*data).width = 0;
	(*data).prec = 1;
	(*data).conv = '\0';
	(*data).va_len = 0;
	(*data).data.lld = 0;
	(*data).sign = 1;
	(*data).s_lev = 0;
	(*data).fd = fd;
	return (1);
}
