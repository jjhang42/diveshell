/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:12:50 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/08 15:20:18 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_paraset(unsigned long *cutoff, int *cutlim, int sign)
{
	int	size;

	size = sizeof(ssize_t) * sizeof(void *);
	*cutoff = (sign) * ((size_t)1 << (size - 1)) - (sign > 0);
	*cutlim = (*cutoff % 10) + '0';
}

static long	ft_any(int sign, unsigned long acc, int return_val)
{
	if (return_val != 0 && sign > 0)
		return (-1);
	if (return_val != 0 && sign < 0)
		return (0);
	return (sign * acc);
}

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	unsigned long	acc;
	unsigned long	cutoff;
	int				cutlim;
	int				sign;

	sign = 1;
	while (*nptr == ' ' || (9 <= *nptr && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	ft_paraset(&cutoff, &cutlim, sign);
	acc = 0;
	while ('0' <= *nptr && *nptr <= '9')
	{
		acc = acc * base + *nptr - '0';
		if (acc > cutoff || (acc == (cutoff / base) && *(nptr + 1) > cutlim))
			return (ft_any(sign, acc, 1));
		nptr++;
	}
	endptr = (char **)nptr;
	return (ft_any(sign, acc, 0));
}

int	ft_atoi(const char *str)
{
	return ((int)ft_strtol(str, (char **) NULL, 10));
}
