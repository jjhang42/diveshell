/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:27:04 by jjhang            #+#    #+#             */
/*   Updated: 2024/04/07 13:13:43 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

int	main(void)
{
	int		exit_code;
	char	*str = "'get_next_line || adjklsfjkladf.!!'||| &&& dfjkladlfjk";
	char	**res;

	res = bottom_up_parser(str);
	exit_code = 0;
	for(int i = 0 ; res[i] != NULL ; i++)
		printf ("%s\n", res[i]);
	exit (exit_code);
}
