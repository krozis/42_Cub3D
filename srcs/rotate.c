/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:00:43 by stelie            #+#    #+#             */
/*   Updated: 2023/02/06 17:52:00 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
void	rotate(t_c3d *c3d)
{
	double	olddirx;
	double	oldplanex;

	olddirx = c3d->player->dir_x;
	oldplanex = c3d->player->plane_x;
	if (c3d->keys.rotate_left
		|| (c3d->keys.rotate_mouse_left && c3d->keys.mouse_free == false))
	{
		c3d->player->dir_x
			= rot_l(c3d->player->dir_x, c3d->player->dir_y, true);
		c3d->player->dir_y = rot_l(olddirx, c3d->player->dir_y, false);
		c3d->player->plane_x
			= rot_l(c3d->player->plane_x, c3d->player->plane_y, true);
		c3d->player->plane_y = rot_l(oldplanex, c3d->player->plane_y, false);
	}
	if (c3d->keys.rotate_right
		|| (c3d->keys.rotate_mouse_right && c3d->keys.mouse_free == false))
	{
		c3d->player->dir_x
			= rot_r(c3d->player->dir_x, c3d->player->dir_y, true);
		c3d->player->dir_y = rot_r(olddirx, c3d->player->dir_y, false);
		c3d->player->plane_x
			= rot_r(c3d->player->plane_x, c3d->player->plane_y, true);
		c3d->player->plane_y = rot_r(oldplanex, c3d->player->plane_y, false);
	}
}
