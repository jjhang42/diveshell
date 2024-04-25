/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tree_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:58:54 by jjhang            #+#    #+#             */
/*   Updated: 2024/04/22 16:59:27 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse.h"

t_pars_tree	*new_tree_node(int type, char *word)
{
	t_pars_tree	*new;

	new = (t_pars_tree *)malloc(sizeof(t_pars_tree) * 1);
	if (new == NULL)
		error_handler(word, NULL, 5);
	new->word = word;
	new->type = type;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
