/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:55:02 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/09 06:56:18 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

static int	is_optional_str(int *flag, char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (idx == 0 && str[idx] == '-')
		{
			if ((*flag & 1) != 1)
				(*flag) += 1;
			idx++;
		}
		else if (idx > 0 && str[idx] == 'n')
		{
			if ((*flag & 2) != 2)
				(*flag) += 2;
			idx++;
		}
		else
			return (0);
	}
	return (1);
}

static int	set_option(int *flag, char **argv)
{
	int	option;
	int	idx;

	idx = 1;
	while (argv[idx] != NULL)
	{
		option = 0;
		if (is_optional_str(&option, argv[idx]) == 1 && (option & 3) == 3)
		{
			*flag = option;
			idx++;
		}
		else
			break ;
	}
	return (idx);
}

int	ft_echo(char **argv)
{
	int		flag;
	int		idx;

	flag = 0;
	idx = set_option(&flag, argv);
	while (argv[idx] != NULL)
	{
		printf ("%s", argv[idx]);
		idx++;
		if (argv[idx] != NULL)
			printf (" ");
	}
	if ((flag & 3) != 3)
		printf ("\n");
	return (0);
}
