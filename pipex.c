/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:58:31 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/20 15:32:18 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char *in_file;
	char *out_file;
	char *line;

	if (argc < 5)
	{
		write(2, "pipex: NOT YET IMPLEMENTED\n", 40);
		return (-1);
	}

	in_file = argv[1];
	out_file = argv[argc - 1];

	int	p_fd = 0;

	if (access(in_file, R_OK) == -1)
	{	
		px_err_msg(argv[0], in_file);
		int fds[2];
		pipe(fds);
		close(fds[1]);
		p_fd = fds[0];
	}
	else
		p_fd = open(argv[1], O_RDONLY);
	//TODO handle when no access no stuff
	int i;
	i = 2;
	while (i < argc - 1)
	{
		p_fd = px_fork(p_fd, argv[i], envp);
		i++;
	}
	if (access(argv[argc - 1], W_OK) == -1 && errno !=2)
		px_err_msg(argv[0], out_file);
	else
	{
		int fd_out = open(out_file, O_CREAT | O_WRONLY | O_TRUNC);
		line = get_next_line(p_fd);
		while (line)
		{
			write(fd_out, line, ft_strlen(line));
			free (line);
			line = get_next_line(p_fd);
		}
	}
	//system("leaks pipex");
	return (0);
}
