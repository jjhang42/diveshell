/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:42:44 by jjhang            #+#    #+#             */
/*   Updated: 2024/02/10 14:59:46 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//function : this function return int(1) if string has arg-'c' character.
//			 or return int(0) if not.
static int	ft_isnextline(t_file **lst, char *str, int mode)
{
	size_t	idx;

	idx = 0;
	if (str == NULL)
		return (0);
	while (mode == 1 && str[idx] != '\0')
	{
		if (str[idx] == '\n')
		{
			(*lst)->str_len = idx + 1;
			return (1);
		}
		idx++;
	}
	while (mode == 0 && str[idx] != '\0')
		idx++;
	(*lst)->str_len = idx;
	return (0);
}

static char	*ft_memfree(t_file **head, t_file **lst)
{
	t_file	*tem;

	tem = *head;
	while (tem != NULL)
	{
		if (tem == (*lst) || tem->next == (*lst))
			break ;
		tem = tem->next;
	}
	free((*lst)->data);
	(*lst)->data = NULL;
	if (*head == *lst)
		(*head) = tem->next;
	else
		tem->next = (*lst)->next;
	free(*lst);
	(*lst) = NULL;
	return (NULL);
}

//function : Define the return value and set the buffer;
static char	*ft_bufset(t_file **lst, char *buf, char *tem, size_t len)
{
	tem = ft_strjoin((*lst)->data, buf);
	free(buf);
	if (tem == NULL)
		return (NULL);
	ft_isnextline(lst, tem, 1);
	buf = ft_substr(tem, 0, (*lst)->str_len);
	len = (*lst)->str_len;
	ft_isnextline(lst, tem + len, 0);
	if (buf == NULL)
	{
		free(tem);
		return (NULL);
	}
	free((*lst)->data);
	(*lst)->data = ft_substr(tem, len, (*lst)->str_len);
	free (tem);
	if ((*lst)->data == NULL)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

//funcion : if user need to another str from file descriptor, 
//user are able to get strings.
static char	*ft_readmore(t_file **lst, char *buf, size_t idx, ssize_t *read_val)
{
	size_t	size;

	size = BUFFER_SIZE;
	*read_val = 0;
	while (ft_isnextline(lst, buf, 1) == 0)
	{
		if (size <= BUFFER_SIZE * (idx + 1))
		{
			buf = ft_realloc(buf, size + BUFFER_SIZE * idx);
			size += size;
		}
		if (buf == NULL)
			return (NULL);
		*read_val = read((*lst)->fd, buf + BUFFER_SIZE * idx, BUFFER_SIZE);
		buf[BUFFER_SIZE * idx + *read_val] = '\0';
		if (*read_val == 0)
			break ;
		idx++;
	}
	if (*read_val == 0 && (*lst)->str_len == 0)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

//funtion : G!N!L!!!!!!
char	*get_next_line(int fd)
{
	static t_file	*head;
	t_file			*node;
	char			*result;
	ssize_t			read_val;

	result = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	node = ft_lstfind(&head, fd);
	if (node == NULL)
		return (NULL);
	if (read(fd, NULL, 0) == -1)
		return (ft_memfree(&head, &node));
	if (ft_isnextline(&node, node->data, 1) == 0)
	{
		result = ft_readmore(&node, result, 0, &read_val);
		if (result == NULL)
			return (ft_memfree(&head, &node));
	}
	result = ft_bufset(&node, result, NULL, 0);
	if (result == NULL)
		return (ft_memfree(&head, &node));
	if (read_val == 0 && node->str_len == BUFFER_SIZE)
		ft_memfree(&head, &node);
	return (result);
}
