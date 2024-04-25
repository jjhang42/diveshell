/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:49:50 by jjhang            #+#    #+#             */
/*   Updated: 2024/03/17 16:33:15 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//size == (len of "%[flag][format char]")
static int	put_format_str(int *pos, char *str, va_list *arg, t_format *data)
{
	int	return_val;
	int	idx;
	int	size;

	size = 1;
	idx = *pos;
	(*pos) += init_data2(data, &str[*pos]);
	init_varg(data, arg);
	if ((*data).conv == '%' || (*data).conv == 'c')
		return_val = put_chartype(data, (*data).data.c, (*data).width);
	if ((*data).conv == 'd' || (*data).conv == 'i')
		return_val = put_inttype(data, (*data).data.lld, (*data).width, 0);
	if ((*data).conv == 'x' || (*data).conv == 'X' || (*data).conv == 'u')
		return_val = put_uinttype(data, (*data).data.ui, (*data).width, 0);
	if ((*data).conv == 's')
		return_val = put_strtype(data, (*data).data.v, (*data).width);
	if ((*data).conv == 'p')
		return_val = put_uinttype(data, (*data).data.zu, (*data).width, 0);
	return (return_val);
}

static int	ft_print_turnout(int fd, char *str, va_list *arg_ptr, int check)
{
	t_format	data;
	int			idx;
	int			size;

	idx = 0;
	size = 0;
	while (str[idx] != '\0' && check != -1)
	{
		while (str[idx] != '\0' && str[idx] == '%' && check != -1)
		{
			idx++;
			init_flag_n_format(fd, &data);
			check = put_format_str(&idx, str, arg_ptr, &data);
			size += check;
		}
		if (str[idx] != '\0' && str[idx] != '%' && check != -1)
		{
			check = ft_putchar_int(fd, str[idx]);
			size += check;
			idx++;
		}
	}
	if (check == -1)
		return (-1);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list		arg_ptr;
	size_t		size;

	va_start(arg_ptr, str);
	size = ft_print_turnout(1, (char *)str, &arg_ptr, 0);
	va_end(arg_ptr);
	return (size);
}

int	ft_fprintf(int fd, const char *str, ...)
{
	va_list		arg_ptr;
	size_t		size;

	va_start(arg_ptr, str);
	size = ft_print_turnout(fd, (char *)str, &arg_ptr, 0);
	va_end(arg_ptr);
	return (size);
}
