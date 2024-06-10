/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:32:25 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/03 07:54:11 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

char	*get_env_name(char *str)
{
	char	*res;
	int		idx;
	int		len;

	len = 0;
	while (str[len] != '\0' && str[len] != '=')
		len++;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		error_handler("export", NULL, 12);
	res[len] = '\0';
	idx = 0;
	while (idx < len)
	{
		res[idx] = str[idx];
		idx++;
	}
	return (res);
}

char	*get_env_content(char *str)
{
	char	*res;
	int		len;
	int		flag;

	len = 0;
	flag = 0;
	while (str[len] != '\0' && str[len] != '=')
		len++;
	if (str[len] == '=')
	{
		flag = 1;
		len++;
	}
	if (flag == 0)
		return (NULL);
	res = ft_strdup(&str[len]);
	return (res);
}

void	print_ft_export(t_execute *ms_exe)
{
	t_env_lst	*env_lst;

	env_lst = ms_exe->env_lst;
	while (env_lst != NULL)
	{
		printf ("declare -x %s", env_lst->name);
		if (env_lst->content != NULL)
			printf ("=\"%s\"", env_lst->content);
		printf ("\n");
		env_lst = env_lst->next;
	}
}
