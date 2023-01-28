/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:03:38 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/28 21:19:15 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	_press_key(int key, t_ptr *c3d)
{
	if (key == XK_Escape)
		mlx_loop_end(c3d->dply.mlx);
	if (key == XK_Left || key == XK_Right)
		rotate(c3d, key);
	if (key == W_KEY)
		go_front(c3d);
	if (key == S_KEY)
		go_back(c3d);
	if (key == A_KEY)
		go_left(c3d);
	if (key == D_KEY)
		go_right(c3d);
	/*
	if (key == XK_M || key == XK_m)
		display_minimap(c3d);
	*/
	return (EXIT_SUCCESS);
}

static int	_routine(t_ptr *ptr)
{

	raycasting(ptr);
	mlx_hook(ptr->dply.win, 02, 1L << 0, &_press_key, ptr);
	mlx_hook(ptr->dply.win, 33, 1L << 5, &mlx_loop_end, ptr->dply.mlx);
	//mlx_put_image_to_window(ptr->dply.mlx, ptr->dply.win, ptr->dply.bg, 0, 0);
	// mlx_put_image_to_window(ptr->dply.mlx, ptr->dply.win,
	// 	ptr->dply.textures[N_TEXT].image, 1380, 840);
	mlx_loop_hook(ptr->dply.mlx, refresh, ptr);
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
	// for (int i = 0; ptr->map[i]; i++){
	// 	printf("%s", ptr->map[i]);
	// }
	_routine(ptr);
	free_them_all(ptr);
	return (EXIT_SUCCESS);
}
