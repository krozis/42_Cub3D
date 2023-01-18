/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:03:38 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/18 12:01:43 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	_press_key(int key, t_ptr *c3d)
{
	if (key == XK_Escape)
		mlx_loop_end(c3d->dply.mlx);
/*
	if (key == XK_Left || key == XK_Right)
		rotate_camera(c3d, key);
	if (key == key == XK_W || key == XK_w)
		go_front(c3d);
	if (key == XK_S || key == XK_s)
		go_back(c3d);
	if (key == XK_A || key == XK_a)
		go_left(c3d);
	if (key == XK_D || key == XK_d)
		go_right(c3d);
	if (key == XK_M || key == XK_m)
		display_minimap(c3d);
	*/
	return (EXIT_SUCCESS);
}

static int	_routine(t_ptr *c3d)
{
	mlx_key_hook(c3d->dply.win, &_press_key, c3d);
	mlx_hook(c3d->dply.win, 33, (1L << 5), &mlx_loop_end, c3d->dply.mlx);
	mlx_put_image_to_window(c3d->dply.mlx, c3d->dply.win, c3d->dply.bg, 0, 0);
	mlx_put_image_to_window(c3d->dply.mlx, c3d->dply.win,
		c3d->dply.textures[N_TEXT].image, 1380, 840);
	mlx_loop(c3d->dply.mlx);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_ptr	*ptr;

	if (verify_args(ac, av) == EXIT_FAILURE)
		return (0);
	ptr = init(av);
	if (check_errors(ptr) == EXIT_FAILURE || init_mlx(ptr) == EXIT_FAILURE)
	{
		free_them_all(ptr);
		return (0);
	}
	_routine(ptr);
	free_them_all(ptr);
	return (EXIT_SUCCESS);
}
