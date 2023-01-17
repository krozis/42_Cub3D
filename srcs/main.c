/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:03:38 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/17 11:02:05 by stelie           ###   ########.fr       */
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

	if (verify_args(ac, av) == EXIT_FAILURE)
		return (0);
	ptr = init(av);
	init_mlx(ptr);
	if (check_errors(ptr) == EXIT_FAILURE)
		return (0);
	printf("test map\n");
	for (int i = 0; ptr->map[i]; i++)
		printf("%s", ptr->map[i]);
	printf("\nnorth texture = %s\n", ptr->text[N_TEXT]);
	printf("south texture = %s\n", ptr->text[S_TEXT]);
	printf("east  texture = %s\n", ptr->text[E_TEXT]);
	printf("west  texture = %s\n", ptr->text[W_TEXT]);
	printf("\ncolors\n");
	printf("floor = %d, %d, %d\n", ptr->floor[0], ptr->floor[1], ptr->floor[2]);
	printf("ceili = %d, %d, %d\n", ptr->ceiling[0], ptr->ceiling[1], ptr->ceiling[2]);
	
	free_them_all(ptr);
	return (EXIT_SUCCESS);
}
