/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:58:31 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/23 16:13:41 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		p_fd;
	int		o_fd;
	int		i;

	if (argc < 5)
		return (-1);
	p_fd = px_input_file_handler(argv[1]);
	i = 2;
	while (i < argc - 2)
	{
		p_fd = px_fork(p_fd, argv[i], envp);
		i++;
	}
	o_fd = px_output_file_handler(argv[argc - 1]);
	if (o_fd != -1)
	{
		p_fd = px_fork(p_fd, argv[i], envp);
		px_write_to_file(p_fd, o_fd);
	}
	exit(0);
	return (0);
}
