/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:16:21 by stelie            #+#    #+#             */
/*   Updated: 2023/02/01 18:49:24 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	get_initial_direction(t_player **player, char dir)
{
	if (dir == 'N')
	{
		(*player)->dir_x = 0.;
		(*player)->dir_y = -1.;
	}
	else if (dir == 'W')
	{
		(*player)->dir_x = -1.;
		(*player)->dir_y = 0.;
	}
	else if (dir == 'E')
	{
		(*player)->dir_x = 1.;
		(*player)->dir_y = 0.;
	}
	else
	{
		(*player)->dir_x = 0.;
		(*player)->dir_y = 1.;
	}
	(*player)->plane_x = (*player)->dir_y * -0.60;
	(*player)->plane_y = (*player)->dir_x * 0.60;
}

/**
 * @brief Initialize player's variables depending on the given 'NSEW' direction.
 * @param player pointer to the *player struct.
 * @param map pointer to the map tab.
 * @return EXIT_FAILURE or EXIT_SUCCESS
 */
int	init_player(t_player **player, char **map)
{
	int	i;
	int	j;

	*player = malloc(sizeof(t_player));
	if (!*player)
		return (EXIT_FAILURE);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_incharset(map[i][j], "NEWS"))
			{
				(*player)->pos_x = j + 0.5;
				(*player)->pos_y = i + 0.5;
				get_initial_direction(player, map[i][j]);
				return (EXIT_SUCCESS);
			}
			j++;
		}
		i++;
	}
	return (EXIT_FAILURE);
}
