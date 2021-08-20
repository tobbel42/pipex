/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:33:47 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/20 15:29:45 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	px_fork(int fd_in, char *argv, char **envp)
{
	int		p_fd[2];
	int		i;
	int		pid;
	char	*cmd;
	char	**cmd_argv;

	pipe(p_fd);
	cmd_argv = px_split_res(argv, ' ');
	cmd = px_check_command(cmd_argv[0], envp);
	if (!cmd)
		px_err_msg("./pipex", cmd_argv[0]);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			close(p_fd[0]);
			dup2(p_fd[1], 1);
			dup2(fd_in, 0);
			execve(cmd, cmd_argv, envp);
		}
	}
	wait(NULL);
	close (p_fd[1]);
	if (cmd)
		free(cmd);
	i = 0;
	while (cmd_argv[i])
	{
		free(cmd_argv[i]);
		i++;
	}
	free(cmd_argv);
	return (p_fd[0]);
}
