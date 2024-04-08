# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 10:32:17 by jjhang            #+#    #+#              #
#    Updated: 2024/04/07 11:50:47 by jjhang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
NAME = parse
BONUS_NAME = parse
LIBFT = libft/libft.a

SRC_DIR = src
OBJ_DIR = obj
BONUS_DIR = obj_bonus
LIBFT_DIR = libft
HEADER_DIR = include

SRC_MAN = 
SRC_BONUS = 

SRC_FILES = bottom_up_parser.c \
			error_handler.c \
			ft_free.c \
			test_main.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_FILES = $(SRC_FILES:.c=.o) $(notdir $(SRC_MAN:.c=.o))
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

BONUS_FILES = $(SRC_FILES:.c=.o) $(notdir $(SRC_BONUS:.c=.o))
B_OBJS = $(addprefix $(BONUS_DIR)/, $(BONUS_FILES))

HEADER = $(HEADER_DIR)

all : $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -o $(NAME) $^

bonus : $(LIBFT) $(B_OBJS)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -o $(BONUS_NAME) $^
	touch bonus

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_DIR) -I $(LIBFT_DIR)

$(OBJ_DIR)/%.o : src_mand/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_DIR) -I $(LIBFT_DIR)

$(BONUS_DIR)/%.o : $(SRC_DIR)/%.c | $(BONUS_DIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_DIR) -I $(LIBFT_DIR)

$(BONUS_DIR)/%.o : src_bonus/%.c | $(BONUS_DIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_DIR) -I $(LIBFT_DIR)

$(OBJ_DIR) :
	mkdir -p $@

$(BONUS_DIR) :
	mkdir -p $@

clean :
	rm -f $(OBJS) $(B_OBJS)
	rm -rf $(OBJ_DIR) $(BONUS_DIR)
	make -C $(LIBFT_DIR) clean
	rm -f bonus

fclean : clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_DIR) fclean

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re