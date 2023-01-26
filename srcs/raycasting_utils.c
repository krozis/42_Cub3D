/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:20:10 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/26 13:22:28 by stelie           ###   ########.fr       */
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
				ptr->player->posX = k + 0.5;
				ptr->player->posY = i + 0.5;
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
	ptr->player->planeX = 0;
	ptr->player->planeY = 0.60;
	if (!ptr->ray || !ptr->player)
		return ;
	if (ptr->player->dir == 'N')
	{
		ptr->player->dirX = 0;
		ptr->player->dirY = -1;
	}
	if (ptr->player->dir == 'S')
	{
		ptr->player->dirX = 0;
		ptr->player->dirY = 1;
	}
	if (ptr->player->dir == 'W')
	{
		ptr->player->dirX = -1;
		ptr->player->dirY = 0;
	}
	if (ptr->player->dir == 'E')
	{
		ptr->player->dirX = 1;
		ptr->player->dirY = 0;
	}
}

void	drawline(t_ptr *ptr, int x, int drawstart, int drawend, int color)
{
	/* drawing the line*/
	int	i;

	i = 0;
	while (i < drawstart)
	{
		ptr->dply.screen->data[4 * (i * WIN_WIDTH + x)] = (ptr->ceiling_color / RGB_RED);
		ptr->dply.screen->data[4 * (i * WIN_WIDTH + x) +1] = (ptr->ceiling_color % RGB_RED) / RGB_GREEN;
		ptr->dply.screen->data[4 * (i * WIN_WIDTH + x) + 2] = (ptr->ceiling_color % RGB_RED) % RGB_GREEN;
		i++;
	}
	while (drawstart < drawend)
	{
		ptr->dply.screen->data[4 * (drawstart * WIN_WIDTH + x)] = (color / RGB_RED);
		ptr->dply.screen->data[4 * (drawstart * WIN_WIDTH + x) +1] = (color % RGB_RED) / RGB_GREEN;
		ptr->dply.screen->data[4 * (drawstart * WIN_WIDTH + x) + 2] = (color % RGB_RED) % RGB_GREEN;
		drawstart++;
	}
	/* printing the image, can be moved. used for debug purpose*/
	mlx_put_image_to_window(ptr->dply.mlx, ptr->dply.win, ptr->dply.screen, 0,0);
}