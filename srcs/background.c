/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:41:57 by stelie            #+#    #+#             */
/*   Updated: 2023/01/23 12:34:11 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	_coloring(t_img *img, int y, int color)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH * 4)
	{
		img->data[(y * 4 * WIN_WIDTH) + x] = (color % RGB_RED) % RGB_GREEN;
		img->data[(y * 4 * WIN_WIDTH) + x + 1] = (color % RGB_RED) / RGB_GREEN;
		img->data[(y * 4 * WIN_WIDTH) + x + 2] = color / RGB_RED;
		x += 4;
	}
}

int	background_image(t_ptr *c3d)
{
	int	y;

	c3d->dply.screen = mlx_new_image(c3d->dply.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (c3d->dply.screen == NULL)
		return (EXIT_FAILURE);
	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		_coloring(c3d->dply.screen, y, c3d->ceiling_color);
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		_coloring(c3d->dply.screen, y, c3d->floor_color);
		y++;
	}
	return (EXIT_SUCCESS);
}
