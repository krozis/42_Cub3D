/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:34:00 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/30 14:56:55 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	raycasting_1(t_ptr *ptr, int x)
{
	ptr->ray->cameraX = 2 * x / (double)WIN_WIDTH - 1;
	ptr->ray->raydirX = ptr->player->dirX + ptr->player->planeX
		* ptr->ray->cameraX;
	ptr->ray->raydirY = ptr->player->dirY + ptr->player->planeY
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
		if (ptr->ray->sideDistX <= ptr->ray->sideDistY)
		{
			ptr->ray->sideDistX += ptr->ray->deltaDistX;
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
		ptr->ray->perpWallDist = (ptr->ray->sideDistX - ptr->ray->deltaDistX);
	else
		ptr->ray->perpWallDist = (ptr->ray->sideDistY - ptr->ray->deltaDistY);
	if (ptr->ray->perpWallDist == 0.0)
		ptr->ray->perpWallDist = ptr->ray->oldperpwall;
	ptr->ray->oldperpwall = ptr->ray->perpWallDist;
}

void	raycasting_4(t_ptr *ptr, int x)
{
	int	lineheight;

	lineheight = (int)(WIN_WIDTH / ptr->ray->perpWallDist);
	ptr->ray->drawval[0] = (-lineheight / 2 + WIN_HEIGHT / 2) + 1;
	if (ptr->ray->drawval[0] < 0)
		ptr->ray->drawval[0] = 0;
	ptr->ray->drawval[1] = lineheight / 2 + WIN_HEIGHT / 2;
	if (ptr->ray->drawval[1] >= WIN_HEIGHT)
		ptr->ray->drawval[1] = WIN_HEIGHT - 1;
	ptr->ray->texNum = text_num(ptr);
	drawline(ptr, x);
}

void	raycasting(t_ptr *ptr)
{
	int	x;

	x = 0;
	secure_free((void **)&ptr->ray);
	ptr->ray = malloc(sizeof(t_ray));
	if (!ptr->player)
		init_player(&(ptr->player), ptr->map);
	if (!ptr->dply.screen)
		ptr->dply.screen = mlx_new_image(ptr->dply.mlx, WIN_WIDTH, WIN_HEIGHT);
	while (x < WIN_WIDTH)
	{
		raycasting_1(ptr, x);
		raycasting_2(ptr);
		raycasting_3(ptr);
		raycasting_4(ptr, x);
		x++;
	}
	mlx_put_image_to_window(ptr->dply.mlx, ptr->dply.win, ptr->dply.screen,
		0, 0);
}
