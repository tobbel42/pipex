/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:58:31 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/18 17:20:58 by tgrossma         ###   ########.fr       */
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
	argv[0] = "zsh";
	in_file = argv[1];
	out_file = argv[argc - 1];
	if (access(in_file, R_OK) == -1)
		px_err_msg(argv[0], in_file);
	if (access(argv[argc - 1], W_OK) == -1 && errno !=2)
		px_err_msg(argv[0], out_file);
	envp = NULL;
	system("leaks pipex");
	return (0);
}
