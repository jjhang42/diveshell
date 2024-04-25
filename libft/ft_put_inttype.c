/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_inttype.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:50:06 by jjhang            #+#    #+#             */
/*   Updated: 2024/02/27 13:22:46 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printint_precpart(t_format *data, size_t nbr, int size, int check)
{
	int	re_val;

	re_val = 0;
	if ((*data).prec != 0)
	{
		if (flag_manager(data, '0', 'c'))
		{
			check = ft_setfield(data, size - (*data).prec - (*data).s_lev, 1);
			if (check == -1)
				return (-1);
			re_val += check;
		}
		else
		{
			check = ft_setfield(data, (*data).prec - (*data).va_len, 1);
			if (check == -1)
				return (-1);
			re_val += check;
		}
		check = ft_putnbr_int(data, nbr, 10);
		if (check == -1)
			return (-1);
		re_val += check;
	}	
	return (re_val);
}

static int	printint_signpart(t_format *data, size_t nbr, int size)
{
	int	re_val;
	int	check;
	int	sign;

	re_val = 0;
	sign = (*data).sign;
	if (sign == -1 || flag_manager(data, '+', 'd'))
	{
		check = ft_putchar_int(data->fd, (sign >= 0) * '+' + (sign < 0) * '-');
		if (check == -1)
			return (-1);
		re_val += check;
	}
	if (flag_manager(data, ' ', 'c'))
	{
		check = ft_putchar_int(data->fd, ' ');
		if (check == -1)
			return (-1);
		re_val += check;
	}
	check = printint_precpart(data, nbr, size, 0);
	if (check == -1)
		return (-1);
	re_val += check;
	return (re_val);
}

int	put_inttype(t_format *data, ssize_t nbr, int size, int check)
{
	int	re_val;

	re_val = 0;
	if (flag_manager(data, '-', 'c'))
	{
		check = printint_signpart(data, nbr, size);
		if (check == -1)
			return (-1);
		re_val += check;
	}
	if (!flag_manager(data, '0', 'c'))
	{
		check = ft_setfield(data, size - (*data).prec - (*data).s_lev, 0);
		if (check == -1)
			return (-1);
		re_val += check;
	}
	if (!flag_manager(data, '-', 'c'))
	{
		re_val = printint_signpart(data, nbr, size);
		if (check == -1)
			return (-1);
		re_val += check;
	}
	return (re_val);
}
