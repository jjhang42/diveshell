/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exe_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:51:34 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/04 23:53:42 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

void	free_exe_data(t_pars_tree **ctl_cmd, t_process *data)
{
	t_pars_tree	*cur;

	free(data->argv);
	free(data->redirection);
	data->argv = NULL;
	data->redirection = NULL;
	cur = *ctl_cmd;
	delete_tree_node(ctl_cmd);
	printf ("ctl_cmd: %p\n", *ctl_cmd);
}
