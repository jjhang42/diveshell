/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:33:13 by jjhang            #+#    #+#             */
/*   Updated: 2024/04/25 19:17:37 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

void	get_variable(t_pars_tree *tree)
{
	char	*word;
	int		idx;

	if (tree->type > 4)
		return ;
	idx = 0;
	word = tree->word;
	while (word[idx] != '\0')
	{
		if (word[idx] == '$')
			ft_printf ("%s\n", tree->word);
		idx++;
	}
}
