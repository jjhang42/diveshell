/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctl_quote2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:22:41 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/06 12:51:50 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static int	get_quote_str(char **str)
{
	int	len;
	int	q_type;

	len = 0;
	if (**str == '\'' || **str == '\"')
	{
		q_type = **str;
		(*str)++;
	}
	while (**str != '\0' && **str != q_type)
	{
		len++;
		(*str)++;
	}
	if (**str == q_type)
		(*str)++;
	return (len);
}

int	get_strlen(char **str)
{
	int		len;

	len = 0;
	while (**str != '\0')
	{
		if ((**str != '\"' && **str != '\''))
		{
			if (**str == '*')
				**str = -1 * '*';
			if (**str == '?')
				**str = -1 * '?';
			(*str)++;
			len++;
		}
		else
			len += get_quote_str(str);
	}
	return (len);
}

char	*str_presscpy(char *dst, char *src, int len)
{
	int	src_idx;
	int	dst_idx;
	int	q_type;

	src_idx = 0;
	dst_idx = 0;
	q_type = -1;
	while (src[src_idx] != '\0' && dst_idx < len)
	{
		if ((src[src_idx] == '\"' || src[src_idx] == '\'') && q_type == -1)
				q_type = src[src_idx];
		else if (src[src_idx] != q_type)
		{
			dst[dst_idx] = src[src_idx];
			dst_idx++;
		}
		else if (src[src_idx] == q_type)
			q_type = -1;
		src_idx++;
	}
	return (dst);
}
