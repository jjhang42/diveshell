/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 02:09:50 by jjhang            #+#    #+#             */
/*   Updated: 2024/06/09 21:24:00 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXECUTE_H
# define FT_EXECUTE_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "ft_parse.h"
# include "minishell_pipe.h"
# include "ft_expand.h"

# ifndef DEBUG
#  define DEBUG 0
# endif

typedef struct s_env_lst
{
	char				*name;
	char				*content;
	struct s_env_lst	*next;
}	t_env_lst;

typedef struct s_execute
{
	t_env_lst	*env_lst;
	t_env_lst	*builtin_env_lst;
	int			fd[2];
}	t_execute;

int			main(int argc, char *argv[], char *env[]);
/*preprocessing*/
void		minishell_preprocess(t_execute *ms_exe, \
									int argc, char *argv[], char *envp[]);
void		init_process_data(t_process *data);
/*manage: env_list*/
void		manage_pwd(char *name, t_env_lst **env_lst);
void		manage_shell_level(t_env_lst **env_lst);
/*SIGNAL FUNCTIONS*/
void		signal_on(int type);
/* execute process */
void		cmd_turn_out(char *cmdline, t_process *data, t_execute *ms_exe);
t_pars_tree	*execute_cmd(t_pars_tree *tree, t_execute *ms_exe, t_process *data);
void		recur_node_call(t_pars_tree *tree, \
										t_process *data, t_execute *ms_exe);
void		recur_node_pipe(t_pars_tree *tree, \
										t_process *data, t_execute *ms_exe);
void		recur_node_ctl(t_pars_tree *tree, \
										t_process *data, t_execute *ms_exe);
void		recur_node_cir(t_pars_tree *tree, \
										t_process *data, t_execute *ms_exe);
/*manage for env_lst utiles*/
t_env_lst	*get_env_lst(char *envp[]);
t_env_lst	*ft_env_lstnew(char *name, char *content);
t_env_lst	*ft_env_splitnew(char *string);
void		ft_env_lstadd_back(t_env_lst **lst, t_env_lst *new);
t_env_lst	*ft_env_lstlast(t_env_lst *lst);
t_env_lst	*ft_getenv_from_node(t_env_lst *env_lst, char *name);
void		print_env_lst(t_env_lst *lst);
void		delete_env_node(t_env_lst *node);
char		**get_env_arr(t_env_lst *env);
/*bulitin*/
int			ft_echo(char **argv);
int			ft_cd(char **argv, t_execute *ms_exe);
int			cd_flag_processer(int flag, char **argv, t_execute *ms_exe);
void		cd_after_organize(int flag, char **argv, t_execute *ms_exe);
int			ft_env(char **argv, t_execute *ms_exe);
int			ft_pwd(char **argv);
int			ft_export(char *argv[], t_execute *ms_exe);
char		*get_env_name(char *str);
char		*get_env_content(char *str);
void		print_ft_export(t_execute *ms_exe);
int			ft_unset(char *argv[], t_execute *ms_exe);
int			ft_exit(char *argv[], t_execute *ms_exe);
int			is_able_to_envname(char *name);
int			builtin_error_handler(char *function, char *message, int exit_no);
int			is_cmd_turn_out(char **argv, t_execute *ms_exe);
int			is_builtin_function(char *argv);
/*execve*/
char		*is_cmd(char *cmd, t_env_lst *env);
void		double_free(char **arr);
void		free_exe_data(t_pars_tree **ctl_cmd, t_process *data);
t_env_lst	*get_last_execute_exit_code\
			(unsigned char exit_no, t_execute *ms_exe);
/*redirection*/
void		redirection_process(t_process *data);
/*process*/
int			parent_process(t_process *data);
void		child_process(int pid, t_execute *ms_exe, t_process *data);
void		wait_process(t_execute *ms_exe, t_process *data);
void		open_pipe(t_process *data);
/*ctl_cmd*/
int			set_ctl_cmd(t_pars_tree *tree, t_execute *ms_exe);
void		set_tree_to_int_max(t_pars_tree *tree);
int			get_type_flag(int type);
int			move_last_process_flag(int type);
int			add_last_process_flag(int type);
#endif