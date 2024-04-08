/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_datatype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:54:00 by jjhang            #+#    #+#             */
/*   Updated: 2023/12/22 17:51:22 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 'x' bits how to make zero -> &= ~(1 << x);
static inline void	integer_flagset(t_format *data, char c)
{
	if (flag_manager(data, '.', 'c'))
		flag_manager(data, '0', 'd');
	if ((*data).data.i < 0)
	{
		(*data).sign = -1;
		(*data).data.i *= -1;
	}
	(*data).va_len += ft_getwidth_lld((*data).data.lld, ft_isconv(c));
	if (((*data).sign == -1 || flag_manager(data, '+', 'c') || \
		flag_manager(data, ' ', 'c')))
	{
		if ((*data).sign == -1 || flag_manager(data, '+', 'c'))
			flag_manager(data, ' ', 'd');
		(*data).s_lev = 1;
	}
}

static inline void	hex_flagset(t_format *data, char c)
{
	if (flag_manager(data, '.', 'c'))
		flag_manager(data, '0', 'd');
	if (c == 'p')
	{
		flag_manager(data, '#', 'n');
		(*data).va_len = ft_getwidth_szt((*data).data.zu, 16);
	}
	if (c == 'x' || c == 'X')
		(*data).va_len = ft_getwidth_szt((*data).data.zu, 16);
	if (flag_manager(data, '#', 'c') && (*data).conv != 'p' && \
		(*data).data.zu == 0)
		flag_manager(data, '#', 'd');
	if (flag_manager(data, '#', 'c'))
		(*data).s_lev += 2;
}

static inline void	string_flagset(t_format *data)
{
	(*data).va_len = ft_strlen((*data).data.v);
	if (flag_manager(data, '.', 'c'))
	{
		if ((*data).va_len < (*data).prec)
			(*data).prec = (*data).va_len;
		(*data).va_len = (*data).prec;
	}
	if (!flag_manager(data, '.', 'c'))
		(*data).prec = (*data).va_len;
}

static inline void	ui_flagset(t_format *data, char c)
{
	(*data).va_len = ft_getwidth_szt((*data).data.ui, ft_isconv(c));
	if (flag_manager(data, '.', 'c'))
		flag_manager(data, '0', 'd');
}

void	format_set(t_format *data)
{
	char	c;

	c = (*data).conv;
	if (flag_manager(data, '-', 'c'))
		flag_manager(data, '0', 'd');
	if (flag_manager(data, '+', 'c'))
		flag_manager(data, ' ', 'd');
	if (c == 'd' || (c == 'i'))
		integer_flagset(data, c);
	if (c == 'p' || c == 'x' || c == 'X')
		hex_flagset(data, c);
	if (c == 's')
		string_flagset(data);
	if (c == 'c' || c == '%')
		(*data).va_len += 1;
	if (c == 'u')
		ui_flagset(data, c);
	if ((*data).prec < (*data).va_len && (c != 's' && (*data).data.lld != 0))
		(*data).prec = (*data).va_len;
}
