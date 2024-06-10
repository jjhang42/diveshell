/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:15:06 by inryu             #+#    #+#             */
/*   Updated: 2024/06/08 19:47:18 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static int	is_filetype(char *str)
{
	if (str[0] != '.')
		return (4);
	return (1);
}

static int	dp_turnout(int type, char *dir_name, char *input)
{
	int	s_len;
	int	p_len;
	int	result;

	s_len = 0;
	p_len = 0;
	result = 0;
	if (dir_name != NULL)
		s_len = ft_strlen(dir_name);
	if (input != NULL)
		p_len = ft_strlen(input);
	if (type == 1 && s_len != 0 && is_filetype(dir_name) == 1)
		result = dp(dir_name, input, s_len, p_len);
	if (type != 1 && s_len != 0 && is_filetype(dir_name) == 4)
		result = dp(dir_name, input, s_len, p_len);
	return (result);
}

static void	recover_str(t_pars_tree *tree)
{
	char	*str;
	int		idx;

	if (tree == NULL)
		return ;
	str = tree->word;
	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] == '*' * -1)
			str[idx] = '*';
		if (str[idx] == '?' * -1)
			str[idx] = '?';
		idx++;
	}
}

static void	wildcard(t_pars_tree **head, t_pars_tree *tree)
{
	DIR				*ptr;
	struct dirent	*dir;
	t_pars_tree		*new;
	int				type;

	ptr = wildcard_preprocess(tree);
	if (ptr == NULL)
		return ;
	type = get_wildcard_type(tree->word);
	while (1)
	{
		dir = readdir(ptr);
		if (dir == NULL)
			break ;
		if (dp_turnout(type, dir->d_name, tree->word))
		{
			new = new_tree_node(1, (ft_strdup(dir->d_name)));
			tree_nodeadd_back(head, new);
		}
	}
	closedir(ptr);
	if (*head != NULL)
		replace_w(head, &tree);
	else
		recover_str(tree);
}

void	search_w(t_pars_tree *tree)
{
	t_pars_tree	*head;
	t_pars_tree	*cur;
	t_pars_tree	*tem;
	int			flag;

	cur = tree;
	while (cur != NULL)
	{
		flag = get_type_flag(cur->type);
		head = NULL;
		if (0 <= flag && flag < PIPE)
			search_quote(&(cur->word));
		if ((ft_strchr(cur->word, -1 * '*') || ft_strchr(cur->word, -1 * '?')))
		{
			tem = cur->left;
			wildcard(&head, cur);
			cur = tem;
		}
		else
			cur = cur->left;
	}
}
