/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:51:06 by jjhang            #+#    #+#             */
/*   Updated: 2024/05/26 01:11:58 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_pipe.h"

void	output_redirection(char *filename, t_process *data)
{
	int	filedesc;

	output_redirection_flag_ctl(data);
	filedesc = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (filedesc == -1)
		error_handler(filename, NULL, 1);
	data->fd[WRITE] = filedesc;
}
