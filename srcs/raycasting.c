/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:34:00 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/26 15:51:28 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	raycasting_1(t_ptr *ptr, int x)
{
	/* setting up cameraX. cameraX is the X coordinate on the camera plane for the X pixel that is on the screen*/
	ptr->ray->cameraX = 2 * x / (double)WIN_WIDTH - 1;
	/* setting up ray directions*/
	ptr->ray->raydirX = ptr->player->dirX + ptr->player->planeX // player->dirX = player's dir X ?
		* ptr->ray->cameraX;
	ptr->ray->raydirY = ptr->player->dirY + ptr->player->planeY // player->dirY = player's dir Y ?
		* ptr->ray->cameraX;
	/* setting up starting position of the ray */
	ptr->ray->mapX = (int)ptr->player->posX;
	ptr->ray->mapY = (int)ptr->player->posY;
	/* setting up distance between the next X or Y side and the one after*/
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
	/* setting up step to increment the ray depending on the direction the player is looking*/
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
	/* Loop and incrementation of sideDist which are the distance between the ray position and the next Y/X side*/
	/* mapX/mapY are the coordinate of where the ray is (which tile the ray is looking at)*/
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
		/* check if we hit a wall*/
		if (ptr->map[ptr->ray->mapY][ptr->ray->mapX] == '1')
			ptr->ray->hit = 1;
	}
	/* calculating the perpendicular distance between the camera plane and the wall.*/
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

	/* calculating height of the vertical line to draw*/
	lineHeight = (int)(WIN_HEIGHT / ptr->ray->perpWallDist);
	/* calculating the Y coordinate of the firs * @param dirX: direction X of the player (which side the player is facing). Can be 1, -1 or 0
 * @param dirY: direction Y of the player (which side the player is facing). Can be 1, -1 or 0
 * @param planeX: value X of the camera plane
 * @param planeY: value Y of the camera planet pixel of the line*/
	drawstart = (-lineHeight / 2 + WIN_HEIGHT / 2) + 1;
	if (drawstart < 0)
		drawstart = 0;
	/* calculating the Y coordinate of the last pixel of the line*/
	drawend = lineHeight / 2 + WIN_HEIGHT / 2;
	if (drawend >= WIN_HEIGHT)
		drawend = WIN_HEIGHT - 1;
	/* drawing the line to the mlx image. x is the postion in the width, drawstart is the y coordinate of the first pixel and drawend the last y coordinate*/
	/* the line to draw then have for coordinate x = x and y = drawstart++ until drawend*/
	drawline(ptr, x, drawstart, drawend, convert_colors(255,0,152));
}

void	raycasting(t_ptr *ptr)
{
	int	x;

	x = 0;
	ptr->ray = malloc(sizeof(t_ray));
	if (!(ptr->player))
		init_player(&(ptr->player), ptr->map);
	if (!ptr->dply.screen)
		ptr->dply.screen = mlx_new_image(ptr->dply.mlx, WIN_WIDTH, WIN_HEIGHT);
	//set_raycasting(ptr);
	//ptr->dply.screen = mlx_new_image(ptr->dply.mlx, WIN_WIDTH, WIN_HEIGHT);
	/* Send rays for the whole width of the window*/
	while (x < (WIN_WIDTH))
	{
		raycasting_1(ptr, x);
		raycasting_2(ptr);
		raycasting_3(ptr);
		raycasting_4(ptr, x);
		x++;
	}
}
