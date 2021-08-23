/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_output_file_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:15:30 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/23 15:21:00 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
//tries to open the file returns the filedescriptor,
//on error, -1 is returned and an error message is printed to stderr
//launch with mode 1 to open the file in append mode.
*/
int	px_output_file_handler(char *argv, int mode)
{
	int	fd_out;

	mode = 1;
	if (access(argv, W_OK) == -1 && errno != 2)
	{
		px_err_msg("./pipex", argv, 1);
		return (-1);
	}
	// else if (mode == 1)
	// {
	// 	fd_out = open(argv, O_CREAT | O_WRONLY | O_APPEND);
	// 	return (fd_out);
	// }
	else
	{
		fd_out =  open(argv, O_CREAT | O_WRONLY | O_TRUNC);
		return (fd_out);
	}
}
