/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:20:10 by dcyprien          #+#    #+#             */
/*   Updated: 2023/02/06 17:31:37 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	set_color(t_c3d *c3d, int texX, int texY)
{
	if (c3d->ray->txt_nb == N_TEXT)
		return (rgb_to_int(c3d->dply.n_texture->data[4 * (64 * texY + texX)]
				, c3d->dply.n_texture->data[4 * (64 * texY + texX) + 1]
				, c3d->dply.n_texture->data[4 * (64 * texY + texX) + 2]));
	if (c3d->ray->txt_nb == S_TEXT)
		return (rgb_to_int(c3d->dply.s_texture->data[4 * (64 * texY + texX)]
				, c3d->dply.s_texture->data[4 * (64 * texY + texX) + 1]
				, c3d->dply.s_texture->data[4 * (64 * texY + texX) + 2]));
	if (c3d->ray->txt_nb == E_TEXT)
		return (rgb_to_int(c3d->dply.e_texture->data[4 * (64 * texY + texX)]
				, c3d->dply.e_texture->data[4 * (64 * texY + texX) + 1]
				, c3d->dply.e_texture->data[4 * (64 * texY + texX) + 2]));
	if (c3d->ray->txt_nb == W_TEXT)
		return (rgb_to_int(c3d->dply.w_texture->data[4 * (64 * texY + texX)]
				, c3d->dply.w_texture->data[4 * (64 * texY + texX) + 1]
				, c3d->dply.w_texture->data[4 * (64 * texY + texX) + 2]));
	return (0);
}

static int	set_texx(t_c3d *c3d, int texX)
{
	if (c3d->ray->side == 0 && c3d->ray->raydir_x > 0 && c3d->ray->raydir_y > 0)
		texX = 64 - texX - 1;
	if (c3d->ray->side == 0 && c3d->ray->raydir_x < 0 && c3d->ray->raydir_y > 0)
		texX = 64 - texX - 1;
	if (c3d->ray->side == 1 && c3d->ray->raydir_x < 0 && c3d->ray->raydir_y > 0)
		texX = 64 - texX - 1;
	if (c3d->ray->side == 1 && c3d->ray->raydir_x < 0 && c3d->ray->raydir_y < 0)
		texX = 64 - texX - 1;
	return (texX);
}

static void	drawline_2(t_c3d *c3d, int x, int texX, int texY)
{
	int		i;
	int		lineheight;
	double	step;
	double	texpos;
	int		colour;

	i = c3d->ray->drawval[0];
	texX = set_texx(c3d, texX);
	lineheight = (int)(WIN_WIDTH / c3d->ray->perp_dist);
	step = 1.0 * 64 / lineheight;
	texpos = (c3d->ray->drawval[0] - WIN_HEIGHT / 2 + lineheight / 2) * step;
	while (i < c3d->ray->drawval[1])
	{
		texY = (int)texpos & (64 - 1);
		texpos += step;
		colour = set_color(c3d, texX, texY);
		if (c3d->ray->side == 1)
			colour = (colour >> 1) & 8355711;
		c3d->dply.screen->data[4 * (i * WIN_WIDTH + x)] = (colour / RGB_RED);
		c3d->dply.screen->data[4 * (i * WIN_WIDTH + x) + 1]
			= (colour % RGB_RED) / RGB_GREEN;
		c3d->dply.screen->data[4 * (i * WIN_WIDTH + x) + 2]
			= (colour % RGB_RED) % RGB_GREEN;
		i++;
	}
}

void	drawline(t_c3d *c3d, int x)
{
	int		i;
	double	wallx;
	int		texx;
	int		texy;

	i = 0;
	while (i < c3d->ray->drawval[0])
	{
		c3d->dply.screen->data[4 * (i * WIN_WIDTH + x)]
			= (c3d->ceiling_color / RGB_RED);
		c3d->dply.screen->data[4 * (i * WIN_WIDTH + x) + 1]
			= (c3d->ceiling_color % RGB_RED) / RGB_GREEN;
		c3d->dply.screen->data[4 * (i * WIN_WIDTH + x) + 2]
			= (c3d->ceiling_color % RGB_RED) % RGB_GREEN;
		i++;
	}
	if (c3d->ray->side == 0)
		wallx = c3d->player->pos_x + c3d->ray->perp_dist * c3d->ray->raydir_x;
	else
		wallx = c3d->player->pos_y + c3d->ray->perp_dist * c3d->ray->raydir_y;
	wallx -= (int)wallx;
	texx = (int)(wallx * (double)(64));
	texy = 0;
	drawline_2(c3d, x, texx, texy);
}

int	text_num(t_c3d *c3d)
{
	if (c3d->ray->side == 0)
	{
		if (c3d->ray->raydir_y > 0)
			return (S_TEXT);
		else
			return (N_TEXT);
	}
	else
	{
		if (c3d->ray->raydir_x > 0)
			return (W_TEXT);
		else
			return (E_TEXT);
	}
}
