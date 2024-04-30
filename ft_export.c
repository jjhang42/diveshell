#include "header.h"

void    ft_add_var(char *key, t_list *cpenv)
{
    t_list	*cur;
	t_list	*pre;
    t_list  *new;
	size_t	key_len;

	cur = cpenv;
	pre = NULL;
	key_len = ft_strlen(key);
	while (cur)
	{
        if (ft_strncmp(key, cur->content, key_len) == 0)
		{
            if (cur->content[key_len] == '=' || cur->content[key_len] == '\0')
            {
                if (pre == NULL)
	    			cpenv = cur->next;
		    	else
			    	pre->next = cur->next;
			    ft_lstdelone(cur, (*del));
	    	}
		pre = cur;
		cur = cur->next;
	}//있었으면 지워버린다
	s = ft_strdup(key);
	new = ms_lstnew(s);
	ft_lstadd_back(&cpenv, new);
	}
}

int ft_export(t_pars_tree *cmd, t_list cpenv, int fd)
{
    t_list	*cur;

	open(fd, O_WRONLY);
	if (cmd->cmd && cmd->redir_flag == 0)
	{
		if (!cmd->cmd[1])//no opt, no arg
        {
        	cur = cpenv;
	        while (cur)
	        {
		        ft_putendl_fd(cur->content, fd);//아니지 내용 없는 애는 '' 넣어야지
		        cur = cur->next;
            }
            return (1);
        }
        if (ft_valid_key(cmd->cmd[1]))
			ft_add_var(cmd->cmd[1], cpenv);
		else
			ft_putendl_fd("bash: unset: `a=': not a valid identifier", 2);
			return (-1);
	}
	return (1);
}
