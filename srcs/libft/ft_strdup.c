/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:53:25 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/16 14:19:43 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/libft.h"


char	*ft_strdup(const char *s1)
{
	char	*copy;

	if (s1 != NULL)
	{
		copy = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
		if (!copy)
			return (NULL);
		ft_memmove(copy, s1, ft_strlen(s1) + 1);
		return (copy);
	}
	return (NULL);
}
