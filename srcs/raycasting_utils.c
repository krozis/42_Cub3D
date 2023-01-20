/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:35:20 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/20 20:08:55 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_player(t_ptr *ptr)
{
	int	i;
	int	k;

	i = 0;
	ptr->player = malloc(sizeof(t_player));
	while(ptr->map[i])
	{
		k = 0;
		while(ptr->map[i][k])
		{
			if (ft_incharset(ptr->map[i][k], "NEWS"))
			{
				ptr->player->posX = k;
				ptr->player->posY = i;
				return ;
			}
			k++;
		}
		i++;
	}
}

void	set_dir(t_ptr *ptr, char c)
{
	if (c == 'N')
	{
		ptr->ray->dirX = 0;
		ptr->ray->dirY = -1;
	}
	if (c == 'E')
	{
		ptr->ray->dirX = 1;
		ptr->ray->dirY = 0;
	}
	if (c == 'W')
	{
		ptr->ray->dirX = -1;
		ptr->ray->dirY = 0;
	}
	if (c == 'S')
	{
		ptr->ray->dirX = 0;
		ptr->ray->dirY = 1;
	}
}

void	init_ray(t_ptr *ptr)
{
	int	i;
	int	k;

	i = 0;
	ptr->ray = malloc(sizeof(t_ray));
	ptr->ray->planeX = 0;
	ptr->ray->planeY = 0.66;
	while (ptr->map[i])
	{
		k = 0;
		while (ptr->map[i][k])
		{
			if (ft_incharset(ptr->map[i][k], "NEWS"))
			{
				set_dir(ptr, ptr->map[i][k]);
				return ;
			}
			k++;
		}
		i++;
	}
}

void	init_structs(t_ptr *ptr)
{
	init_player(ptr);
	init_ray(ptr);
}
