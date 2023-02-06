/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:24:15 by stelie            #+#    #+#             */
/*   Updated: 2023/02/06 17:26:09 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Returns an int color  from the given r,g and b int
 */
int	rgb_to_int(int r, int g, int b)
{
	return ((r * RGB_RED) + (g * RGB_GREEN) + b);
}

/**
 * @brief Returns a t_rgb from the given int color
 */
t_rgb	int_to_rgb(int color)
{
	t_rgb	rgb;

	rgb.r = color / RGB_RED;
	rgb.g = (color % RGB_RED) / RGB_GREEN;
	rgb.b = (color % RGB_RED) % RGB_GREEN;
	return (rgb);
}

/**
 * @brief Returns the color (t_rgb format) of the pixel at the given x and y.
 */
t_rgb	get_pixel_color(t_img *img, int x, int y)
{
	t_rgb	color;

	color.r = abs(img->data[(y * WIN_WIDTH) + x + 2]);
	color.g = abs(img->data[(y * WIN_WIDTH) + x + 1]);
	color.b = abs(img->data[(y * WIN_WIDTH) + x]);
	return (color);
}

/**
 * @brief Returns the color which is a transparent looking of the two
 * given colors.
 */
t_rgb	transparency(t_rgb color_one, t_rgb color_two)
{
	color_two.r = (color_two.r + color_one.r) / 2;
	color_two.g = (color_two.g + color_one.g) / 2;
	color_two.b = (color_two.b + color_one.b) / 2;
	return (color_two);
}
