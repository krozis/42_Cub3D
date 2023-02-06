/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:34:00 by dcyprien          #+#    #+#             */
/*   Updated: 2023/02/06 17:31:37 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	raycasting_1(t_c3d *c3d, int x)
{
	c3d->ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	c3d->ray->raydir_x = c3d->player->dir_x + c3d->player->plane_x
		* c3d->ray->camera_x;
	c3d->ray->raydir_y = c3d->player->dir_y + c3d->player->plane_y
		* c3d->ray->camera_x;
	c3d->ray->map_x = (int)c3d->player->pos_x;
	c3d->ray->map_y = (int)c3d->player->pos_y;
	if (c3d->ray->raydir_y == 0)
		c3d->ray->delta_x = 0;
	else if (c3d->ray->raydir_x == 0)
		c3d->ray->delta_x = 1;
	else
		c3d->ray->delta_x = fabs(1 / c3d->ray->raydir_x);
	if (c3d->ray->raydir_x == 0)
		c3d->ray->delta_y = 0;
	else if (c3d->ray->raydir_y == 0)
		c3d->ray->delta_y = 0;
	else
		c3d->ray->delta_y = fabs(1 / c3d->ray->raydir_y);
}

static void	raycasting_2(t_c3d *c3d)
{
	c3d->ray->hit = 0;
	if (c3d->ray->raydir_x < 0)
	{
		c3d->ray->step_x = -1;
		c3d->ray->side_x = (c3d->player->pos_x - c3d->ray->map_x)
			* c3d->ray->delta_x;
	}
	else
	{
		c3d->ray->step_x = 1;
		c3d->ray->side_x = (c3d->ray->map_x + 1.0 - c3d->player->pos_x)
			* c3d->ray->delta_x;
	}
	if (c3d->ray->raydir_y < 0)
	{
		c3d->ray->step_y = -1;
		c3d->ray->side_y = (c3d->player->pos_y - c3d->ray->map_y)
			* c3d->ray->delta_y;
	}
	else
	{
		c3d->ray->step_y = 1;
		c3d->ray->side_y = (c3d->ray->map_y + 1.0 - c3d->player->pos_y)
			* c3d->ray->delta_y;
	}
}

static void	raycasting_3(t_c3d *c3d)
{
	while (c3d->ray->hit == 0)
	{
		if (c3d->ray->side_x <= c3d->ray->side_y)
		{
			c3d->ray->side_x += c3d->ray->delta_x;
			c3d->ray->map_x += c3d->ray->step_x;
			c3d->ray->side = 1;
		}
		else
		{
			c3d->ray->side_y += c3d->ray->delta_y;
			c3d->ray->map_y += c3d->ray->step_y;
			c3d->ray->side = 0;
		}
		if (c3d->map[c3d->ray->map_y][c3d->ray->map_x] == '1')
			c3d->ray->hit = 1;
	}
	if (c3d->ray->side == 1)
		c3d->ray->perp_dist = (c3d->ray->side_x - c3d->ray->delta_x);
	else
		c3d->ray->perp_dist = (c3d->ray->side_y - c3d->ray->delta_y);
	if (c3d->ray->perp_dist == 0.0)
		c3d->ray->perp_dist = c3d->ray->oldperpwall;
	c3d->ray->oldperpwall = c3d->ray->perp_dist;
}

static void	raycasting_4(t_c3d *c3d, int x)
{
	int	lineheight;

	lineheight = (int)(WIN_WIDTH / c3d->ray->perp_dist);
	c3d->ray->drawval[0] = (-lineheight / 2 + WIN_HEIGHT / 2) + 1;
	if (c3d->ray->drawval[0] < 0)
		c3d->ray->drawval[0] = 0;
	c3d->ray->drawval[1] = lineheight / 2 + WIN_HEIGHT / 2;
	if (c3d->ray->drawval[1] >= WIN_HEIGHT)
		c3d->ray->drawval[1] = WIN_HEIGHT - 1;
	c3d->ray->txt_nb = text_num(c3d);
	drawline(c3d, x);
}

void	raycasting(t_c3d *c3d)
{
	int	x;

	x = 0;
	secure_free((void **)&c3d->ray);
	c3d->ray = malloc(sizeof(t_ray));
	if (!c3d->player)
		init_player(&(c3d->player), c3d->map);
	while (x < WIN_WIDTH)
	{
		raycasting_1(c3d, x);
		raycasting_2(c3d);
		raycasting_3(c3d);
		raycasting_4(c3d, x);
		x++;
	}
}
