/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:09:11 by stelie            #+#    #+#             */
/*   Updated: 2023/02/06 11:19:24 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	_check_map(t_img *img, char **map)
{
	t_point	a;
	t_point	b;

	a = init_point(MAP_MID_START_X, MAP_MID_START_Y);
	b = add_point(a, MAP_CASE_W, MAP_CASE_H);
	(void)map;
	draw_rect_empty(img, a, b, int_to_rgb(7239790));
}

void	minimap(t_ptr *c3d)
{
	t_point	a;
	t_point	b;

	a = init_point(MAP_X_START, MAP_Y_START);
	b = init_point(MAP_X_END, MAP_Y_END);
	draw_rect_trans(c3d->dply.screen, a, b, int_to_rgb(MAP_BG_COLOR));
	_check_map(c3d->dply.screen, c3d->map);
}
