/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_error_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:41:31 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/09 05:57:24 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

int	builtin_error_handler(char *function, char *message, int exit_no)
{
	char	*error_msg;

	error_msg = NULL;
	if (errno != 0)
		error_msg = strerror(errno);
	ft_fprintf (2, "diveshell: ");
	if (function != NULL)
		ft_fprintf (2, "%s: ", function);
	if (error_msg != NULL)
		ft_fprintf (2, "%s", error_msg);
	else if (message != NULL)
		ft_fprintf (2, "%s", message);
	ft_fprintf(2, "\n");
	return (exit_no);
}
