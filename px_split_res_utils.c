/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_split_res_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:22:34 by tgrossma          #+#    #+#             */
/*   Updated: 2021/08/23 11:59:50 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	quote_skip(char const *s, int *i)
{
	char	quote;

	quote = s[*i];
	*i = *i + 1;
	while (s[*i] && s[*i] != quote)
		*i = *i + 1;
	if (s[*i] == '\0')
		return (0);
	return (1);
}

int	find_subs(char const *s, char c)
{
	int		i;
	int		del_flag;
	int		n_subs;

	i = 0;
	del_flag = 1;
	n_subs = 0;
	while (s[i] != '\0')
	{
		if (s[i] == 34 || s[i] == 39)
		{
			if (quote_skip(s, &i) == 0)
				return (-1);
		}
		if (s[i] != c && del_flag == 1)
		{
			n_subs++;
			del_flag = 0;
		}
		else if (s[i] == c && del_flag == 0)
			del_flag = 1;
		i++;
	}
	return (n_subs);
}

int	unwind(char **ptr_tab, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		free(ptr_tab[i]);
		i++;
	}
	return (0);
}

int	fill_tab(char **ptr_tab, char *ptr, char c, int n_subs)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (i < n_subs)
	{	
		while (ptr[j] == c)
			j++;
		start = j;
		while (ptr[j] != c && ptr[j] != 0)
		{
			if (ptr[j] == 34 || ptr[j] == 39)
				quote_skip(ptr, &j);
			j++;
		}
		ptr_tab[i] = (char *)malloc((j - start + 1) * sizeof(char));
		if (ptr_tab[i] == 0)
			return (unwind(ptr_tab, i));
		ft_strlcpy(ptr_tab[i], &ptr[start], j - start + 1);
		i++;
	}
	ptr_tab[n_subs] = 0;
	return (1);
}
