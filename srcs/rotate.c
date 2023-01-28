/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:00:43 by stelie            #+#    #+#             */
/*   Updated: 2023/01/28 17:08:32 by dcyprien         ###   ########.fr       */
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

static double	rot_r(double x, double y, bool is_x)
{
	if (is_x)
		return (x * cos(ROTATION_SPEED) - (y * sin(ROTATION_SPEED)));
	return (x * sin(ROTATION_SPEED) + (y * cos(ROTATION_SPEED)));
}

static double	rot_l(double x, double y, bool is_x)
{
	if (is_x)
		return (x * cos(-ROTATION_SPEED) - (y * sin(-ROTATION_SPEED)));
	return (x * sin(-ROTATION_SPEED) + (y * cos(-ROTATION_SPEED)));
}

void	rotate(t_ptr *c3d, int key)
{
	double	olddirx;
	double	oldplanex;

	olddirx = c3d->player->dirX;
	oldplanex = c3d->player->planeX;
	if (key == XK_Left)
	{
		c3d->player->dirX = rot_l(c3d->player->dirX, c3d->player->dirY, true);
		c3d->player->dirY = rot_l(olddirx, c3d->player->dirY, false);
		c3d->player->planeX
			= rot_l(c3d->player->planeX, c3d->player->planeY, true);
		c3d->player->planeY = rot_l(oldplanex, c3d->player->planeY, false);
	}
	if (key == XK_Right)
	{
		c3d->player->dirX = rot_r(c3d->player->dirX, c3d->player->dirY, true);
		c3d->player->dirY = rot_r(olddirx, c3d->player->dirY, false);
		c3d->player->planeX
			= rot_r(c3d->player->planeX, c3d->player->planeY, true);
		c3d->player->planeY = rot_r(oldplanex, c3d->player->planeY, false);
	}
	refresh(c3d);
}
