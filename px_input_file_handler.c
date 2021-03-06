/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_input_file_handler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:05:34 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/23 15:20:47 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
//tries to opens the input file, returns the filedescriptor
//if the file can not be opened, an errormessage is printed
//and the read end of a emptt pipe is returned
*/
int	px_input_file_handler(char *argv)
{
	int	fd[2];

	if (access(argv, R_OK) == -1)
	{
		px_err_msg("./pipex", argv, 1);
		pipe(fd);
		close(fd[1]);
		return (fd[0]);
	}
	else
		return (open(argv, O_RDONLY));
}
