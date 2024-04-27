#include "header.h"

t_list	*ms_lstnew(void *content)
{
	t_list	*ret;

	ret = ft_calloc(1, sizeof(t_list));
	if (!ret)
		exit(1);
	ret->content = content;
	return (ret);
}

t_list	*ft_ddup(char **env)
{
	t_list	*head;
	t_list	*new;
	char	*s;
	int		i;

	new = NULL;
	i = 0;
	while (env[i])
	{
		s = ft_strdup(env[i]);
		if (new == NULL)
		{
			new = ft_lstnew(s);
			head = new;
		}
		else
		{
			new = ft_lstnew(s);
			ft_lstadd_back(&head, new);
		}
		i++;
	}
	return (head);
}
