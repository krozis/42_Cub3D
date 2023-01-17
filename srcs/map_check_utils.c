/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:10:43 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/17 13:34:53 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_up(char **map, int i, int k)
{
	while (i != 0)
	{
		if (map[i][k] == '1')
			return (EXIT_SUCCESS);
		if (map[i][k] == ' ')
			return (EXIT_FAILURE);
		i--;
	}
	if (map[i][k] == '1')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	check_down(char **map, int i, int k)
{
	while (map[i])
	{
		if (map[i][k] == '1')
			return (EXIT_SUCCESS);
		if (map[i][k] == ' ')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_FAILURE);
}

int	check_right(char **map, int i, int k)
{
	while(map[i][k])
	{
		if (map[i][k] == '1')
			return (EXIT_SUCCESS);
		if (map[i][k] == ' ')
			return (EXIT_FAILURE);
		k++;
	}
	return (EXIT_FAILURE);
}

int	check_left(char **map, int i, int k)
{
	while (k != 0)
	{
		if (map[i][k] == '1')
			return (EXIT_SUCCESS);
		if (map[i][k] == ' ')
			return (EXIT_FAILURE);
		k--;
	}
	if (map[i][k] == '1')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	check_ones(char **map, int i, int k)
{
	if (check_up(map, i, k) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_down(map, i, k) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_right(map, i, k) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_left(map, i, k) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}