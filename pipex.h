/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:15:37 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/20 14:53:10 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <sys/errno.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "libft/libft.h"
# include "ft_get_next_line/get_next_line.h"

void	px_err_msg(char *ex, char *file);
char	*px_check_command(char *arg, char **envp);
char	**px_split_res(char const *s, char c);
int		px_fork(int fd_in, char *argv, char **envp);

#endif