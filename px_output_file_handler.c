/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_output_file_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:15:30 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/23 16:15:27 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
//tries to open the file returns the filedescriptor,
//on error, -1 is returned and an error message is printed to stderr
*/
int	px_output_file_handler(char *argv)
{
	int	fd_out;

	if (access(argv, W_OK) == -1 && errno != 2)
	{
		px_err_msg("./pipex", argv, 1);
		return (-1);
	}
	else
	{
		fd_out = open(argv, O_CREAT | O_WRONLY | O_TRUNC);
		return (fd_out);
	}
}
