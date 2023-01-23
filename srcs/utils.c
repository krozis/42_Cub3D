/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:28:35 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/20 15:18:19 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	empty_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (EXIT_FAILURE);
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ismap(char *str)
{
	int	i;

	i = 0;
	if (empty_line(str) == EXIT_SUCCESS)
		return (EXIT_FAILURE);
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] && ft_isalpha(str[i]))
			return (EXIT_FAILURE);
		if (i >= (int)ft_strlen(str))
			break ;
		i++;
	}
	return (EXIT_SUCCESS);
}
