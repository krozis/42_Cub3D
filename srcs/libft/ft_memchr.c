/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:46:16 by dcyprien          #+#    #+#             */
/*   Updated: 2022/05/14 03:08:00 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*mem;
	unsigned char	character;
	size_t			i;

	if (s != NULL)
	{
		i = 0;
		mem = (unsigned char *)s;
		character = (unsigned char)c;
		while (i < n)
		{
			if (mem[i] == character)
				return (&mem[i]);
			i++;
		}
	}
	return (NULL);
}
