/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:00:43 by stelie            #+#    #+#             */
/*   Updated: 2023/01/26 14:44:32 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	refresh(t_ptr *c3d)
{
	//secure_free((void **)(&(c3d->ray)));
//mlx_destroy_image(c3d->dply.mlx, c3d->dply.screen);
	background_image(c3d);
	raycasting(c3d);
	mlx_put_image_to_window(c3d->dply.mlx, c3d->dply.win, c3d->dply.screen,
		0, 0);
}

static double	rotate_r(double x, double y, bool is_x)
{
	if (is_x)
		return (x * cos(-ROTATION_SPEED) - (y * sin(-ROTATION_SPEED)));
	return (x * sin(-ROTATION_SPEED) + (y = cos(-ROTATION_SPEED)));
}

static double	rotate_l(double x, double y, bool is_x)
{
	if (is_x)
		return (x * cos(ROTATION_SPEED) - (y * sin(ROTATION_SPEED)));
	return (x * sin(ROTATION_SPEED) + (y = cos(ROTATION_SPEED)));
}

void	rotate(t_ptr *c3d, int key)
{
	double	olddirx;
	double	oldplanex;

	olddirx = c3d->player->dirX;
	oldplanex = c3d->player->planeX;

	if (key == XK_Left)
	{
		c3d->player->dirX = rotate_l(olddirx, c3d->player->dirY, true);
		c3d->player->dirY = rotate_l(olddirx, c3d->player->dirY, false);
		c3d->player->planeX = rotate_l(oldplanex, c3d->player->planeY, true);
		c3d->player->planeY = rotate_l(oldplanex, c3d->player->planeY, false);
		printf("ROTATE LEFT");
	}
	if (key == XK_Right)
	{
		c3d->player->dirX = rotate_r(olddirx, c3d->player->dirY, true);
		c3d->player->dirY = rotate_r(olddirx, c3d->player->dirY, false);
		c3d->player->planeX = rotate_r(oldplanex, c3d->player->planeY, true);
		c3d->player->planeY = rotate_r(oldplanex, c3d->player->planeY, false);
		printf("ROTATE RIGHT");
	}
	refresh(c3d);
}
