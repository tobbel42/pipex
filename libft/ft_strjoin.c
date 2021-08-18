/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:58:36 by tgrossma          #+#    #+#             */
/*   Updated: 2021/06/28 13:58:36 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	join_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

static void	*join_memcpy(void *dest, const void *src, size_t n)
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
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len_s1;
	size_t		len_s2;
	char		*ptr;

	len_s1 = join_strlen(s1);
	len_s2 = join_strlen(s2);
	ptr = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (ptr == 0)
	{
		return (0);
	}
	join_memcpy(ptr, s1, len_s1);
	join_memcpy(ptr + len_s1, s2, len_s2);
	ptr[len_s1 + len_s2] = '\0';
	return (ptr);
}
