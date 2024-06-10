/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctl_quote1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:22:41 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/06 10:14:07 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

void	search_quote(char **src)
{
	char	*tem;
	char	*dst;
	int		len;

	tem = *src;
	len = get_strlen(&tem);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		error_handler("quote", NULL, 12);
	dst = str_presscpy(dst, *src, len);
	dst[len] = '\0';
	free(*src);
	*src = dst;
}
