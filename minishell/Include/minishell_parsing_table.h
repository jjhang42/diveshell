/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parsing_table.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 23:54:14 by jjhang            #+#    #+#             */
/*   Updated: 2024/04/08 16:58:39 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_parse.h"

# define SHIFT 0
# define REDUCE 1
# define ACCEPT 2
# define ERROR 3

typedef struct s_parsetable
{
	int	actiontype;
	int	next_stage;
	int production;
}	t_parsetable;
