/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:09:11 by stelie            #+#    #+#             */
/*   Updated: 2023/02/06 10:23:10 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	minimap(t_ptr *c3d)
{
	t_point	a;
	t_point	b;

	a.x = MAP_X_START;
	a.y = MAP_Y_START;
	b.x = MAP_X_END;
	b.y = MAP_Y_END;
	draw_rect_trans(c3d->dply.screen, a, b, int_to_rgb(MAP_BG_COLOR));
}
