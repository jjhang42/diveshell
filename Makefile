# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 10:32:17 by jjhang            #+#    #+#              #
#    Updated: 2024/06/09 23:58:04 by jjhang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
READLINE = readline
NAME = minishell
BONUS = minishell_bonus
LIBFT = libft/libft.a

EXPAND_DIR = ms_expand
EXECUTE_DIR = ms_execute
PARSER_DIR = ms_parser

OBJ_DIR = obj
LIBFT_DIR = libft
HEADER_DIR = include

EXPAND_FILES = expand.c \
				wildcard1.c wildcard2.c \
				ctl_quote1.c \
				ctl_quote2.c \
				replace_w.c \
				wildcard_preprocess.c

EXECUTE_FILES = main.c \
				appending_output.c \
				builtin_error_handler.c \
				child_process.c \
				delete_env_lst.c \
				execute_cmd.c \
				free_exe_data.c \
				ft_cd1.c \
				ft_cd2.c \
				ft_echo.c \
				ft_env.c \
				ft_exit.c \
				ft_export1.c \
				ft_export2.c \
				ft_free.c \
				ft_getenv_from_node.c \
				ft_here_doc.c \
				ft_pwd.c \
				ft_unset.c \
				get_env_arr.c \
				get_env_lst.c \
				input_redirection.c \
				is_able_to_envname.c \
				is_builtin_function.c \
				is_cmd.c \
				manage_pwd.c \
				manage_shell_level.c \
				minishell_preprocess.c \
				output_redirection.c \
				parent_process.c \
				print_env_lst.c \
				print_tree.c \
				recursive_exe_utils.c \
				recursive_exe.c \
				redirection_flag_ctl.c \
				redirection_process.c \
				set_ctl_cmd.c \
				signal_functions.c \
				wait_process.c

PARSER_FILES = delete_tree_all.c \
			error_handler.c \
			get_ctl_cmd.c \
			get_additional_input.c \
			get_last_node.c \
			get_next_token.c \
			get_pipe.c \
			get_redireaction.c \
			get_subshell1.c \
			get_subshell2.c \
			get_variable.c \
			get_word1.c \
			get_word2.c \
			is_another_ctl_cmd.c \
			is_control_cmd.c \
			is_control_oprator.c \
			is_meta_charater.c \
			is_whitespace.c \
			minishell_parser.c \
			new_tree_node.c

EXPAND_SRCS = $(addprefix $(EXPAND_DIR)/, $(EXPAND_FILES))
EXECUTE_SRCS = $(addprefix $(EXECUTE_DIR)/, $(EXECUTE_FILES))
PARSER_SRCS = $(addprefix $(PARSER_DIR)/, $(PARSER_FILES))

OBJS = $(EXECUTE_FILES:%.c=$(OBJ_DIR)/%.o) \
		$(PARSER_FILES:%.c=$(OBJ_DIR)/%.o) \
		$(EXPAND_FILES:%.c=$(OBJ_DIR)/%.o)

HEADER = $(HEADER_DIR)

all : $(LIBFT) $(NAME)

bonus : $(LIBFT) $(BONUS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -l$(READLINE) -o $(NAME) $^

$(BONUS) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -l$(READLINE) -o $(BONUS) $^
	touch bonus

$(OBJ_DIR)/%.o : $(EXECUTE_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_DIR) -I $(LIBFT_DIR)

$(OBJ_DIR)/%.o : $(PARSER_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_DIR) -I $(LIBFT_DIR)

$(OBJ_DIR)/%.o : $(EXPAND_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_DIR) -I $(LIBFT_DIR)

$(OBJ_DIR) :
	mkdir -p $@

clean :
	rm -f $(OBJS) bonus
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME) $(BONUS)
	make -C $(LIBFT_DIR) fclean

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re
