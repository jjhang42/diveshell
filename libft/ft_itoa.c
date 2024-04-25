/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:04:14 by jjhang            #+#    #+#             */
/*   Updated: 2023/10/31 00:35:29 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checklen(int n, size_t *us_nbr, int *sign)
{
	size_t	num;
	int		len;

	len = 0;
	if (n < 1)
	{
		*sign = -1;
		*us_nbr = (size_t)n * -1;
		len++;
	}
	else
		*us_nbr = (size_t)n;
	num = *us_nbr;
	while (num)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

static char	*ft_setnum(size_t n, int sign, int len, char *res)
{
	int	idx;

	idx = 0;
	while (n != 0)
	{
		res[len - idx - 1] = (n % 10) + '0';
		n = n / 10;
		idx++;
	}
	if (sign == -1)
		res[0] = '-';
	res[len] = '\0';
	return (res);
}

char	*ft_setzero(char *str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	us_nbr;
	int		sign;
	int		len;

	sign = 1;
	len = ft_checklen(n, &us_nbr, &sign);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (n == 0)
		return (ft_setzero(res));
	ft_setnum(us_nbr, sign, len, res);
	return (res);
}
