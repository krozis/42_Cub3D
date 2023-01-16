/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:03:38 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/16 18:26:32 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* static int	_exit_routine(void *mlx)
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
} */

/**
 * TODO: ERR_MSG if (ac != 2)
 */
int	main(int ac, char **av)
{
	t_ptr	*ptr;

	(void)ac;
	ptr = init(av);
	printf("test map\n");
	for (int i = 0; ptr->map[i]; i++)
		printf("%s", ptr->map[i]);
	printf("\nnorth texture = %s\n", ptr->n_text);
	printf("south texture = %s\n", ptr->s_text);
	printf("east  texture = %s\n", ptr->e_text);
	printf("west  texture = %s\n", ptr->w_text);
	printf("\ncolors\n");
	printf("floor = %d,%d,%d\n", ptr->floor[0], ptr->floor[1],ptr->floor[2]);
	printf("ceili = %d,%d,%d\n", ptr->ceiling[0], ptr->ceiling[1],ptr->ceiling[2]);
	init_mlx(ptr);
	free_them_all(ptr);
	return (EXIT_SUCCESS);
}
