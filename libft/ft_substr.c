/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:59:14 by tgrossma          #+#    #+#             */
/*   Updated: 2021/06/28 13:59:14 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*sub_memcpy(void *dest, const void *src, size_t n)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		strlen;
	char		*ptr;

	strlen = 0;
	while (s[strlen] != 0)
		strlen++;
	if (start > strlen)
	{
		ptr = (char *)malloc((1) * sizeof(char));
		if (ptr != 0)
			ptr[0] = '\0';
		return (ptr);
	}
	strlen = strlen - start;
	if (len < strlen)
		strlen = len;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	sub_memcpy(ptr, &s[start], len);
	ptr[len] = '\0';
	return (ptr);
}
