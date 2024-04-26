#include "header.h"
/*int chdir(const char *path)*/

char	*_pwd(void)
{
	char	*s;
	char	*buf;

	buf = NULL;
	s = getcwd(buf, 1024);
	if (!s)
		exit(1);
	printf("pwd: %s\n", s);
	return (s);
}

void	ft_cd(void)
{
	char	*tmp;

	tmp = _pwd();
	//~가 인자로 오면 HOME으로 보내줘야 한다
	if (chdir("~") == -1)
	{
		ft_printf("faied\n");
		exit(1);
	}
	_pwd();
	//unset PWD로 PWD의 환경변수를 삭제한 경우, cd로 PWD의 값이 변경돼도 환경변수가 새로 생기지 않는다
	//$OLDPWD도 바꿔준다 tmp를 여기 넣어준다
	//$PWD의 값 새로 받아서 수동으로 바꿔준다
}
