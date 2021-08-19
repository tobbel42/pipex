/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:58:31 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/19 16:54:21 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char** envp)
{
	char *in_file;
	char *out_file;

	if (argc != 5)
	{
		write(2, "pipex: NOT YET IMPLEMENTED\n", 40);
		return (-1);
	}
	in_file = argv[1];
	out_file = argv[argc - 1];
	if (access(in_file, R_OK) == -1)
		px_err_msg(argv[0], in_file);
	if (access(argv[argc - 1], W_OK) == -1 && errno !=2)
		px_err_msg(argv[0], out_file);
	char *path;
	path = px_check_command(argv[2], envp);
	if (path)
	{
		printf("%s\n", path);
		free(path);
	}
	else
		px_err_msg(argv[0], argv[2]);
	path = px_check_command(argv[3], envp);
	if (path)
	{
		printf("%s\n", path);
		free(path);
	}
	else
		px_err_msg(argv[0], argv[3]);
	system("leaks pipex");
	return (0);
}
