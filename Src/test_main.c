/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:27:04 by jjhang            #+#    #+#             */
/*   Updated: 2024/04/25 19:19:30 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pars_tree	*tree;
	char		*str;

	if (argc == 0)
		printf ("%s\n", *argv);
	while (1)
	{
		str = readline("dive-1.0$ ");
		if (str == NULL)
			break ;
		tree = minishell_parser(str, envp);
		circuit_tree(tree);
		free(str);
	}
	exit (0);
}
