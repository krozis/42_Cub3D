/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:56:59 by dcyprien          #+#    #+#             */
/*   Updated: 2020/01/07 08:41:06 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	if (dst != NULL && src != NULL && src != dst)
	{
		i = 0;
		s = (unsigned char *)src;
		d = (unsigned char *)dst;
		while (i < n)
		{
			d[i] = s[i];
			if (s[i] == (unsigned char)c)
				return (d + i + 1);
			i++;
		}
	}
	return (NULL);
}
