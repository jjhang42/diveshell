/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 03:28:07 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/09 23:04:16 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

void	signal_def(int sig)
{
	if (sig)
		return ;
}

static void	sigint_handler(int sig)
{
	if (sig != SIGINT)
		return ;
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("  \b\b", 1);
	ft_putstr_fd("\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	sigquit_handler(int sig)
{
	if (sig != SIGQUIT)
		return ;
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("  \b\b", 1);
}

void	signal_second(int sig)
{
	if (sig == SIGINT)
	{
		rl_done = 1;
		g_signal = 1;
		rl_on_new_line();
		rl_redisplay();
		ft_printf ("b\b  \n");
		exit(1);
	}
	if (sig == SIGQUIT)
		ft_printf ("\b\b  \b\b");
}

void	signal_on(int type)
{
	if (type == 0)
	{
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, sigquit_handler);
	}
	if (type == 1)
	{
		signal(SIGINT, signal_second);
		signal(SIGQUIT, sigquit_handler);
	}
	if (type == 2)
	{
		signal(SIGINT, signal_def);
		signal(SIGQUIT, signal_def);
	}
	if (type == 3)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
}
