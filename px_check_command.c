/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_check_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:15:59 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/19 16:54:46 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
//searches the env for the path variable, and returns a NULL-terminated array
//of all paths, the array is freeable
*/
static char	**px_gen_paths(char **envp)
{
	int		i;
	char	*temp;
	char	*path;
	char	**path_list;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	temp = ft_strtrim(envp[i], "PATH=");
	if (!temp)
		return (NULL);
	path = ft_strjoin(temp, ":.");
	free(temp);
	path_list = ft_split(path, ':');
	if (path)
		free(path);
	return (path_list);
}

/*
//frees the ft_split of the path
*/
static char	**unwind(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
	return (NULL);
}

static char	**px_gen_full_path(char *arg, char **envp)
{
	int		i;
	char	*path;
	char	*temp;
	char	**paths;

	paths = px_gen_paths(envp);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (!temp)
			return (unwind(paths));
		path = ft_strjoin(temp, arg);
		free(temp);
		if (!path)
			unwind(paths);
		free(paths[i]);
		paths[i] = path;
		i++;
	}
	return (paths);
}

/*
//takes a command as input, and checks the PATH + . if command exist, and if
//pipex has the access rights, returns full path of the command, else NULL
*/
char	*px_check_command(char *arg, char **envp)
{
	char	**paths;
	char	*path;
	int		flag;
	int		i;

	paths = px_gen_full_path(arg, envp);
	if (!paths)
		return (NULL);
	path = NULL;
	flag = 0;
	i = 0;
	while (paths[i])
	{
		if (access(paths[i], X_OK) == 0)
		{
			path = ft_strdup(paths[i]);
			break ;
		}
		else if (errno != 2)
			break ;
		i++;
	}
	unwind(paths);
	return (path);
}
