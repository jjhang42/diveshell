# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 10:32:17 by jjhang            #+#    #+#              #
#    Updated: 2024/04/25 19:17:09 by jjhang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
READLINE = readline
NAME = parse
LIBFT = libft/libft.a

SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
HEADER_DIR = include

SRC_FILES = minishell_parser.c \
			get_last_node.c \
			new_tree_node.c \
			get_word.c \
			get_pipe.c \
			get_redireaction.c \
			get_ctl_cmd.c \
			get_variable.c \
			get_next_token.c \
			is_control_cmd.c \
			is_control_oprator.c \
			is_meta_charater.c \
			is_whitespace.c \
			error_handler.c \
			test_main.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

HEADER = $(HEADER_DIR)

all : $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -l$(READLINE) -o $(NAME) $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_DIR) -I $(LIBFT_DIR)

$(OBJ_DIR) :
	mkdir -p $@

clean :
	rm -f $(OBJS) $(B_OBJS)
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	rm -f bonus

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_DIR) fclean

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re