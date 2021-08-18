/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:21:11 by tgrossma          #+#    #+#             */
/*   Updated: 2021/06/29 16:56:13 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void static	calloc_bzero(void *s, size_t n)
{
	size_t		counter;
	char		*ptr;

	counter = 0;
	ptr = (char *)s;
	while (counter < n)
	{
		ptr[counter] = 0;
		counter++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr != 0)
		calloc_bzero(ptr, count * size);
	return (ptr);
}
