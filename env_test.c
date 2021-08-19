#include <stdio.h>
#include "libft/libft.h"
#include <unistd.h>

int main (int argc, char **argv, char **envp)
{
	int i = 0;
	char *path;
	while (envp[i])
	{
		if (!ft_strncmp("PATH=", envp[i], 5))
		{
			path = envp[i];
			break ;
		}
		i++;
	}
	

	path = ft_strtrim(path, "PATH=");
	char **p_list = ft_split(path, ':');
	i = 0;
	while (p_list[i])
	{
		printf("%s\n", p_list[i]);
		//execve(p_list[1], { "cat", "env_test.c", NULL}, { NULL });
		i++;
	}

	return(0);
}