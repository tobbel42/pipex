/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:35:12 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/13 15:58:23 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "ft_get_next_line/get_next_line.h"

int	main(void)
{	
	int pi[2];
	pipe(pi);
	int pid = fork();
	if (pid == 0)
	{
		char *const argv [] = { "cat", "test.c" , NULL};
		char *const envp [] = { NULL };
		close(pi[0]);
		dup2(pi[1], 1);
		
		int p = execve("/bin/cat", argv, envp);
		printf("ERROR\n");
	}
	else
		wait(NULL);
	close (pi[1]);

	int p2[2];
	pipe(p2);
	pid = fork();
	if (pid == 0)
	{
		char *const argv [] = { "head", "-n5" , NULL};
		char *const envp [] = { NULL };
		close(p2[0]);
		dup2(pi[0], 0);
		dup2(p2[1], 1);
		int p = execve("/usr/bin/head", argv, envp);
		printf("ERROR\n");
	}
	else
		wait(NULL);
	close (p2[1]);
	char *line = get_next_line(p2[0]);
	while (line)
	{
		printf("%s", line);
		line = get_next_line(p2[0]);
	}
	close(p2[0]);
	return (0);
}
