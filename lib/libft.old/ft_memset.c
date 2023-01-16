/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:37:10 by dcyprien          #+#    #+#             */
/*   Updated: 2020/01/07 08:42:39 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*buffer;
	size_t			i;

	if (b != NULL)
	{
		i = 0;
		buffer = (unsigned char *)b;
		while (i < len)
		{
			buffer[i] = (unsigned char)c;
			i++;
		}
	}
	return (b);
}
