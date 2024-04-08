/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 23:52:49 by jjhang            #+#    #+#             */
/*   Updated: 2024/02/27 15:23:47 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_isconv(char c)
{
	if (c == 'c')
		return (1);
	if (c == '%')
		return (1);
	if (c == 's')
		return (8);
	if (c == 'd' || c == 'i' || c == 'u')
		return (10);
	if (c == 'x' || c == 'X' || c == 'p')
		return (16);
	return (0);
}

int	ft_getwidth_szt(size_t nbr, size_t base)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len++;
	while (nbr != 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

int	ft_getwidth_lld(ssize_t nbr, size_t base)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	if (nbr == 0)
		len++;
	while (nbr != 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}
