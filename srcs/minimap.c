/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:09:11 by stelie            #+#    #+#             */
/*   Updated: 2023/02/03 17:45:36 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	_coloring_pixel(t_img *img, int y, int color)
{
	int		x;
	t_rgb	old;
	t_rgb	new;

	x = MAP_X_START;
	x *= 4;
	y *= 4;
	while (x++ < MAP_X_END * 4)
	{
		new = int_to_rgb(color);
		old = get_color(img, x, y);
		new.r = (new.r + old.r) / 2;
		new.g = (new.g + old.g) / 2;
		new.b = (new.b + old.b) / 2;
		draw_pixel(img, x, y, new);
	}
}

static void	_draw_map(t_ptr *c3d)
{
	int	y;

	y = MAP_Y_START;
	while (y++ < MAP_Y_END)
		_coloring_pixel(c3d->dply.screen, y, MAP_FLOOR_COLOR);
}

void	minimap(t_ptr *c3d)
{
	_draw_map(c3d);
}
