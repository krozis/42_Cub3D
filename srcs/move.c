/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:12:04 by dcyprien          #+#    #+#             */
/*   Updated: 2023/02/01 16:38:47 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	go_front(t_ptr *ptr)
{
	if (ptr->keys.move_front)
	{
		if (ptr->map[(int)ptr->player->posY][(int)(ptr->player->posX
			+ ptr->player->dirX * MOVE_SPEED)] != '1')
			ptr->player->posX += ptr->player->dirX * MOVE_SPEED;
		if (ptr->map[(int)(ptr->player->posY + ptr->player->dirY
				* MOVE_SPEED)][(int)ptr->player->posX] != '1')
			ptr->player->posY += ptr->player->dirY * MOVE_SPEED;
	}
}

static void	go_back(t_ptr *ptr)
{
	if (ptr->keys.move_back)
	{
		if (ptr->map[(int)ptr->player->posY][(int)(ptr->player->posX
			- ptr->player->dirX * MOVE_SPEED)] != '1')
			ptr->player->posX -= ptr->player->dirX * MOVE_SPEED;
		if (ptr->map[(int)(ptr->player->posY - ptr->player->dirY
				* MOVE_SPEED)][(int)ptr->player->posX] != '1')
			ptr->player->posY -= ptr->player->dirY * MOVE_SPEED;
	}
}

static void	go_left(t_ptr *ptr)
{
	if (ptr->keys.move_left)
	{
		if (ptr->player->posX - ptr->player->planeX * MOVE_SPEED >= 0)
		{
			if (ptr->map[(int)ptr->player->posY][(int)(ptr->player->posX
				- ptr->player->planeX * MOVE_SPEED)] != '1')
				ptr->player->posX -= ptr->player->planeX * MOVE_SPEED;
		}
		if (ptr->player->posY - ptr->player->planeY * MOVE_SPEED >= 0)
		{
			if (ptr->map[(int)(ptr->player->posY - ptr->player->planeY
					* MOVE_SPEED)][(int)ptr->player->posX] != '1')
				ptr->player->posY -= ptr->player->planeY * MOVE_SPEED;
		}
	}
}

static void	go_right(t_ptr *ptr)
{
	if (ptr->keys.move_right)
	{
		if (ptr->player->posX - ptr->player->planeX * MOVE_SPEED >= 0)
		{
			if (ptr->map[(int)ptr->player->posY][(int)(ptr->player->posX
				+ ptr->player->planeX * MOVE_SPEED)] != '1')
				ptr->player->posX += ptr->player->planeX * MOVE_SPEED;
		}
		if (ptr->player->posY - ptr->player->planeY * MOVE_SPEED >= 0)
		{
			if (ptr->map[(int)(ptr->player->posY + ptr->player->planeY
					* MOVE_SPEED)][(int)ptr->player->posX] != '1')
				ptr->player->posY += ptr->player->planeY * MOVE_SPEED;
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
