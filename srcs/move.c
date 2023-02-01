/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:12:04 by dcyprien          #+#    #+#             */
/*   Updated: 2023/02/01 18:49:24 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	go_front(t_ptr *ptr)
{
	if (ptr->keys.move_front)
	{
		if (ptr->map[(int)ptr->player->pos_y][(int)(ptr->player->pos_x
			+ ptr->player->dir_x * MOVE_SPEED)] != '1')
			ptr->player->pos_x += ptr->player->dir_x * MOVE_SPEED;
		if (ptr->map[(int)(ptr->player->pos_y + ptr->player->dir_y
				* MOVE_SPEED)][(int)ptr->player->pos_x] != '1')
			ptr->player->pos_y += ptr->player->dir_y * MOVE_SPEED;
	}
}

static void	go_back(t_ptr *ptr)
{
	if (ptr->keys.move_back)
	{
		if (ptr->map[(int)ptr->player->pos_y][(int)(ptr->player->pos_x
			- ptr->player->dir_x * MOVE_SPEED)] != '1')
			ptr->player->pos_x -= ptr->player->dir_x * MOVE_SPEED;
		if (ptr->map[(int)(ptr->player->pos_y - ptr->player->dir_y
				* MOVE_SPEED)][(int)ptr->player->pos_x] != '1')
			ptr->player->pos_y -= ptr->player->dir_y * MOVE_SPEED;
	}
}

static void	go_left(t_ptr *ptr)
{
	if (ptr->keys.move_left)
	{
		if (ptr->player->pos_x - ptr->player->plane_x * MOVE_SPEED >= 0)
		{
			if (ptr->map[(int)ptr->player->pos_y][(int)(ptr->player->pos_x
				- ptr->player->plane_x * MOVE_SPEED)] != '1')
				ptr->player->pos_x -= ptr->player->plane_x * MOVE_SPEED;
		}
		if (ptr->player->pos_y - ptr->player->plane_y * MOVE_SPEED >= 0)
		{
			if (ptr->map[(int)(ptr->player->pos_y - ptr->player->plane_y
					* MOVE_SPEED)][(int)ptr->player->pos_x] != '1')
				ptr->player->pos_y -= ptr->player->plane_y * MOVE_SPEED;
		}
	}
}

static void	go_right(t_ptr *ptr)
{
	if (ptr->keys.move_right)
	{
		if (ptr->player->pos_x - ptr->player->plane_x * MOVE_SPEED >= 0)
		{
			if (ptr->map[(int)ptr->player->pos_y][(int)(ptr->player->pos_x
				+ ptr->player->plane_x * MOVE_SPEED)] != '1')
				ptr->player->pos_x += ptr->player->plane_x * MOVE_SPEED;
		}
		if (ptr->player->pos_y - ptr->player->plane_y * MOVE_SPEED >= 0)
		{
			if (ptr->map[(int)(ptr->player->pos_y + ptr->player->plane_y
					* MOVE_SPEED)][(int)ptr->player->pos_x] != '1')
				ptr->player->pos_y += ptr->player->plane_y * MOVE_SPEED;
		}
	}
}

void	move(t_ptr *c3d)
{
	go_front(c3d);
	go_back(c3d);
	go_left(c3d);
	go_right(c3d);
}
