/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:43:32 by jjhang            #+#    #+#             */
/*   Updated: 2024/02/28 19:58:03 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_file
{
	int				fd;
	char			*data;
	size_t			str_len;
	struct s_file	*next;
}	t_file;

char	*get_next_line(int fd);
t_file	*ft_lstfind(t_file **head, int fd);

#endif
