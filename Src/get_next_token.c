/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:07:51 by jjhang            #+#    #+#             */
/*   Updated: 2024/04/25 19:22:15 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

void	circuit_tree(t_pars_tree *tree)
{
	if (tree == NULL)
		return ;
	circuit_tree(tree->left);
	circuit_tree(tree->right);
}

// char	*get_next_token(t_pars_tree *tree)
// {
// 	char	*str;

// 	return (str);
// }
