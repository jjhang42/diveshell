/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:55:09 by jjhang            #+#    #+#             */
/*   Updated: 2024/04/21 14:18:10 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

static void	ft_printerr(char *str)
{
	int	return_val;

	return_val = write (2, str, ft_strlen(str));
}

void	error_handler(char *filename, char *msg, int err_no)
{
	char	*strerr;

	write (2, "parse: ", 7);
	if (filename != NULL)
	{
		ft_printerr(filename);
		write (2, ": ", 2);
	}
	strerr = strerror(errno);
	if (msg != NULL)
		ft_printerr (msg);
	else
		ft_printerr(strerr);
	write (2, "\n", 1);
	exit(err_no);
}

void	syntax_error(char *str)
{
	ft_fprintf (2, "syntax error near unexpected token `%s'\n", str);
}