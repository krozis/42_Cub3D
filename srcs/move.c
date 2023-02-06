/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:12:04 by dcyprien          #+#    #+#             */
/*   Updated: 2023/02/06 17:31:37 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	go_front(t_c3d *c3d)
{
	if (c3d->keys.move_front)
	{
		if (c3d->map[(int)c3d->player->pos_y][(int)(c3d->player->pos_x
			+ c3d->player->dir_x * MOVE_SPEED)] != '1')
			c3d->player->pos_x += c3d->player->dir_x * MOVE_SPEED;
		if (c3d->map[(int)(c3d->player->pos_y + c3d->player->dir_y
				* MOVE_SPEED)][(int)c3d->player->pos_x] != '1')
			c3d->player->pos_y += c3d->player->dir_y * MOVE_SPEED;
	}
}

static void	go_back(t_c3d *c3d)
{
	if (c3d->keys.move_back)
	{
		if (c3d->map[(int)c3d->player->pos_y][(int)(c3d->player->pos_x
			- c3d->player->dir_x * MOVE_SPEED)] != '1')
			c3d->player->pos_x -= c3d->player->dir_x * MOVE_SPEED;
		if (c3d->map[(int)(c3d->player->pos_y - c3d->player->dir_y
				* MOVE_SPEED)][(int)c3d->player->pos_x] != '1')
			c3d->player->pos_y -= c3d->player->dir_y * MOVE_SPEED;
	}
}

static void	go_left(t_c3d *c3d)
{
	if (c3d->keys.move_left)
	{
		if (c3d->player->pos_x - c3d->player->plane_x * MOVE_SPEED >= 0)
		{
			if (c3d->map[(int)c3d->player->pos_y][(int)(c3d->player->pos_x
				- c3d->player->plane_x * MOVE_SPEED)] != '1')
				c3d->player->pos_x -= c3d->player->plane_x * MOVE_SPEED;
		}
		if (c3d->player->pos_y - c3d->player->plane_y * MOVE_SPEED >= 0)
		{
			if (c3d->map[(int)(c3d->player->pos_y - c3d->player->plane_y
					* MOVE_SPEED)][(int)c3d->player->pos_x] != '1')
				c3d->player->pos_y -= c3d->player->plane_y * MOVE_SPEED;
		}
	}
}

static void	go_right(t_c3d *c3d)
{
	if (c3d->keys.move_right)
	{
		if (c3d->player->pos_x - c3d->player->plane_x * MOVE_SPEED >= 0)
		{
			if (c3d->map[(int)c3d->player->pos_y][(int)(c3d->player->pos_x
				+ c3d->player->plane_x * MOVE_SPEED)] != '1')
				c3d->player->pos_x += c3d->player->plane_x * MOVE_SPEED;
		}
		if (c3d->player->pos_y - c3d->player->plane_y * MOVE_SPEED >= 0)
		{
			if (c3d->map[(int)(c3d->player->pos_y + c3d->player->plane_y
					* MOVE_SPEED)][(int)c3d->player->pos_x] != '1')
				c3d->player->pos_y += c3d->player->plane_y * MOVE_SPEED;
		}
	}
}

/**
 * @brief move function who calls the left/right/front/back movements.
 * @param c3d: a pointer to the main cub3D structure
 */
void	move(t_c3d *c3d)
{
	go_front(c3d);
	go_back(c3d);
	go_left(c3d);
	go_right(c3d);
}
