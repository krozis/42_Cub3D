/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:44:43 by dcyprien          #+#    #+#             */
/*   Updated: 2020/01/07 08:48:25 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	len;

	if (s1 != NULL && set != NULL)
	{
		i = 0;
		len = ft_strlen(s1);
		while (ft_cinset(s1[i], set))
			i++;
		while (ft_cinset(s1[len - 1], set) && len > 1)
			len--;
		if (len == 1)
			return (ft_strdup("\0"));
		return (ft_substr(s1, i, len - i));
	}
	return (ft_strdup("\0"));
}
