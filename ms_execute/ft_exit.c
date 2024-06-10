/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 00:45:31 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/09 20:45:00 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

static unsigned char	put_exit_err(int idx, int flag, \
										unsigned char result, char *str)
{
	if (idx > 2)
	{
		ft_fprintf(2, "diveshell: exit: too many arguments\n");
		result = 1;
	}
	else if (flag == TRUE)
	{
		ft_fprintf (2, "diveshell: %s: numeric argument required\n", str);
		result = 255;
	}
	return (result);
}

unsigned char	get_exit_status(char result, char *argv[])
{
	int		flag;
	int		idx1;
	int		idx2;

	idx1 = 1;
	flag = FALSE;
	while (argv[idx1] != NULL)
	{
		idx2 = 0;
		while (argv[idx1][idx2] != '\0')
		{
			if (ft_isdigit(argv[idx1][idx2]) != 1)
				flag = TRUE;
			if (argv[idx1][0] == '-' || argv[idx1][0] == '+')
				flag = FALSE;
			idx2++;
		}
		result = strtol(argv[idx1], NULL, 10);
		idx1++;
	}
	result = put_exit_err(idx1, flag, result, argv[1]);
	return (result);
}

int	ft_exit(char *argv[], t_execute *ms_exe)
{
	t_env_lst		*exit_code;
	unsigned char	result;

	result = 0;
	exit_code = ft_getenv_from_node(ms_exe->builtin_env_lst, "?");
	exit_code->content = ft_itoa(result);
	result = get_exit_status(result, argv);
	free(exit_code->content);
	exit_code->content = NULL;
	exit_code->content = ft_itoa((int)result);
	exit (result);
}
