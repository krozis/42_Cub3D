/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:03:38 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/16 15:07:24 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

typedef enum e_direction
{
	N = 2,
	S,
	W,
	E
}			t_direction;

int	worldMap[7][7] = {
	{1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, N, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1},
};

static int	_exit_routine(void *mlx)
{
	if (mlx == NULL)
		return (EXIT_FAILURE);
	write(1, "YO", 2);
	mlx_destroy_display(mlx);
	free(mlx);
	return (EXIT_SUCCESS);
}

static int	_routine(void	*mlx)
{
	return (_exit_routine(mlx));
}

/**
 * TODO: ERR_MSG if (ac != 2)
 */
int	main(int ac, char **av)
{
	void	*mlx;

	if (ac != 2)
		return (EXIT_FAILURE);
	(void)av;
	// 1) Open map file
	// 2) Parse map
	// 3) close map file
	mlx = mlx_init();
	if (mlx == NULL)
		return (_exit_routine(NULL));
	return (_routine(mlx));
}
