/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:27:04 by jjhang            #+#    #+#             */
/*   Updated: 2024/04/30 19:35:14 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pars_tree	*temp;
	t_pars_tree	*tree;
	char		**new_argv;
	char		*str;
	char		**fd_data;

	if (argc == 0)
	{
		printf ("%s\n", *argv);
		envp[0] = NULL;
	}
	while (1)
	{
		str = readline("dive-1.0$ ");
		if (str == NULL)
			break ;
		tree = minishell_parser(str);
		temp = get_token_ptr(tree);
		get_token_line(&fd_data, &new_argv, temp);
		for (int i = 0; new_argv[i] != NULL; i++)
			printf ("%s\n", new_argv[i]);
		for (int i = 0; fd_data[i] != NULL; i++)
			printf ("%s\n", fd_data[i]);
		free(str);
	}
	exit (0);
}
