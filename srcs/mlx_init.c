/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:23:07 by stelie            #+#    #+#             */
/*   Updated: 2023/01/16 18:26:02 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
/* 
static t_pic	_text_load(t_ptr *c3d, char *file)
{
	t_pic	i;

	i.img = mlx_xpm_file_to_image(c3d->dply->mlx, file, &i.width, &i.height);
	return (i);
}
 */
int	init_mlx(t_ptr *c3d)
{
	c3d->dply.mlx = mlx_init();
	if (c3d->dply.mlx == NULL)
		return (EXIT_FAILURE);
	c3d->dply.win = mlx_new_window(c3d->dply.mlx, WIN_WIDTH, WIN_WIDTH,
			WIN_NAME);
	if (c3d->dply.mlx == NULL)
	{
		mlx_destroy_display(c3d->dply.mlx);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
