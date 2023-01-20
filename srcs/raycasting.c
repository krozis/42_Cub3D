/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:34:00 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/20 22:21:19 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	perform_dda(t_ptr *ptr)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ptr->ray->sideDistX < ptr->ray->sideDistY)
		{
			ptr->ray->sideDistX += ptr->ray->deltaDistX;
			ptr->ray->mapX += ptr->ray->stepX;
			ptr->ray->side = 0;
		}
		else
		{
			ptr->ray->sideDistY += ptr->ray->deltaDistY;
			ptr->ray->mapY += ptr->ray->stepY;
			ptr->ray->side = 1;
		}
		if (ptr->map[ptr->ray->mapY][ptr->ray->mapX] == '1')
			hit = 1;
	}
	return (ptr->ray->side);
}

void	drawline(t_ptr *ptr, int x, int drawend, int drawstart)
{
	int	tmp;

	while (x > 0)
	{
		tmp = drawstart;
		while (tmp < drawend)
		{
			if (ptr->ray->side == 0)
				ptr->dply.screen->data[tmp] = convert_colors(255,0,127);
			else
				ptr->dply.screen->data[tmp] = convert_colors(255,0,127) / 2;
			tmp++;
		}
		x--;
	}
}

void	draw(t_ptr *ptr, int x)
{
	int	lineheight;
	int	drawstart;
	int	drawend;

	lineheight = (int)(WIN_HEIGHT / ptr->ray->perpWallDist);
	drawstart = -lineheight / 2 + WIN_HEIGHT / 2;
	if (drawstart < 0)
		drawstart = 0;
	drawend = lineheight / 2 + WIN_HEIGHT / 2;
	if (drawend >= WIN_HEIGHT)
		drawend = WIN_HEIGHT - 1;
	drawline(ptr, x, drawend, drawstart);
}


void	raycasting(t_ptr *ptr)
{
	int		done;
	int		x;

	x = 0;
	done = 0;
	init_structs(ptr);
	ptr->dply.screen = mlx_new_image(ptr->dply.mlx, WIN_WIDTH, WIN_HEIGHT);
	while (x < WIN_WIDTH)
	{
		x++;
	}
}
