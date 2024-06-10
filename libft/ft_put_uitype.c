/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uitype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:52:45 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/08 23:31:32 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printui_precpart(t_format *data, size_t nbr, int size, int check)
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
		check = ft_putnbr_szt(data, nbr, ft_isconv((*data).conv));
		if (check == -1)
			return (-1);
		re_val += check;
	}
	return (re_val);
}

static int	printui_signpart(t_format *data, size_t nbr, int size, int check)
{
	char	*add;
	int		re_val;

	if ((*data).conv == 'X')
		add = "0X";
	else
		add = "0x";
	re_val = 0;
	if (flag_manager(data, '#', 'c'))
	{
		check = ft_putstr_int(data, add, 2);
		if (check == -1)
			return (-1);
		re_val += check;
	}
	check = printui_precpart(data, nbr, size, 0);
	if (check == -1)
		return (-1);
	re_val += check;
	return (re_val);
}

int	put_uinttype(t_format *data, size_t nbr, int size, int check)
{
	int	re_val;

	re_val = 0;
	if (flag_manager(data, '-', 'c'))
	{
		check = printui_signpart(data, nbr, size, 0);
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
		check = printui_signpart(data, nbr, size, 0);
		if (check == -1)
			return (-1);
		re_val += check;
	}
	return (re_val);
}
