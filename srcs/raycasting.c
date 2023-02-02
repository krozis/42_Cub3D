/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:34:00 by dcyprien          #+#    #+#             */
/*   Updated: 2023/02/02 12:08:09 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	raycasting_1(t_ptr *ptr, int x)
{
	ptr->ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ptr->ray->raydir_x = ptr->player->dir_x + ptr->player->plane_x
		* ptr->ray->camera_x;
	ptr->ray->raydir_y = ptr->player->dir_y + ptr->player->plane_y
		* ptr->ray->camera_x;
	ptr->ray->map_x = (int)ptr->player->pos_x;
	ptr->ray->map_y = (int)ptr->player->pos_y;
	if (ptr->ray->raydir_y == 0)
		ptr->ray->delta_x = 0;
	else if (ptr->ray->raydir_x == 0)
		ptr->ray->delta_x = 1;
	else
		ptr->ray->delta_x = fabs(1 / ptr->ray->raydir_x);
	if (ptr->ray->raydir_x == 0)
		ptr->ray->delta_y = 0;
	else if (ptr->ray->raydir_y == 0)
		ptr->ray->delta_y = 0;
	else
		ptr->ray->delta_y = fabs(1 / ptr->ray->raydir_y);
}

static void	raycasting_2(t_ptr *ptr)
{
	ptr->ray->hit = 0;
	if (ptr->ray->raydir_x < 0)
	{
		ptr->ray->step_x = -1;
		ptr->ray->side_x = (ptr->player->pos_x - ptr->ray->map_x)
			* ptr->ray->delta_x;
	}
	else
	{
		ptr->ray->step_x = 1;
		ptr->ray->side_x = (ptr->ray->map_x + 1.0 - ptr->player->pos_x)
			* ptr->ray->delta_x;
	}
	if (ptr->ray->raydir_y < 0)
	{
		ptr->ray->step_y = -1;
		ptr->ray->side_y = (ptr->player->pos_y - ptr->ray->map_y)
			* ptr->ray->delta_y;
	}
	else
	{
		ptr->ray->step_y = 1;
		ptr->ray->side_y = (ptr->ray->map_y + 1.0 - ptr->player->pos_y)
			* ptr->ray->delta_y;
	}
}

static void	raycasting_3(t_ptr *ptr)
{
	while (ptr->ray->hit == 0)
	{
		if (ptr->ray->side_x <= ptr->ray->side_y)
		{
			ptr->ray->side_x += ptr->ray->delta_x;
			ptr->ray->map_x += ptr->ray->step_x;
			ptr->ray->side = 1;
		}
		else
		{
			ptr->ray->side_y += ptr->ray->delta_y;
			ptr->ray->map_y += ptr->ray->step_y;
			ptr->ray->side = 0;
		}
		if (ptr->map[ptr->ray->map_y][ptr->ray->map_x] == '1')
			ptr->ray->hit = 1;
	}
	if (ptr->ray->side == 1)
		ptr->ray->perp_dist = (ptr->ray->side_x - ptr->ray->delta_x);
	else
		ptr->ray->perp_dist = (ptr->ray->side_y - ptr->ray->delta_y);
	if (ptr->ray->perp_dist == 0.0)
		ptr->ray->perp_dist = ptr->ray->oldperpwall;
	ptr->ray->oldperpwall = ptr->ray->perp_dist;
}

static void	raycasting_4(t_ptr *ptr, int x)
{
	int	lineheight;

	lineheight = (int)(WIN_WIDTH / ptr->ray->perp_dist);
	ptr->ray->drawval[0] = (-lineheight / 2 + WIN_HEIGHT / 2) + 1;
	if (ptr->ray->drawval[0] < 0)
		ptr->ray->drawval[0] = 0;
	ptr->ray->drawval[1] = lineheight / 2 + WIN_HEIGHT / 2;
	if (ptr->ray->drawval[1] >= WIN_HEIGHT)
		ptr->ray->drawval[1] = WIN_HEIGHT - 1;
	ptr->ray->txt_nb = text_num(ptr);
	drawline(ptr, x);
}

void	raycasting(t_ptr *ptr)
{
	int	x;

	x = 0;
	secure_free((void **)&ptr->ray);
	ptr->ray = malloc(sizeof(t_ray));
	if (!ptr->player)
		init_player(&(ptr->player), ptr->map);
	if (!ptr->dply.screen)
		ptr->dply.screen = mlx_new_image(ptr->dply.mlx, WIN_WIDTH, WIN_HEIGHT);
	while (x < WIN_WIDTH)
	{
		raycasting_1(ptr, x);
		raycasting_2(ptr);
		raycasting_3(ptr);
		raycasting_4(ptr, x);
		x++;
	}
	mlx_put_image_to_window(ptr->dply.mlx, ptr->dply.win, ptr->dply.screen,
		0, 0);
}
