/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:28:35 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/16 18:33:59 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ismap(char *str)
{
	int	i;

	i = 0;
	if (empty_line(str))
		return (0);
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (ft_isalpha(str[i]))
			return (0);
		i++;
	}
	return (1);
}
