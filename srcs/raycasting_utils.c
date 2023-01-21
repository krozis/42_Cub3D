/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:20:10 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/21 19:09:37 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_player(t_ptr *ptr)
{
	int	i;
	int	k;

	i = 0;
	ptr->player = malloc(sizeof(t_player));
	if (!ptr->player)
		return ;
	while (ptr->map[i])
	{
		k = 0;
		while (ptr->map[i][k])
		{
			if (ft_incharset(ptr->map[i][k], "NEWS"))
			{
				ptr->player->posX = (double)(k + 0.5);
				ptr->player->posY = (double)(i - 0.5);
				ptr->player->dir = ptr->map[i][k];
				return ;
			}
			k++;
		}
		i++;
	}
}

void	set_raycasting(t_ptr *ptr)
{
	set_player(ptr);
	if (!ptr->ray || !ptr->player)
		return ;
	if (ptr->player->dir == 'N')
	{
		ptr->ray->dirX = 0;
		ptr->ray->dirY = -1;
	}
	if (ptr->player->dir == 'S')
	{
		ptr->ray->dirX = 0;
		ptr->ray->dirY = 1;
	}
	if (ptr->player->dir == 'W')
	{
		ptr->ray->dirX = -1;
		ptr->ray->dirY = 0;
	}
	if (ptr->player->dir == 'E')
	{
		ptr->ray->dirX = 1;
		ptr->ray->dirY = 0;
	}
}

void	drawline(t_ptr *ptr, int x, int drawstart, int drawend, int color)
{
	printf("drawstart = %d\n", drawstart);
	printf("drawend = %d\n", drawend);
	printf("x = %d\n", x);
	while (drawstart <= drawend)
	{
		ptr->dply.screen->data[(drawstart * WIN_WIDTH) + x] = (color % RGB_RED) % RGB_GREEN;
		ptr->dply.screen->data[(drawstart * WIN_WIDTH) + x + 1] = (color % RGB_RED) / RGB_GREEN;
		ptr->dply.screen->data[(drawstart * WIN_WIDTH) + x + 2] = color / RGB_RED;
		drawstart++;
	}
	mlx_put_image_to_window(ptr->dply.mlx, ptr->dply.win, ptr->dply.screen, 0,0);
}