/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:23:07 by stelie            #+#    #+#             */
/*   Updated: 2023/02/01 18:41:38 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief destroy and frees the mlx memory.
 * 
 * @param c3d the structure where the mlx is.
 * @param txt true if all textures has been loaded
 * @param bg true if the background image has been loaded
 * @param exit_code will return the given exit_code
 */
int	free_mlx(t_ptr *c3d, bool txt, int exit_code)
{
	if (txt)
	{
		if (c3d->dply.n_texture)
			mlx_destroy_image(c3d->dply.mlx, c3d->dply.n_texture);
		if (c3d->dply.s_texture)
			mlx_destroy_image(c3d->dply.mlx, c3d->dply.s_texture);
		if (c3d->dply.e_texture)
			mlx_destroy_image(c3d->dply.mlx, c3d->dply.e_texture);
		if (c3d->dply.w_texture)
			mlx_destroy_image(c3d->dply.mlx, c3d->dply.w_texture);
	}
	mlx_destroy_window(c3d->dply.mlx, c3d->dply.win);
	mlx_destroy_display(c3d->dply.mlx);
	secure_free(&(c3d->dply.mlx));
	return (exit_code);
}

static t_img	*_text_load_each(void *mlx, char *file, int x, int y)
{
	t_img	*img;

	img = mlx_xpm_file_to_image(mlx, file, &x, &y);
	img->height = y;
	img->width = x;
	return (img);
}

static int	_text_load(t_ptr *c3d)
{
	c3d->dply.n_texture = _text_load_each(c3d->dply.mlx,
			c3d->text[N_TEXT], 64, 64);
	c3d->dply.s_texture = _text_load_each(c3d->dply.mlx,
			c3d->text[S_TEXT], 64, 64);
	c3d->dply.e_texture = _text_load_each(c3d->dply.mlx,
			c3d->text[E_TEXT], 64, 64);
	c3d->dply.w_texture = _text_load_each(c3d->dply.mlx,
			c3d->text[W_TEXT], 64, 64);
	if (!c3d->dply.n_texture || !c3d->dply.s_texture
		|| !c3d->dply.e_texture || !c3d->dply.w_texture)
		return (free_mlx(c3d, true, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}

/**
 * @brief Initializes the mlx display, window and textures.
 * @param c3d a pointer to the main cub3D structure
 * @return EXIT_FAILURE or EXIT_SUCCESS.
 */
int	init_mlx(t_ptr *c3d)
{
	c3d->dply.mlx = mlx_init();
	if (c3d->dply.mlx == NULL)
		return (EXIT_FAILURE);
	c3d->dply.win = mlx_new_window(c3d->dply.mlx, WIN_WIDTH, WIN_HEIGHT,
			WIN_NAME);
	if (c3d->dply.win == NULL)
	{
		mlx_destroy_display(c3d->dply.mlx);
		ft_free(c3d->dply.mlx);
		return (EXIT_FAILURE);
	}
	c3d->player = NULL;
	if (_text_load(c3d) == EXIT_FAILURE)
		return (free_mlx(c3d, false, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}
