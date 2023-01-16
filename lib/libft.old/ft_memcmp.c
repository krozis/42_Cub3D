/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:08:42 by dcyprien          #+#    #+#             */
/*   Updated: 2020/01/07 08:41:41 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*first;
	unsigned char	*second;

	if (s1 != NULL && s2 != NULL && s1 != s2 && n != 0)
	{
		first = (unsigned char *)s1;
		second = (unsigned char *)s2;
		while (*first == *second && --n > 0)
		{
			first++;
			second++;
		}
		return ((int)(*first - *second));
	}
	return (0);
}
