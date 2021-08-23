/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_split_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 12:07:46 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/23 12:00:35 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "px_split_res.h"

/*
//splits the string ito substring using delimitor c
//everything inside quotes (" or ') is not split
*/
char	**px_split_res(char const *s, char c)
{
	int		n_subs;
	char	**ptr_tab;
	char	*ptr;

	n_subs = find_subs(s, c);
	if (n_subs == -1)
		return (0);
	ptr_tab = (char **)malloc((n_subs + 1) * sizeof(char *));
	if (ptr_tab == 0)
		return (ptr_tab);
	ptr = (char *)s;
	if (fill_tab(ptr_tab, ptr, c, n_subs) == 0)
	{
		free(ptr_tab);
		return (0);
	}
	return (ptr_tab);
}
