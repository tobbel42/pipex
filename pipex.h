/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:15:37 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/23 15:20:04 by tgrossma         ###   ########.fr       */
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

void	px_err_msg(char *ex, char *file, int mode);
char	*px_check_command(char *arg, char **envp);
char	**px_split_res(char const *s, char c);
int		px_fork(int fd_in, char *argv, char **envp);
int		px_input_file_handler(char *argv);
int		px_output_file_handler(char *argv, int mode);
void	px_write_to_file(int p_fd, int o_fd);
#endif