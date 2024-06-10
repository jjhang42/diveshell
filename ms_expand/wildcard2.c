/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:02:15 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/07 09:34:13 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static char	**array_init(int *j, char *p, int s_len, int p_len)
{
	int		idx;
	char	**array;

	array = (char **)malloc(sizeof(char *) * (s_len));
	if (array == NULL)
		error_handler("dp", NULL, 12);
	idx = 0;
	while (idx < s_len)
	{
		array[idx] = (char *)malloc(sizeof(char) * (p_len));
		if (array[idx] == NULL)
			error_handler("dp", NULL, 12);
		ft_bzero(array[idx], p_len);
		idx++;
	}
	idx = 0;
	array[0][0] = TRUE;
	while (++idx <= p_len && p[idx - 1] == ('*' * -1))
		array[0][idx] = array[0][idx - 1];
	*j = idx;
	return (array);
}

static void	dp_free(char **array, int s_len)
{
	int	idx;

	idx = 0;
	while (idx < s_len)
	{
		free(array[idx]);
		idx++;
	}
	free(array);
}

BOOL	dp(char *s, char *p, int s_len, int p_len)
{
	char	**dp;
	int		i;
	int		j;
	int		result;

	dp = array_init(&j, p, s_len + 1, p_len + 1);
	i = 1;
	while (i <= s_len)
	{
		j = 1;
		while (j <= p_len)
		{
			if (p[j - 1] == ('?' * -1) || s[i - 1] == p[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else if (p[j - 1] == ('*' * -1))
				dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
			j++;
		}
		i++;
	}
	result = dp[s_len][p_len];
	dp_free(dp, s_len + 1);
	return (result);
}
