/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:08:47 by jjhang            #+#    #+#             */
/*   Updated: 2024/05/13 18:46:27 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

void	double_free(char **arr)
{
	int	idx;

	idx = 0;
	while (arr[idx] != NULL)
	{
		free(arr[idx]);
		idx++;
	}
	free(arr);
}
