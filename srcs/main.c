/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:03:38 by dcyprien          #+#    #+#             */
/*   Updated: 2023/02/06 17:31:37 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	_mouse_move(int x, int y, t_c3d *c3d)
{
	(void)y;
	if (x < WIN_WIDTH / 2 && x > 0)
	{
		c3d->keys.rotate_mouse_right = false;
		c3d->keys.rotate_mouse_left = true;
	}
	else if (x > WIN_WIDTH * 0.5 && x < WIN_WIDTH)
	{
		c3d->keys.rotate_mouse_left = false;
		c3d->keys.rotate_mouse_right = true;
	}
	else
	{
		c3d->keys.rotate_mouse_left = false;
		c3d->keys.rotate_mouse_right = false;
	}
	return (EXIT_SUCCESS);
}

static int	_release_key(int key, t_c3d *c3d)
{
	if (key == XK_w)
		c3d->keys.move_front = false;
	if (key == XK_s)
		c3d->keys.move_back = false;
	if (key == XK_a)
		c3d->keys.move_left = false;
	if (key == XK_d)
		c3d->keys.move_right = false;
	if (key == XK_Left)
		c3d->keys.rotate_left = false;
	if (key == XK_Right)
		c3d->keys.rotate_right = false;
	if (key == XK_space)
		c3d->keys.mouse_free = false;
	return (EXIT_SUCCESS);
}

static int	_press_key(int key, t_c3d *c3d)
{
	if (key == XK_Escape)
		mlx_loop_end(c3d->dply.mlx);
	if (key == XK_w)
		c3d->keys.move_front = true;
	if (key == XK_s)
		c3d->keys.move_back = true;
	if (key == XK_a)
		c3d->keys.move_left = true;
	if (key == XK_d)
		c3d->keys.move_right = true;
	if (key == XK_Left)
	{
		c3d->keys.rotate_right = false;
		c3d->keys.rotate_left = true;
	}
	if (key == XK_Right)
	{
		c3d->keys.rotate_left = false;
		c3d->keys.rotate_right = true;
	}
	if (key == XK_space)
		c3d->keys.mouse_free = true;
	return (EXIT_SUCCESS);
}

static int	_routine(t_c3d *c3d)
{
	background(c3d);
	raycasting(c3d);
	minimap(c3d);
	mlx_put_image_to_window(c3d->dply.mlx, c3d->dply.win, c3d->dply.screen,
		0, 0);
	move(c3d);
	rotate(c3d);
	if (c3d->keys.mouse_free == false)
		mlx_mouse_move(c3d->dply.mlx, c3d->dply.win,
			WIN_WIDTH / 2, WIN_HEIGHT / 2);
	secure_free((void **)&c3d->ray);
	mlx_destroy_image(c3d->dply.mlx, c3d->dply.screen);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_c3d	*c3d;

	if (verify_args(ac, av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	c3d = init(av);
	if (check_errors(c3d) == EXIT_FAILURE || init_mlx(c3d) == EXIT_FAILURE)
	{
		free_them_all(c3d);
		return (EXIT_FAILURE);
	}
	mlx_hook(c3d->dply.win, DestroyNotify, ButtonPressMask \
		, &mlx_loop_end, c3d->dply.mlx);
	mlx_hook(c3d->dply.win, KeyPress, KeyPressMask, &_press_key, c3d);
	mlx_loop_hook(c3d->dply.mlx, _routine, c3d);
	mlx_hook(c3d->dply.win, KeyRelease, KeyReleaseMask, &_release_key, c3d);
	mlx_hook(c3d->dply.win, MotionNotify, PointerMotionMask, &_mouse_move, c3d);
	mlx_loop(c3d->dply.mlx);
	free_them_all(c3d);
	return (EXIT_SUCCESS);
}
