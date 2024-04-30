#include "header.h"

void	handle_signal(int sig)
{
	pid_t	pid;
	int		status;

/*fork()을 통하여 일반 명령을 수행하는 자식 프로세스의 작업 도중 수행을 중단시킬 수 있어야하므로 
	자식 프로세스의 경우에 한해서만 SIGINT를 DEFAULT로 설정한다*/
	pid = waitpid(-1, &status, WNOHANG);//자식프로세스 종료 안된 상황이면 0
	if (sig == SIGINT)
	{
		if (pid == -1)//자식프로세스가 없다: 개행, 나눌 필요가 있는가? pdf
		{
			rl_on_new_line();//관련 함수들에 다음 줄로 이동했음을 알린다
			rl_redisplay();//입력 받은 것 다시 출력
			ft_putstr_fd("  \b\b", 1);
			ft_putstr_fd("\n", 1);//개행
			rl_on_new_line();
		// //readline 다시 실행
			rl_replace_line("", 0);//버퍼내용을 빈문자열로 바꾼다, 0: 버퍼 초기화하지 않는다
			rl_redisplay();//실행...???
		}
		else
			ft_putstr_fd("\n", 1);//다시출력해서 커서가 글자의 끝에 있음.
	}
	else if (sig == SIGQUIT)
	{
		if (pid == -1)
		{
			rl_on_new_line();//입력 받은 것 종료
			rl_redisplay();// 입력받은 것 다시 출력
			ft_putstr_fd("  \b\b", 1);
		}
		else
			ft_putstr_fd("Quit: 3\n", 1);
	}
}


int	main(int ac, char **av, char **env)
{
	t_list	*cpenv;
	char	*input;
	t_pars_tree	*cmd;

	if (ac == 1 && !av[1])
	{
		cpenv = ft_ddup(env);//미니쉘 켤 때마다 매번
		signal(SIGINT, handle_signal);//signal controller
		signal(SIGQUIT, handle_signal);
		while((input = readline("minishell$ ")))
		{
			add_history(input);
			*cmd = paser(input);//화이트 스페이스만 있는 경우는?
			process(cmd, cpenv);
			free(input);
			//cmd도 프리해줘야 하나?
		}//ctrl + d를 눌렀을 때
		ft_putstr_fd("\x1b[1A", 1);//위로 한칸 이동
		ft_putstr_fd("\033[11C",1);//오른쪽으로 11칸
		ft_putstr_fd("exit\n", 1);
	}
	return (exitno);
}
