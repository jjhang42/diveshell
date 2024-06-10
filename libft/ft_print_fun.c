/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:13:29 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/08 23:31:10 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_int(int fd, char c)
{
	int	len;

	len = write (fd, &c, 1);
	return (len);
}

int	ft_setfield(t_format *data, int size, int pos)
{
	int		re_val;
	int		check;
	int		idx;
	char	c;

	idx = 0;
	re_val = 0;
	if ((flag_manager(data, '0', 'c') || flag_manager(data, '.', 'c')) && \
		pos == 1)
		c = '0';
	else if (flag_manager(data, 'f', 'c'))
		c = ' ';
	while (idx < size)
	{
		check = ft_putchar_int(data->fd, c);
		if (check == -1)
			return (-1);
		re_val += check;
		idx++;
	}
	return (re_val);
}

int	ft_putnbr_szt(t_format *data, size_t nbr, int base)
{
	char	*num;
	int		re_val;
	int		check;

	if ((*data).conv == 'X')
		num = "0123456789ABCDEF";
	else
		num = "0123456789abcdef";
	re_val = 0;
	if (nbr / base == 0)
	{
		check = ft_putchar_int(data->fd, num[nbr % base]);
		return (check);
	}
	check = ft_putnbr_szt(data, nbr / base, base);
	if (check == -1)
		return (-1);
	re_val += check;
	check = ft_putchar_int(data->fd, num[nbr % base]);
	if (check == -1)
		return (-1);
	re_val += check;
	return (re_val);
}

int	ft_putnbr_int(t_format *data, ssize_t nbr, int base)
{
	char	*num;
	int		re_val;
	int		check;

	num = "0123456789abcdef";
	re_val = 0;
	if (nbr == -2147483648)
	{
		re_val = write (1, "-2147483648", 11);
		return (re_val);
	}
	if (nbr / base == 0)
	{
		check = ft_putchar_int(data->fd, num[nbr % base]);
		return (check);
	}
	check = ft_putnbr_int(data, nbr / base, base);
	if (check == -1)
		return (-1);
	re_val += check;
	check = ft_putchar_int(data->fd, num[nbr % base]);
	if (check == -1)
		return (-1);
	re_val += check;
	return (re_val);
}

int	ft_putstr_int(t_format *data, char *str, int size)
{
	int	re_val;
	int	idx;
	int	check;

	idx = 0;
	re_val = 0;
	while (idx < size)
	{
		check = write (data->fd, &str[idx], 1);
		if (check == -1)
			return (-1);
		re_val += check;
		idx++;
	}
	return (re_val);
}
