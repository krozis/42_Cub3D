/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:15:12 by stelie            #+#    #+#             */
/*   Updated: 2023/02/03 17:21:45 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_pixel(t_img *img, int x, int y, t_rgb color)
{
	y *= 4;
	img->data[(y * WIN_WIDTH) + x] = color.b;
	img->data[(y * WIN_WIDTH) + x + 1] = color.g;
	img->data[(y * WIN_WIDTH) + x + 2] = color.r;
}

int	rgb_to_int(int r, int g, int b)
{
	return ((r * RGB_RED) + (g * RGB_GREEN) + b);
}

t_rgb	int_to_rgb(int color)
{
	t_rgb	rgb;

	rgb.r = color / RGB_RED;
	rgb.g = (color % RGB_RED) / RGB_GREEN;
	rgb.b = (color % RGB_RED) % RGB_GREEN;
	return (rgb);
}