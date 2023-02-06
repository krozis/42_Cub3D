/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:09:11 by stelie            #+#    #+#             */
/*   Updated: 2023/02/06 11:30:26 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	_check_map(t_img *img, char **map)
{
	(void)img;
	(void)map;
}

void	minimap(t_ptr *c3d)
{
	t_point	a;
	t_point	b;

	a = init_point(MAP_X_START, MAP_Y_START);
	b = init_point(MAP_X_END, MAP_Y_END);
	draw_rect_trans(c3d->dply.screen, a, b, int_to_rgb(MAP_BG_COLOR));
	a = init_point(MAP_P_X, MAP_P_Y);
	b = add_point(a, MAP_BOX_W, MAP_BOX_H);
	draw_rect_trans(c3d->dply.screen, a, b, int_to_rgb(MAP_PLAYER_COLOR));
	_check_map(c3d->dply.screen, c3d->map);
}
