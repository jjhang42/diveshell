/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:31:49 by inryu             #+#    #+#             */
/*   Updated: 2024/06/08 19:51:23 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXPAND_H
# define FT_EXPAND_H

# include <dirent.h>
# include <stdlib.h>
# include <stdbool.h>
# include "ft_parse.h"
# include "ft_execute.h"

# define BOOL int

# define TRUE 1
# define FALSE 0

typedef struct s_execute	t_execute;
typedef struct s_expand_word
{
	char	*head;
	char	*key;
	char	*toe;
	char	*val;
}			t_expand_word;

void	is_wildcard(t_pars_tree *tree, t_execute *ms_exe, int *start);
void	replace_d(char **word, t_execute *ms_exe, int *start, int len);
void	key_obj(t_expand_word *exp, t_execute *ms_exe);
void	num_qm(char **word, t_expand_word *exp, t_execute *ms_exe, int start);
void	search_w(t_pars_tree *tree);
void	replace_w(t_pars_tree **head, t_pars_tree **tree);
BOOL	dp(char *s, char *p, int s_len, int p_len);
void	search_quote(char **str);
int		get_strlen(char **str);
char	*str_presscpy(char *dst, char *src, int len);
DIR		*wildcard_preprocess(t_pars_tree *tree);
int		get_wildcard_type(char *str);

#endif
