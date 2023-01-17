/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:03:38 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/17 15:48:18 by dcyprien         ###   ########.fr       */
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
	mlx_loop(c3d->dply.mlx);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_ptr	*ptr;

	if (verify_args(ac, av) == EXIT_FAILURE)
		return (0);
	ptr = init(av);
	printf("\nnorth texture = %s\n", ptr->text[N_TEXT]);
	printf("south texture = %s\n", ptr->text[S_TEXT]);
	printf("east  texture = %s\n", ptr->text[E_TEXT]);
	printf("west  texture = %s\n", ptr->text[W_TEXT]);
	if (check_errors(ptr) == EXIT_FAILURE)
	{
		free_them_all(ptr);
		return (0);
	}
	if (init_mlx(ptr) == EXIT_FAILURE)
	{
		free_them_all(ptr);
		return (0);
	}
	printf("test map\n");
	for (int i = 0; ptr->map[i]; i++)
		printf("%s", ptr->map[i]);
	printf("\ncolors\n");
	printf("floor = %d,%d,%d\n", ptr->floor[0], ptr->floor[1],ptr->floor[2]);
	printf("ceili = %d,%d,%d\n", ptr->ceiling[0], ptr->ceiling[1],ptr->ceiling[2]);
	_routine(ptr);
	free_mlx(ptr, true, true, EXIT_SUCCESS);
	free_them_all(ptr);
	return (EXIT_SUCCESS);
}
