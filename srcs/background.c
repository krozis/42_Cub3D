/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:41:57 by stelie            #+#    #+#             */
/*   Updated: 2023/01/18 11:56:40 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	pixel_test(t_img *img, int x, int y, int color)
{
	unsigned char *src;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	src = (unsigned char *)&color;
	r = src[0];
	g = src[1];
	b = src[2];
	img->data[y * img->size_line + x * img->bpp / 8] = r;
	img->data[y * img->size_line + x * img->bpp / 8 + 1] = g;
	img->data[y * img->size_line + x * img->bpp / 8 + 2] = b;
}

int	background_image(t_ptr *c3d)
{
	int y;
	int x;

	c3d->dply.bg = mlx_new_image(c3d->dply.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (c3d->dply.bg == NULL)
		return (EXIT_FAILURE);

	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
			pixel_test(c3d->dply.bg, x++, y, c3d->ceiling_color);
		y++;
	}
	y = WIN_HEIGHT - 1;
	while (y >= WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
			pixel_test(c3d->dply.bg, x++, y, c3d->floor_color);
		y--;
	}
	return (EXIT_SUCCESS);
}
