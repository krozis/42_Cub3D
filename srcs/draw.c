/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:15:12 by stelie            #+#    #+#             */
/*   Updated: 2023/02/06 17:31:37 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Draws a rectangle on the t_img. The rectangle is fully colored
 * using transparency between given color and existing color at each pixel. 
 * @param img: a pointer to the t_img where to draw
 * @param a: the top-left t_point
 * @param b: the bottom-right t_point
 * @param color: the color of the drawing
 */
void	draw_rect_trans(t_img *img, t_point a, t_point b, t_rgb color)
{
	t_point	p;
	t_rgb	new;

	p = a;
	while (p.y < b.y)
	{
		p.x = a.x;
		while (p.x < b.x)
		{
			new = transparency(get_pixel_color(img, p.x * 4, p.y * 4), color);
			draw_pixel(img, p.x * 4, p.y * 4, new);
			p.x++;
		}
		p.y++;
	}
}

/**
 * @brief Draws a rectangle on the t_img. The rectangle is fully colored. 
 * @param img: a pointer to the t_img where to draw
 * @param a: the top-left t_point
 * @param b: the bottom-right t_point
 * @param color: the color of the drawing
 */
void	draw_rect_full(t_img *img, t_point a, t_point b, t_rgb color)
{
	t_point	p;

	p = a;
	while (p.y < b.y)
	{
		p.x = a.x;
		while (p.x < b.x)
		{
			draw_pixel(img, p.x * 4, p.y * 4, color);
			p.x++;
		}
		p.y++;
	}
}

/**
 * @brief Colors the pixel at the given coordonates
 */
void	draw_pixel(t_img *img, int x, int y, t_rgb color)
{
	img->data[(y * WIN_WIDTH) + x] = color.b;
	img->data[(y * WIN_WIDTH) + x + 1] = color.g;
	img->data[(y * WIN_WIDTH) + x + 2] = color.r;
}

/**
 * @brief Colors the background of the screen.
 * @return EXIT_FAILURE or EXIT_SUCCESS
 */
int	background(t_c3d *c3d)
{
	c3d->dply.screen = mlx_new_image(c3d->dply.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (c3d->dply.screen == NULL)
		return (EXIT_FAILURE);
	draw_rect_full(c3d->dply.screen, init_point(0, 0),
		init_point(WIN_WIDTH, WIN_HEIGHT / 2), int_to_rgb(c3d->ceiling_color));
	draw_rect_full(c3d->dply.screen, init_point(0, WIN_HEIGHT / 2),
		init_point(WIN_WIDTH, WIN_HEIGHT), int_to_rgb(c3d->floor_color));
	return (EXIT_SUCCESS);
}
