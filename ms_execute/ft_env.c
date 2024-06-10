/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:04:21 by inryu             #+#    #+#             */
/*   Updated: 2024/06/03 07:51:44 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

static int	env_flag_processer(int *flag, char **argv, t_execute *ms_exe)
{
	int	idx;

	idx = 0;
	while (argv[idx] != NULL)
		idx++;
	if (idx != 1)
	{
		builtin_error_handler("env", NULL, 22);
		*flag = -1;
		return (-1);
	}
	if (ms_exe->env_lst == NULL)
		*flag = -1;
	return (0);
}

int	ft_env(char **argv, t_execute *ms_exe)
{
	int	flag;
	int	check;

	flag = 0;
	check = env_flag_processer(&flag, argv, ms_exe);
	if (check != 0)
		return (1);
	if (flag != -1)
		print_env_lst(ms_exe->env_lst);
	return (0);
}
