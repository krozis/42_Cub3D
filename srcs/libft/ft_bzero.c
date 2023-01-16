/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:04:55 by dcyprien          #+#    #+#             */
/*   Updated: 2022/05/14 03:56:36 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*buffer;
	size_t			i;

	if (s != NULL)
	{
		i = 0;
		buffer = (unsigned char *)s;
		while (i < n)
		{
			buffer[i] = 0;
			i++;
		}
	}
}
