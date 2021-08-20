/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 12:08:47 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/20 14:06:30 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	char **list;

	if (argc != 2)
	{
		write (2, "Error\n", 6);
		return(0);
	}
	list = px_split_res(argv[1], ' ');
	int i = 0;
	while (list[i])
	{
		printf("%s\n", ft_strtrim(list[i], "\""));
		i++;
	}
	execve(px_check_command(list[0], envp), list, envp);
	return (1);
}