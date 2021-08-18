/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:59:10 by tgrossma          #+#    #+#             */
/*   Updated: 2021/06/28 13:59:10 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int		i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	*trim_memcpy(void *dest, const void *src, size_t n)
{
	char		*ptr1;
	char		*ptr2;
	size_t		i;

	ptr1 = (char *) src;
	ptr2 = (char *) dest;
	i = 0;
	while (i < n)
	{
		ptr2[i] = ptr1[i];
		i++;
	}
	ptr2[i] = '\0';
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			start;
	int			end;
	char		*ptr;

	start = 0;
	end = 0;
	while (s1[end] != 0)
		end++;
	end--;
	while (start <= end && is_set(s1[start], set))
		start++;
	while (end > 0 && is_set(s1[end], set))
		end--;
	if (start > end)
		ptr = (char *)malloc(sizeof(char) * 1);
	else
		ptr = (char *)malloc((end - start + 2) * sizeof(char));
	if (ptr == 0)
		return (0);
	if (start > end)
		ptr[0] = '\0';
	else
		trim_memcpy(ptr, &s1[start], end - start + 1);
	return (ptr);
}
