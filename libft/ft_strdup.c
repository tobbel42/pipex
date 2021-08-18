/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:30:02 by tgrossma          #+#    #+#             */
/*   Updated: 2021/06/30 11:32:55 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*ptr;
	size_t		len;

	len = 0;
	while (s1[len] != '\0')
		len++;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr != 0)
	{
		len = 0;
		while (s1[len] != 0)
		{
			ptr[len] = s1[len];
			len++;
		}
		ptr[len] = s1[len];
	}
	return (ptr);
}
