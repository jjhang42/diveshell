/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:23:55 by jjhang            #+#    #+#             */
/*   Updated: 2024/04/30 19:15:47 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>


# define LEFT 0
# define RIGHT 1

/*type desc
*	INT_MAX == INVALID
*	2048
*	1024
*	512
*	256
*	128		ctl_cmd type
*	64		| type
*	32		() type
*	16		redi type
*	8		'' type
*	4		"" type
*	2		filename type
*	1		file type
*/
typedef struct s_pars_tree
{
	char	*word;
	int		type;
 	struct s_pars_tree	*left;
	struct s_pars_tree	*right;
}	t_pars_tree;


int			main(int argc, char *argv[], char *envp[]);
/* error_msg*/
void		error_handler(char *filename, char *msg, int err_no);
void		syntax_error(char *str);
/*parsing functinos*/
t_pars_tree	*minishell_parser(char *cmdline);
void		get_word(int *lexer, char **cursor, t_pars_tree **ptr);
void		get_redirection(int *lexer, char **cursor, t_pars_tree **ptr);
void		get_pipe(int *lexer, char **cursor, t_pars_tree **ptr);
void		get_ctl_cmd(int *lexer, char **cursor, t_pars_tree **ptr);
void		get_variable(t_pars_tree *tree);
/*parsing untils functions*/
int			is_meta_charater(char c);
int			is_whitespace(char c);
int			is_control_oprator(char *ptr);
int			is_control_cmd(char *ptr);
t_pars_tree	*new_tree_node(int type, char *word);
t_pars_tree *get_last_node(int way, t_pars_tree *tree);
t_pars_tree	*add_tree_front(t_pars_tree *old, t_pars_tree *new);

t_pars_tree	*get_token_ptr(t_pars_tree *tree);
void	get_token_line(char ***fd_data, char ***argv, t_pars_tree *tree);
// void	circuit_tree(t_pars_tree *tree);

#endif