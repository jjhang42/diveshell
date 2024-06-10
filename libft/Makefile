# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 21:36:55 by jjhang            #+#    #+#              #
#    Updated: 2024/05/20 14:34:05 by jjhang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRCS = ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strcmp.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_realloc.c \
	   ft_getenv.c \
	   $(LST) \
	   $(GNL) \
	   $(PRINTF) \
	   $(PARSER)

LST = ft_lstnew.c \
		 ft_lstadd_front.c \
		 ft_lstsize.c \
		 ft_lstlast.c \
		 ft_lstadd_back.c \
		 ft_lstdelone.c  \
		 ft_lstclear.c \
		 ft_lstiter.c \
		 ft_lstmap.c

GNL = get_next_line_utils.c get_next_line.c

PRINTF = ft_printf.c \
		ft_printf_utils.c \
		ft_print_fun.c \
		init_fun.c \
		init_datatype.c \
		ft_put_inttype.c \
		ft_put_uitype.c \
		ft_put_chartype.c \
		ft_put_strtype.c \
		ft_flag.c

OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)
HEADER = ./

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

clean :
	rm -f $(OBJS) $(B_OBJS)

fclean : clean
	rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re
