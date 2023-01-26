/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:41:57 by stelie            #+#    #+#             */
/*   Updated: 2023/01/26 12:45:21 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	_coloring(t_img *img, int y, int color)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH * 4)
	{
		img->data[(y * 4 * WIN_WIDTH) + x] = (color % RGB_RED) % RGB_GREEN;
		img->data[(y * 4 * WIN_WIDTH) + x + 1] = (color % RGB_RED) / RGB_GREEN;
		img->data[(y * 4 * WIN_WIDTH) + x + 2] = color / RGB_RED;
		x += 4;
	}
}

int	background_image(t_ptr *ptr)
{
	int	y;

	ptr->dply.screen = mlx_new_image(ptr->dply.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (ptr->dply.screen == NULL)
		return (EXIT_FAILURE);
	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		_coloring(ptr->dply.screen, y, ptr->ceiling_color);
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		_coloring(ptr->dply.screen, y, ptr->floor_color);
		y++;
	}
	return (EXIT_SUCCESS);
}
