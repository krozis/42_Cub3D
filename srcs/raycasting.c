/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:34:00 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/21 23:44:29 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	raycasting_1(t_ptr *ptr, int x)
{
	ptr->ray->cameraX = 2 * x / (double)WIN_WIDTH - 1;
	ptr->ray->raydirX = ptr->ray->dirX + ptr->ray->planeX
		* ptr->ray->cameraX;
	ptr->ray->raydirY = ptr->ray->dirY + ptr->ray->planeY
		* ptr->ray->cameraX;
	ptr->ray->mapX = (int)ptr->player->posX;
	ptr->ray->mapY = (int)ptr->player->posY;
	if (ptr->ray->raydirY == 0)
		ptr->ray->deltaDistX = 0;
	else if (ptr->ray->raydirX == 0)
		ptr->ray->deltaDistX = 1;
	else
		ptr->ray->deltaDistX = fabs(1 / ptr->ray->raydirX);
	if (ptr->ray->raydirX == 0)
		ptr->ray->deltaDistY = 0;
	else if (ptr->ray->raydirY == 0)
		ptr->ray->deltaDistY = 0;
	else
		ptr->ray->deltaDistY = fabs(1 / ptr->ray->raydirY);
}

void	raycasting_2(t_ptr *ptr)
{
	ptr->ray->hit = 0;
	if (ptr->ray->raydirX < 0)
	{
		ptr->ray->stepX = -1;
		ptr->ray->sideDistX = (ptr->player->posX - ptr->ray->mapX)
			* ptr->ray->deltaDistX;
	}
	else
	{
		ptr->ray->stepX = 1;
		ptr->ray->sideDistX = (ptr->ray->mapX + 1.0 - ptr->player->posX)
			* ptr->ray->deltaDistX;
	}
	if (ptr->ray->raydirY < 0)
	{
		ptr->ray->stepY = -1;
		ptr->ray->sideDistY = (ptr->player->posY - ptr->ray->mapY)
			* ptr->ray->deltaDistY;
	}
	else
	{
		ptr->ray->stepY = 1;
		ptr->ray->sideDistY = (ptr->ray->mapY + 1.0 - ptr->player->posY)
			* ptr->ray->deltaDistY;
	}
}

void	raycasting_3(t_ptr *ptr)
{
	while (ptr->ray->hit == 0)
	{
		if (ptr->ray->sideDistX < ptr->ray->sideDistY)
		{
			ptr->ray->sideDistX +=  ptr->ray->deltaDistX;
			ptr->ray->mapX += ptr->ray->stepX;
			ptr->ray->side = 1;
		}
		else
		{
			ptr->ray->sideDistY += ptr->ray->deltaDistY;
			ptr->ray->mapY += ptr->ray->stepY;
			ptr->ray->side = 0;
		}
		if (ptr->map[ptr->ray->mapY][ptr->ray->mapX] == '1')
			ptr->ray->hit = 1;
	}
	if (ptr->ray->side == 1)
		ptr->ray->perpWallDist = (ptr->ray->mapX - ptr->player->posX + (1 - ptr->ray->stepX) / 2) / ptr->ray->raydirX;
	else
		ptr->ray->perpWallDist = (ptr->ray->mapY - ptr->player->posY + (1 - ptr->ray->stepY) / 2) / ptr->ray->raydirY;
	if (ptr->ray->perpWallDist < 0.001)
		ptr->ray->perpWallDist = 0.001;
}

void	raycasting_4(t_ptr *ptr, int x)
{
	int	lineHeight;
	int	drawstart;
	int	drawend;

	lineHeight = (int)(WIN_WIDTH / ptr->ray->perpWallDist);
	drawstart = (-lineHeight / 2 + WIN_WIDTH / 2) + 1;
	if (drawstart < 0)
		drawstart = 0;
	drawend = lineHeight / 2 + WIN_WIDTH / 2;
	if (drawend >= WIN_WIDTH)
		drawend = WIN_WIDTH - 1;
	drawline(ptr, x, drawstart, drawend, convert_colors(255,0,152));
}

void	raycasting(t_ptr *ptr)
{
	int	x;

	x = 0;
	ptr->ray = malloc(sizeof(t_ray));
	set_raycasting(ptr);
	ptr->ray->planeX = 0;
	ptr->ray->planeY = 0.60;
	ptr->dply.screen = mlx_new_image(ptr->dply.mlx, WIN_WIDTH, WIN_HEIGHT);
	while (x < (WIN_WIDTH))
	{
		raycasting_1(ptr, x);
		raycasting_2(ptr);
		raycasting_3(ptr);
		raycasting_4(ptr, x);
		x++;
	}
}
