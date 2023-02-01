/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:00:43 by stelie            #+#    #+#             */
/*   Updated: 2023/02/01 16:58:43 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	refresh(t_ptr *c3d)
{
	static int		fps;
	static clock_t	clock_cur;

	if (clock() != clock_cur)
		fps = CLOCKS_PER_SEC / (clock() - clock_cur);
	//mlx_destroy_image(c3d->dply.mlx, c3d->dply.screen);
	background_image(c3d);
	raycasting(c3d);
	move(c3d);
	rotate(c3d);
//	minimap(c3d);
	mlx_put_image_to_window(c3d->dply.mlx, c3d->dply.win, c3d->dply.screen,
		0, 0);
	mlx_string_put(c3d->dply.mlx, c3d->dply.win, 10, 20,0x00FB50FF, "FPS");
	mlx_string_put(c3d->dply.mlx, c3d->dply.win, 35, 20, 0x00FB50FF, \
		(char []){'0' + fps / 100, '0' + fps / 10 % 10, '0' + fps % 10, '\0'});
	return (0);
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

/**
 * @brief Rotate left or right (with arrow keys or mouse movements)
 * @param c3d: Takes a pointer to the main structure.
 */
void	rotate(t_ptr *c3d)
{
	double	olddirx;
	double	oldplanex;

	olddirx = c3d->player->dirX;
	oldplanex = c3d->player->planeX;
	if (c3d->keys.rotate_left)
	{
		c3d->player->dirX = rot_l(c3d->player->dirX, c3d->player->dirY, true);
		c3d->player->dirY = rot_l(olddirx, c3d->player->dirY, false);
		c3d->player->planeX
			= rot_l(c3d->player->planeX, c3d->player->planeY, true);
		c3d->player->planeY = rot_l(oldplanex, c3d->player->planeY, false);
	}
	if (c3d->keys.rotate_right)
	{
		c3d->player->dirX = rot_r(c3d->player->dirX, c3d->player->dirY, true);
		c3d->player->dirY = rot_r(olddirx, c3d->player->dirY, false);
		c3d->player->planeX
			= rot_r(c3d->player->planeX, c3d->player->planeY, true);
		c3d->player->planeY = rot_r(oldplanex, c3d->player->planeY, false);
	}
}
