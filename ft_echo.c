#include "header.h"
//인자로 여러개 오면 32 하나 두고 조인한다 (redirection이 아니면 다 받음)

//echo의 n옵션 체크함수.

int	ft_echo(t_token *cmd, int fd)
{
	int flag; //-n 옵션에 대한 플래그
	int cnt;

	flag = 0;
	cnt = 0;
	//-nnnn 도 가능. -n -n -n 도 가능하게 해야합니다.
	//echo의 n옵션 체크함수.
	while (cmd->cmd && 리다이렉션 아닐 때)
	{
		if (cnt != 0)
			write(fd, " ", 1); //argument 사이사이 공백1개 넣기
		ft_putstr_fd(cmd->cmd, fd);
		cmd = cmd->right;
		cnt++;
	}
	if (flag == 0)
		write(fd, "\n", 1);
	return (1);
}
