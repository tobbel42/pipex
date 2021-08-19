/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:15:37 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/19 15:39:56 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <sys/errno.h>
# include <string.h>
# include "libft/libft.h"

void	px_err_msg(char *ex, char *file);
char	*px_check_command(char *arg, char **envp);

#endif