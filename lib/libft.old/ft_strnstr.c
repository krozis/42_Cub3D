/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:13:33 by dcyprien          #+#    #+#             */
/*   Updated: 2022/05/14 02:55:22 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;

	if (haystack != NULL && needle != NULL && *needle)
	{
		n = ft_strlen(needle);
		while (*haystack && len-- >= n)
		{
			if (ft_strncmp(haystack, needle, n) == 0)
				return ((char *)haystack);
			haystack++;
		}
		return (NULL);
	}
	return ((char *)haystack);
}
