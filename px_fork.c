/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:33:47 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/23 17:39:31 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	fork_cleanup(char *cmd, char **cmd_argv)
{
	int		i;

	if (cmd)
		free(cmd);
	i = 0;
	if (cmd_argv)
	{
		while (cmd_argv[i])
		{
			free(cmd_argv[i]);
			i++;
		}
		free(cmd_argv);
	}
}

static void	fork_action(char **cmd_argv, char **envp, int *p_fd, int i_fd)
{
	int		pid;
	char	*cmd;

	cmd = px_check_command(cmd_argv[0], envp);
	if (!cmd)
		px_err_msg("./pipex", cmd_argv[0], 0);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			close(p_fd[0]);
			dup2(p_fd[1], 1);
			dup2(i_fd, 0);
			execve(cmd, cmd_argv, envp);
			px_err_msg("./pipex", cmd_argv[0], 1);
		}
		wait(NULL);
	}
	free(cmd);
}

/*
//opens a pipe, and tries to launch the command and
//writes the output into the pipe.
//the fd of read-end of pipe is returned.
*/
int	px_fork(int i_fd, char *argv, char **envp)
{
	int		p_fd[2];
	char	**cmd_argv;

	pipe(p_fd);
	cmd_argv = px_split_res(argv, ' ');
	if (cmd_argv)
		fork_action(cmd_argv, envp, p_fd, i_fd);
	else
		px_err_msg("./pipex", cmd_argv[0], 1);
	close (p_fd[1]);
	fork_cleanup(NULL, cmd_argv);
	return (p_fd[0]);
}
