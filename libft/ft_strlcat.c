/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:58:40 by tgrossma          #+#    #+#             */
/*   Updated: 2021/06/28 13:58:40 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dst_len;
	size_t		src_len;
	size_t		i;

	i = 0;
	dst_len = 0;
	while (dst[dst_len] != 0 && dst_len < dstsize)
		dst_len++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dstsize > dst_len)
	{
		while (i < (dstsize - dst_len - 1) && src[i] != '\0')
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
	}
	else
		return (dstsize + src_len);
	return (dst_len + src_len);
}
