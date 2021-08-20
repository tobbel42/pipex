/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_err_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:03:28 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/20 14:29:36 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
//prints a detailed error message
*/
void	px_err_msg(char *ex, char *file)
{
	char	*err_msg;

	err_msg = ft_strdup(strerror(errno));
	if (!err_msg)
		return ;
	err_msg[0] = ft_tolower(err_msg[0]);
	write(2, ex, ft_strlen(ex));
	write(2, ": ", 2);
	write(2, err_msg, ft_strlen(err_msg));
	write(2, ": ", 2);
	write(2, file, ft_strlen(file));
	write(2, "\n", 1);
	free(err_msg);
}
