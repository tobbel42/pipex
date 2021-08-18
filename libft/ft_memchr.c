/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:57:47 by tgrossma          #+#    #+#             */
/*   Updated: 2021/06/28 13:57:47 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*ptr;

	ptr = (char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
