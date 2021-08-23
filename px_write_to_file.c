/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_write_to_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:38:54 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/23 13:41:56 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
//writes the contend of pipe p_fd to file o_fd
*/
void	px_write_to_file(int p_fd, int o_fd)
{
	char	*line;

	line = get_next_line(p_fd);
	while (line)
	{
		write(o_fd, line, ft_strlen(line));
		free (line);
		line = get_next_line(p_fd);
	}
}
