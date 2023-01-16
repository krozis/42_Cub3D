/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:12:41 by dcyprien          #+#    #+#             */
/*   Updated: 2020/01/07 08:42:06 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (dst != NULL && src != NULL && src != dst && n != 0)
	{
		d = (unsigned char *)dst;
		s = (unsigned char *)src;
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
