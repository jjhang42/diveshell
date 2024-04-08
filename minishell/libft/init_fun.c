/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:35:29 by jjhang            #+#    #+#             */
/*   Updated: 2024/02/27 13:23:15 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	init_data1(t_format *data, char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0' && ft_isconv(str[idx]) == 0)
	{
		if (str[idx] == '-' && ((*data).flag & (char)1) != 1)
			(*data).flag += 1;
		if (str[idx] == '+' && ((*data).flag & (char)2) != 2)
			(*data).flag += 2;
		if (str[idx] == '#' && ((*data).flag & (char)4) != 4)
			(*data).flag += 4;
		if (str[idx] == ' ' && ((*data).flag & (char)8) != 8)
			(*data).flag += 8;
		if (str[idx] == '0' && ((*data).flag & (char)16) != 16)
			(*data).flag += 16;
		if ('1' <= str[idx] && str[idx] <= '9')
			break ;
		if (str[idx] == '.')
			break ;
		idx++;
	}
	return (idx);
}

static int	swappoint(t_format *data, char *str, char flag_nbr, int *pos)
{
	char	*tem;
	int		res;

	(*data).flag += flag_nbr;
	res = (int)ft_strtol(str, &tem, 10);
	*pos = *pos + (tem - str);
	return (res);
}

int	init_data2(t_format *data, char *str)
{
	int		idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if ('1' <= str[idx] && str[idx] <= '9' && ((*data).flag & 64) != 64)
			(*data).width = swappoint(data, &str[idx], 64, &idx);
		if (str[idx] == '.')
		{
			idx++;
			(*data).prec = swappoint(data, &str[idx], 32, &idx);
		}
		if (ft_isconv(str[idx]))
		{
			(*data).conv = str[idx];
			idx++;
			break ;
		}
		idx++;
	}
	return (idx);
}

int	init_varg(t_format *data, va_list *arg_ptr)
{
	char	c;

	c = (*data).conv;
	if (c == 'c')
		(*data).data.c = va_arg(*arg_ptr, int);
	if (c == '%')
		(*data).data.c = '%';
	if (c == 'd' || c == 'i')
		(*data).data.i = va_arg(*arg_ptr, int);
	if (c == 'x' || c == 'X' || c == 'u')
		(*data).data.ui = va_arg(*arg_ptr, unsigned int);
	if (c == 's')
		(*data).data.v = va_arg(*arg_ptr, char *);
	if (c == 'p')
		(*data).data.zu = va_arg(*arg_ptr, unsigned long long);
	format_set(data);
	return (0);
}
