/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:18:13 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/19 12:29:41 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_empty_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (empty_line(map[i]) == EXIT_SUCCESS)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_chars(char **map)
{
	int	i;
	int	k;
	int	player;

	player = 0;
	i = 0;
	while (map[i])
	{
		k = -1;
		while (map[i][++k])
		{
			if (ft_incharset(map[i][k], "NSEW01 \n") == false)
				return (EXIT_FAILURE);
			if (ft_incharset(map[i][k], "NSEW") && player == 0)
				player = 1;
			else if (ft_incharset(map[i][k], "NSEW") && player == 1)
				return (ERR_TWO_START);
		}
		i++;
	}
	if (player == 0)
		return (ERR_NO_START);
	return (EXIT_SUCCESS);
}

int	check_closed_map(char **map)
{
	int	i;
	int	k;

	i = 0;
	while (map[i])
	{
		k = -1;
		while (map[i][++k])
			if (map[i][k] == '0' && check_ones(map, i, k) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_borders(char **map)
{
	int	i;
	int	k;

	i = 0;
	k = -1;
	while (map[i][++k])
		if (map[i][k] != '1' && !ft_isspace(map[i][k]))
			return (EXIT_FAILURE);
	while (map[i])
	{
		k = 0;
		while (map[i][k] && ft_isspace(map[i][k]))
			k++;
		if (map[i][k] != '1')
			return (EXIT_FAILURE);
		if (map[i][ft_strlen(map[i]) - 2] != '1')
			return (EXIT_FAILURE);
		i++;
	}
	k = -1;
	while (map[i - 1][++k])
		if (map[i - 1][k] != '1' && !ft_isspace(map[i - 1][k]))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_integrity(char **map)
{
	int	k;

	(void)k;
	if (check_borders(map) == EXIT_FAILURE
		|| check_closed_map(map) == EXIT_FAILURE)
		return (ft_putmsg_fd("Error\nMap is not closed\n", 2, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}
