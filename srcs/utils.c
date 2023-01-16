/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:28:35 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/16 12:31:10 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/libft.h"

int	ft_cinset(const char c, const char *set)
{
	int	i;

	if (set != NULL)
	{
		i = 0;
		while (set[i])
		{
			if (c == set[i])
				return (1);
			i++;
		}
		return (0);
	}
	return (-1);
}

int	ft_isspace(const char c)
{
	return (ft_cinset(c, "\t\n\r\v\f "));
}

int		ismap(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!isdigit(str[i]) && !isspace(str[i]))
			return (0);
	}
	return (1);
}