/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:55:59 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/19 12:14:29 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
//searches the env for the path variable, and returns a NULL-terminated array
//of all paths, the array is freeable
*/
char	**px_find_path(char** envp)
{
	int	i;
	char *path;
	char **path_list;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	path = ft_strtrim(envp[i], "PATH=");
	path_list = ft_split(path, ':');
	if (path)
		free(path);
	return (path_list);
}
