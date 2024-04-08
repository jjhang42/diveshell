/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_chartype.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:51:00 by jjhang            #+#    #+#             */
/*   Updated: 2024/02/27 13:21:25 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_chartype(t_format *data, char c, int size)
{
	int	re_val;
	int	check;

	re_val = 0;
	if (flag_manager(data, '-', 'c'))
	{
		check = ft_putchar_int(data->fd, c);
		if (check == -1)
			return (-1);
		re_val += check;
	}
	check = ft_setfield(data, size - (*data).va_len, 0);
	if (check == -1)
		return (-1);
	re_val += check;
	if (!flag_manager(data, '-', 'c'))
	{
		check = ft_putchar_int(data->fd, c);
		if (check == -1)
			return (-1);
		re_val += check;
	}
	return (re_val);
}
