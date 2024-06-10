/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appending_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:46:44 by jjhang            #+#    #+#             */
/*   Updated: 2024/05/26 01:10:17 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_pipe.h"

void	appending_output(char *filename, t_process *data)
{
	int	filedesc;

	output_redirection_flag_ctl(data);
	filedesc = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (filedesc == -1)
		error_handler(filename, NULL, 1);
	data->fd[WRITE] = filedesc;
}
