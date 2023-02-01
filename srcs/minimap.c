/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:09:11 by stelie            #+#    #+#             */
/*   Updated: 2023/02/01 16:56:31 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	close_minimap(t_ptr *c3d)
{
	(void)c3d;
	mlx_destroy_image(c3d->dply.mlx, c3d->dply.minimap);
	return (EXIT_SUCCESS);
} 

void	minimap(t_ptr *c3d)
{
	if (c3d->keys.minimap)
	{
		c3d->dply.minimap = mlx_new_image(c3d->dply.mlx, 50, 50);
		mlx_put_image_to_window(c3d->dply.mlx, c3d->dply.win, c3d->dply.minimap, 25, 25);
	}
	else
		close_minimap(c3d);
}
