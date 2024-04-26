#include "header.h"

int	builtin(t_token *cmd, char **copy_env, int fds[])
{
	int	fd;
	
	//리다이렉션이 있으면
	//파이프가 있으면
	// else
	// 	fd = 1;
	if (ft_strcmp("pwd", cmd->cmd) == 0) // 명령어는 커맨드라인의 처음부분에만 올 수 있으므로
	//cmdline의 첫번째 index를 과제에서 구현해야하는 명령어와 비교하여 일치할 시, 조건문의 함수를 실행합니다.
		return (ft_pwd(fd));
	else if (ft_strcmp("cd", cmd->cmd) == 0)
		return (ft_cd());
	else if (ft_strcmp("exit", cmd->cmd) == 0)
		return (ft_exit(cmd));
	else if (ft_strcmp("env", cmd->cmd) == 0)
		return (ft_env(*envp, fd));
	else if (ft_strcmp("export", cmd->cmd) == 0)
		return (ft_export(cmd, copy_env, fd));
	else if (ft_strcmp("echo", cmd->cmd) == 0)
		return (ft_echo(cmd, fd));
	else if (ft_strcmp("unset", cmd->cmd) == 0)
		return (ft_unset(cmd, *copy_env));
	else if (non_builtin(cmd, *copy_env, fds) == 0) // 위의 해당하는 명령어가 아닐경우, non_built 함수에서 입력된 명령어가 유효한 명령어인지 최종적으로 확인합니다. 유효한 명령어일 경우, 내장된 프로그램이 실행되고 아닐경우, 오류가 출력됩니다.
	{
		cmd->errcode = 1;
		return (-1);
	}
	return (0);
}

void	process(t_token *cmd, char **copy_env)
{
// 	int pid;

	if (is_builtin_cmd_only_one(cmd))//?
		builtin(cmd, copy_env);
// 	else
// 	{
// 		pid = prcesser(cmd, env);
// 		if (waitpid(pid, &status, 0) != -1)
// 		{
// 			///여러가지 exit 코드 계산해줘야함
// 		}
// 	}
// 	while(waitpid(-1, NULL, 0) >0 )
// 		;
// 	unlink("heredoc");
}

// int	processer(t_list *cmd, char **env)
// {
// 	if (is_heredoc)
// 		make_heredoc_file()
// 	while (pipecount)
// 		pipex();
// }
