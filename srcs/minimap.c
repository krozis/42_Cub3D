/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:09:11 by stelie            #+#    #+#             */
/*   Updated: 2023/02/06 15:52:23 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	_color_case(t_img *img, t_point p, char type)
{
	if (type == '1')
		draw_rect_trans(img, p, add_point(p, MAP_BOX_W, MAP_BOX_H),
			int_to_rgb(MAP_WALL_COLOR));
	else if (type == '0' || ft_incharset(type, "NWSE"))
		draw_rect_trans(img, p, add_point(p, MAP_BOX_W, MAP_BOX_H),
			int_to_rgb(MAP_FLOOR_COLOR));
}

static t_point	_calculate(t_point p, int x, int y)
{
	t_point	ret;

	if (x == 0)
		ret.x = MAP_P_X - ((p.x - x) * MAP_BOX_W);
	else if (p.x > x)
		ret.x = MAP_P_X - ((p.x - x) * MAP_BOX_W);
	else
		ret.x = MAP_P_X + ((x - p.x) * MAP_BOX_W);
	if (y == 0)
		ret.y = MAP_P_Y - ((p.y - y) * MAP_BOX_H);
	else if (p.y > y)
		ret.y = MAP_P_Y - ((p.y - y) * MAP_BOX_H);
	else
		ret.y = MAP_P_Y + ((y - p.y) * MAP_BOX_H);
	return (ret);
}

static t_point	_get_corner_coord(char **map, t_point p, int corner_type)
{
	int	min_y;
	int	min_x;
	int	max_y;

	min_x = ft_posmin(p.x - 4, 0);
	min_y = ft_posmin(p.y - 4, 0);
	if (corner_type == TOP_LEFT)
		return (init_point(min_x, min_y));
	max_y = 0;
	while (map[max_y] != NULL)
		max_y++;
	max_y--;
	return (init_point(ft_min(p.x + 4, ft_strlen(map[0])), \
			ft_min(max_y, p.y + 4)));
}

static void	_check_map(t_img *img, char **map, t_player *player)
{
	t_point	corner;
	t_point	tmp;
	t_point	p;
	int		x;
	int		y;

	p = abs_point(init_point(player->pos_x, player->pos_y));
	tmp = _get_corner_coord(map, p, TOP_LEFT);
	corner = _get_corner_coord(map, p, BOT_RIGHT);
	y = tmp.y;
	while (y <= corner.y)
	{
		x = tmp.x;
		while (x <= corner.x)
		{
			_color_case(img, _calculate(p, x, y), map[y][x]);
			x++;
		}
		y++;
	}
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
	_check_map(c3d->dply.screen, c3d->map, c3d->player);
	draw_rect_trans(c3d->dply.screen, a, b, int_to_rgb(MAP_PLAYER_COLOR));
}
