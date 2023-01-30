/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:20:10 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/30 14:52:46 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	text_num(t_ptr *ptr)
{
	if (ptr->ray->side == 0)
	{
		if (ptr->ray->raydirY > 0)
			return (S_TEXT);
		else
			return (N_TEXT);
	}
	else
	{
		if (ptr->ray->raydirX > 0)
			return (W_TEXT);
		else
			return (E_TEXT);
	}
}

int	set_color(t_ptr *ptr, int texX, int texY)
{
	if (ptr->ray->texNum == N_TEXT)
		return (convert_colors(ptr->dply.n_texture->data[4 * (64 * texY + texX)]
				, ptr->dply.n_texture->data[4 * (64 * texY + texX) + 1]
				, ptr->dply.n_texture->data[4 * (64 * texY + texX) + 2]));
	if (ptr->ray->texNum == S_TEXT)
		return (convert_colors(ptr->dply.s_texture->data[4 * (64 * texY + texX)]
				, ptr->dply.s_texture->data[4 * (64 * texY + texX) + 1]
				, ptr->dply.s_texture->data[4 * (64 * texY + texX) + 2]));
	if (ptr->ray->texNum == E_TEXT)
		return (convert_colors(ptr->dply.e_texture->data[4 * (64 * texY + texX)]
				, ptr->dply.e_texture->data[4 * (64 * texY + texX) + 1]
				, ptr->dply.e_texture->data[4 * (64 * texY + texX) + 2]));
	if (ptr->ray->texNum == W_TEXT)
		return (convert_colors(ptr->dply.w_texture->data[4 * (64 * texY + texX)]
				, ptr->dply.w_texture->data[4 * (64 * texY + texX) + 1]
				, ptr->dply.w_texture->data[4 * (64 * texY + texX) + 2]));
	return (0);
}

int	set_texx(t_ptr *ptr, int texX)
{
	if (ptr->ray->side == 0 && ptr->ray->raydirX > 0 && ptr->ray->raydirY > 0)
		texX = 64 - texX - 1;
	if (ptr->ray->side == 0 && ptr->ray->raydirX < 0 && ptr->ray->raydirY > 0)
		texX = 64 - texX - 1;
	if (ptr->ray->side == 1 && ptr->ray->raydirX < 0 && ptr->ray->raydirY > 0)
		texX = 64 - texX - 1;
	if (ptr->ray->side == 1 && ptr->ray->raydirX < 0 && ptr->ray->raydirY < 0)
		texX = 64 - texX - 1;
	return (texX);
}

void	drawline_2(t_ptr *ptr, int x, int texX, int texY)
{
	int		i;
	int		lineheight;
	double	step;
	double	texpos;
	int		colour;

	i = ptr->ray->drawval[0];
	texX = set_texx(ptr, texX);
	lineheight = (int)(WIN_WIDTH / ptr->ray->perpWallDist);
	step = 1.0 * 64 / lineheight;
	texpos = (ptr->ray->drawval[0] - WIN_HEIGHT / 2 + lineheight / 2) * step;
	while (i < ptr->ray->drawval[1])
	{
		texY = (int)texpos & (64 - 1);
		texpos += step;
		colour = set_color(ptr, texX, texY);
		if (ptr->ray->side == 1)
			colour = (colour >> 1) & 8355711;
		ptr->dply.screen->data[4 * (i * WIN_WIDTH + x)] = (colour / RGB_RED);
		ptr->dply.screen->data[4 * (i * WIN_WIDTH + x) + 1]
			= (colour % RGB_RED) / RGB_GREEN;
		ptr->dply.screen->data[4 * (i * WIN_WIDTH + x) + 2]
			= (colour % RGB_RED) % RGB_GREEN;
		i++;
	}
}

void	drawline(t_ptr *ptr, int x)
{
	int		i;
	double	wallx;
	int		texx;
	int		texy;

	i = 0;
	while (i < ptr->ray->drawval[0])
	{
		ptr->dply.screen->data[4 * (i * WIN_WIDTH + x)]
			= (ptr->ceiling_color / RGB_RED);
		ptr->dply.screen->data[4 * (i * WIN_WIDTH + x) + 1]
			= (ptr->ceiling_color % RGB_RED) / RGB_GREEN;
		ptr->dply.screen->data[4 * (i * WIN_WIDTH + x) + 2]
			= (ptr->ceiling_color % RGB_RED) % RGB_GREEN;
		i++;
	}
	if (ptr->ray->side == 0)
		wallx = ptr->player->posX + ptr->ray->perpWallDist * ptr->ray->raydirX;
	else
		wallx = ptr->player->posY + ptr->ray->perpWallDist * ptr->ray->raydirY;
	wallx -= (int)wallx;
	texx = (int)(wallx * (double)(64));
	texy = 0;
	drawline_2(ptr, x, texx, texy);
}
