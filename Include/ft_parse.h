/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:23:55 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/09 18:09:12 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "libft.h"
# include <readline/readline.h>

# define LEFT 0
# define RIGHT 1

# define TRUE 1
# define FALSE 0

# define SKIP 512
# define LAST_PROCESS 256
# define CTL_CMD 128
# define PIPE 64
# define SUB_SHELL 32
# define QUOTE 16
# define DOUBLE_QUOTE 8
# define REDIRECTION 4
# define FILENAME 2
# define WORD 1
# define JUST_FILENAME 0

typedef struct s_pars_tree
{
	char				*word;
	int					type;
	struct s_pars_tree	*left;
	struct s_pars_tree	*right;
}	t_pars_tree;

extern volatile sig_atomic_t	g_signal;
/* error_msg*/
void		error_handler(char *filename, char *msg, int err_no);
void		syntax_error(int *lexer, char *str);
/*parsing functinos*/
t_pars_tree	*minishell_parser(int *res, char *cmdline, \
								t_pars_tree **end_ptr, t_pars_tree **tree);
int			get_subshell(int lexer, char **cursor, \
								t_pars_tree **end_ptr, t_pars_tree **tree);
t_pars_tree	*add_new_subshell(t_pars_tree *new_node, t_pars_tree **ptr);
int			get_word(int lexer, char **cursor, \
								t_pars_tree **end_ptr, t_pars_tree **tree);
int			get_redirection(int lexer, char **cursor, \
								t_pars_tree **end_ptr, t_pars_tree **tree);
int			get_pipe(int lexer, char **cursor, \
								t_pars_tree **end_ptr, t_pars_tree **tree);
int			get_ctl_cmd(int lexer, char **cursor, \
								t_pars_tree **end_ptr, t_pars_tree **tree);
void		is_another_ctl_cmd(int *lexer, char **cursor);
int			get_additional_input(int *lexer, \
								t_pars_tree **end_ptr, t_pars_tree **tree);
int			word_symbol(char c);
void		get_variable(t_pars_tree *tree);
/*parsing untils functions*/
void		delete_tree_node(t_pars_tree **tree);
int			is_meta_charater(char c);
int			is_whitespace(char c);
int			is_control_oprator(char *ptr);
int			is_limited_control_operator(char *ptr);
char		token_start(int *lexer, char c);
int			is_control_cmd(char *ptr);
t_pars_tree	*new_tree_node(int type, char *word);
t_pars_tree	*get_last_node(int way, t_pars_tree *tree);
void		tree_nodeadd_back(t_pars_tree **head, t_pars_tree *new);
t_pars_tree	*add_tree_front(t_pars_tree *old, t_pars_tree *new);
void		get_token_line(char ***fd_data, char ***argv, t_pars_tree *tree);
char		*read_word(int *lexer, char **cursor);
/*made on*/
void		print_tree(t_pars_tree *head);

#endif