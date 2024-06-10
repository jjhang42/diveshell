/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_strtype.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:02:48 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/08 23:30:08 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printstr_part(t_format *data, char *str)
{
	int	re_val;
	int	check;

	re_val = 0;
	if (str == NULL)
	{
		check = ft_putstr_int(data, "(null)", (*data).prec);
		if (check == -1)
			return (-1);
		re_val += check;
	}
	else
	{
		check = ft_putstr_int(data, str, (*data).prec);
		if (check == -1)
			return (-1);
		re_val += check;
	}
	return (re_val);
}

int	put_strtype(t_format *data, char *str, int size)
{
	int	re_val;
	int	check;

	re_val = 0;
	if (flag_manager(data, '-', 'c'))
	{
		check = printstr_part(data, str);
		if (check == -1)
			return (-1);
		re_val += check;
	}
	check = ft_setfield(data, size - (*data).prec, 0);
	if (check == -1)
		return (-1);
	re_val += check;
	if (!flag_manager(data, '-', 'c'))
	{
		check = printstr_part(data, str);
		if (check == -1)
			return (-1);
		re_val += check;
	}
	return (re_val);
}
