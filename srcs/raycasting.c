/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:34:00 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/21 15:41:23 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	raycasting_1(t_ptr *ptr)
{
	ptr->ray->cameraX = 2 * x / (double)WIN_WIDTH - 1;
	ptr->ray->raydirX = ptr->ray->dirX + ptr->ray->planeX
		* ptr->ray->cameraX;
	ptr->ray->raydirY = ptr->ray->dirY + ptr->ray->planeY
		* ptr->ray->cameraX;
	ptr->ray->mapX = (int)ptr->player->posX;
	ptr->ray->mapY = (int)ptr->player->posY;
	if (ptr->ray->raydirY == 0)
		ptr->ray->deltadistX = 0;
	else if (ptr->ray->raydirX == 0)
		ptr->ray->deltaDistX = 1;
	else
		ptr->ray->deltadistX = ft_abs(1 / ptr->ray->raydirX);
	if (ptr->ray->raydirX == 0)
		ptr->ray->deltadistY = 0;
	else if (ptr->ray->raydirY == 0)
		ptr->ray->deltaDistY = 0;
	else
		ptr->ray->deltadistY = ft_abs(1 / ptr->ray->raydirY);
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
	if (ptr->rayDirY < 0)
	{
		ptr->ray->stepY = -1;
		ptr->sideDistY = (ptr->player->posY - ptr->ray->mapY)
			* ptr->ray->deltaDistY;
	}
	else
	{
		ptr->ray->stepX = 1;
		ptr->ray->sideDistX = (ptr->ray->mapY + 1.0 - ptr->player->posY)
			* ptr->ray->deltaDistY;
	}
}

void	raycasting_3(t_ptr *ptr)
{
	while (ptr->ray->hit == 0)
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
		if (ptr->map[y][x] == '1')
			ptr->ray->hit = 1;
	}
	if (ptr->ray->side == 0)
		ptr->ray->perpWallDist = (ptr->ray->sideDistX - ptr->ray->deltaDistX);
	else
		ptr->ray->perpWallDist = (ptr->ray->sideDistY - ptr->ray->deltaDistY);
}

void	raycasting_4(t_ptr *ptr, int x)
{
	int	lineHeight;
	int	drawstart;
	int	drawend;

	lineHeight = (int)(WIN_WIDTH / ptr->ray->perpWallDist);
	drawstart = -lineHeight / 2 + WIN_WIDTH / 2;
	if (drawstart < 0)
		drawstart = 0;
	drawend = lineHeight / 2 + WIN_WIDTH / 2;
	if (drawend >= WIN_WIDTH)
		drawend = WIN_WIDTH - 1;
	drawline(x, drawstart, drawend, convert_colors(127,0,127));
}

void	raycasting(t_ptr *ptr)
{
	int	x;

	x = 0;
	
	ptr->ray = malloc(sizeof(t_ray));
	set_raycasting(ptr);
	ptr->ray->planeX = 0;
	ptr->ray->planeY = 0.66;
	ptr->dply.screen = mlx_new_image(ptr->dply.mlx, WIN_WIDTH, WIN_HEIGHT);
	while (x < WIN_WIDTH)
	{
		raycasting_1(ptr);
		raycasting_2(ptr);
		raycasting_3(ptr);
		raycasting_4(ptr, x);
		x++;
	}
	for(int x = 0; x < w; x++)
	{

      double sideDistX;
      double sideDistY;

       //length of ray from one x or y-side to next x or y-side
      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?
	       //perform DDA
      while (hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
        if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if (worldMap[mapX][mapY] > 0) hit = 1;
      } 
	        //Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
      if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);
	      //Calculate height of line to draw on screen
      int lineHeight = (int)(h / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + h / 2;
      if(drawStart < 0)drawStart = 0;
      int drawEnd = lineHeight / 2 + h / 2;
      if(drawEnd >= h)drawEnd = h - 1;
	        //choose wall color
      ColorRGB color;
      switch(worldMap[mapX][mapY])
      {
        case 1:  color = RGB_Red;  break; //red
        case 2:  color = RGB_Green;  break; //green
        case 3:  color = RGB_Blue;   break; //blue
        case 4:  color = RGB_White;  break; //white
        default: color = RGB_Yellow; break; //yellow
      }

      //give x and y sides different brightness
      if (side == 1) {color = color / 2;}

      //draw the pixels of the stripe as a vertical line
      verLine(x, drawStart, drawEnd, color);
    }

}
