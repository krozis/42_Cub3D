/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:23:07 by stelie            #+#    #+#             */
/*   Updated: 2023/01/26 18:11:29 by dcyprien         ###   ########.fr       */
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
int	free_mlx(t_ptr *c3d, bool txt, bool bg, int exit_code)
{
	int	i;

	if (txt)
	{
		i = N_TEXT;
		while (i <= E_TEXT)
		{
			mlx_destroy_image(c3d->dply.mlx, c3d->dply.textures[i].image);
			i++;
		}
	}
	if (bg)
		;//mlx_destroy_image(c3d->dply.mlx, c3d->dply.screen);
	mlx_destroy_window(c3d->dply.mlx, c3d->dply.win);
	mlx_destroy_display(c3d->dply.mlx);
	secure_free(&(c3d->dply.mlx));
	return (exit_code);
}

static t_img	_text_load_each(void *mlx, char *file)
{
	t_img	i;

	i.image = mlx_xpm_file_to_image(mlx, file, &i.width, &i.height);
	return (i);
}

static int	_text_load(t_ptr *c3d)
{
	int	i;

	i = N_TEXT;
	while (i <= E_TEXT)
	{
		c3d->dply.textures[i] = _text_load_each(c3d->dply.mlx, c3d->text[i]);
		if (c3d->dply.textures[i].image == NULL)
		{
			while (--i <= 0)
			{
				mlx_destroy_image(c3d->dply.mlx, c3d->dply.textures[i].image);
			}
			return (EXIT_FAILURE);
		}
		i++;
	}
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
	if (_text_load(c3d) == EXIT_FAILURE)
		return (free_mlx(c3d, false, false, EXIT_FAILURE));
	if (background_image(c3d) == EXIT_FAILURE)
		return (free_mlx(c3d, true, false, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}
