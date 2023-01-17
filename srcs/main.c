/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:03:38 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/17 12:26:18 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	_press_key(int key, t_ptr *c3d)
{
	if (key == XK_Escape)
		mlx_loop_end(c3d->dply.mlx);
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
	init_mlx(ptr);
	printf("\nnorth texture = %s\n", ptr->text[N_TEXT]);
	printf("south texture = %s\n", ptr->text[S_TEXT]);
	printf("east  texture = %s\n", ptr->text[E_TEXT]);
	printf("west  texture = %s\n", ptr->text[W_TEXT]);
	if (check_errors(ptr) == EXIT_FAILURE)
		return (0);
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
