/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:16:21 by stelie            #+#    #+#             */
/*   Updated: 2023/01/26 16:41:30 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	get_initial_direction(t_player **player, char dir)
{
	if (dir == 'N')
	{
		(*player)->dirX = 0.;
		(*player)->dirY = -1.;
	}
	else if (dir == 'W')
	{
		(*player)->dirX = -1.;
		(*player)->dirY = 0.;
	}
	else if (dir == 'E')
	{
		(*player)->dirX = 1.;
		(*player)->dirY = 0.;
	}
	else
	{
		(*player)->dirX = 0.;
		(*player)->dirY = 1.;
	}
	(*player)->planeX = (*player)->dirY * -0.60;
	(*player)->planeY = (*player)->dirX * 0.60;
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
				(*player)->posX = j + 0.5;
				(*player)->posY = i + 0.5;
				get_initial_direction(player, map[i][j]);
				return (EXIT_SUCCESS);
			}
			j++;
		}
		i++;
	}
	return (EXIT_FAILURE);
}
