/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:51:03 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/08 23:29:58 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef union u_data
{
	void				*v;
	char				c;
	int					i;
	unsigned int		ui;
	ssize_t				lld;
	size_t				zu;
}	t_data;

typedef struct s_format
{
	char	flag;
	int		width;
	int		prec;
	char	conv;
	int		va_len;
	t_data	data;
	int		sign;
	int		s_lev;
	int		fd;
}	t_format;

int		ft_printf(const char *str, ...);
int		ft_fprintf(int fd, const char *str, ...);
size_t	ft_isconv(char c);
int		ft_getwidth_szt(size_t nbr, size_t base);
int		ft_getwidth_lld(ssize_t nbr, size_t base);
int		ft_putchar_int(int fd, char c);
int		ft_setfield(t_format *data, int size, int pos);
int		ft_putnbr_int(t_format *data, ssize_t nbr, int base);
int		ft_putnbr_szt(t_format *data, size_t nbr, int base);
int		ft_putstr_int(t_format *data, char *str, int size);
int		init_data1(t_format *data, char *str);
int		init_data2(t_format *data, char *str);
int		init_varg(t_format *data, va_list *arg_ptr);
void	format_set(t_format *data);
long	ft_strtol(const char *nptr, char **endptr, int base);
int		put_chartype(t_format *data, char c, int size);
int		put_inttype(t_format *data, ssize_t nbr, int size, int check);
int		put_strtype(t_format *data, char *str, int size);
int		put_uinttype(t_format *data, size_t nbr, int size, int check);
int		flag_manager(t_format *data, char c, char mode);
int		init_flag_n_format(int fd, t_format *data);

#endif
