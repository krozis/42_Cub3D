/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:12:04 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/30 15:01:03 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	go_front(t_ptr *ptr)
{
	if (ptr->map[(int)ptr->player->posY][(int)(ptr->player->posX
		+ ptr->player->dirX * MOVE_SPEED)] != '1')
		ptr->player->posX += ptr->player->dirX * MOVE_SPEED;
	if (ptr->map[(int)(ptr->player->posY + ptr->player->dirY
			* MOVE_SPEED)][(int)ptr->player->posX] != '1')
		ptr->player->posY += ptr->player->dirY * MOVE_SPEED;
}

void	go_back(t_ptr *ptr)
{
	if (ptr->map[(int)ptr->player->posY][(int)(ptr->player->posX
		- ptr->player->dirX * MOVE_SPEED)] != '1')
		ptr->player->posX -= ptr->player->dirX * MOVE_SPEED;
	if (ptr->map[(int)(ptr->player->posY - ptr->player->dirY
			* MOVE_SPEED)][(int)ptr->player->posX] != '1')
		ptr->player->posY -= ptr->player->dirY * MOVE_SPEED;
}

void	go_left(t_ptr *ptr)
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

void	go_right(t_ptr *ptr)
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
