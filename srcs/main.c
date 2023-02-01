/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:03:38 by dcyprien          #+#    #+#             */
/*   Updated: 2023/02/01 17:11:11 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	_release_key(int key, t_ptr *c3d)
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
	if (key == XK_m)
		c3d->keys.minimap = false;
	return (EXIT_SUCCESS);
}

static int	_press_key(int key, t_ptr *c3d)
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
		c3d->keys.rotate_left = true;
	if (key == XK_Right)
		c3d->keys.rotate_right = true;
	if (key == XK_m)
		c3d->keys.minimap = true;
	return (EXIT_SUCCESS);
}

static int	_loop_routine(t_ptr *c3d)
{
	static int		fps;
	static clock_t	clock_cur;

	if (clock() != clock_cur)
		fps = CLOCKS_PER_SEC / (clock() - clock_cur);
	background_image(c3d);
	raycasting(c3d);
	move(c3d);
	rotate(c3d);
	mlx_put_image_to_window(c3d->dply.mlx, c3d->dply.win, c3d->dply.screen,
		0, 0);
	mlx_string_put(c3d->dply.mlx, c3d->dply.win, 10, 20,0x00FB50FF, "FPS");
	mlx_string_put(c3d->dply.mlx, c3d->dply.win, 35, 20, 0x00FB50FF, \
		(char []){'0' + fps / 100, '0' + fps / 10 % 10, '0' + fps % 10, '\0'});
	minimap(c3d);
	return (0);
}

static int	_routine(t_ptr *ptr)
{
	mlx_hook(ptr->dply.win, DestroyNotify, ButtonPressMask \
		, &mlx_loop_end, ptr->dply.mlx);
	mlx_hook(ptr->dply.win, KeyPress, KeyPressMask, &_press_key, ptr);
	mlx_loop_hook(ptr->dply.mlx, _loop_routine, ptr);
	mlx_hook(ptr->dply.win, KeyRelease, KeyReleaseMask, &_release_key, ptr);
	mlx_loop(ptr->dply.mlx);
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
