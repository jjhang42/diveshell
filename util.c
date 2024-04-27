#include "header.h"

t_list	*ft_ddup(char **env)
{
	t_list	*head;
	t_list	*new;
	char	*s;
	int		i;

	new = NULL;
	i = 0;
	if (env[i])
	{
		s = ft_strdup(env[i]);
		if (new == NULL)
		{
			new = ft_lstnew(s);//lstnew 함수 안에서 할당 실패 시 exit으로 바꿔야?
			head = new;
		}
		else
		{
			new = ft_lstnew(s);
			ft_lstadd_back(head, new);
		}
		i++;
	}
	return (head);
}
