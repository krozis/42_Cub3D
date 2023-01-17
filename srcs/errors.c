/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:26:55 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/17 11:32:58 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	verify_args(int ac, char **av)
{
	if (ac != 2)
		return (ft_putmsg_fd("Error\nUsage : ./cub3D [path to config file]\n"
				, 2, EXIT_FAILURE));
	if (!ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
		return (ft_putmsg_fd("Error\nConfig file must have .cub extension\n"
				, 2, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}

int	check_texture(t_ptr *ptr)
{
	int	fd;

	fd = open(ptr->text[N_TEXT], O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	fd = open(ptr->text[S_TEXT], O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	fd = open(ptr->text[E_TEXT], O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	fd = open(ptr->text[W_TEXT], O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_colors(t_ptr *ptr)
{
	if ((ptr->floor[0] < 0 || ptr->floor[0] > 255) || (ptr->floor[1] < 0
			|| ptr->floor[1] > 255) || (ptr->floor[2] < 0
			|| ptr->floor[2] > 255))
		return (EXIT_FAILURE);
	if ((ptr->ceiling[0] < 0 || ptr->ceiling[0] > 255) || (ptr->ceiling[1] < 0
			|| ptr->ceiling[1] > 255) || (ptr->ceiling[2] < 0
			|| ptr->ceiling[2] > 255))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_errors(t_ptr *ptr)
{
	if (!ptr->dply.mlx)
		return (ft_putmsg_fd("Error\nError in initialization of MLX\n"
				, 2, EXIT_FAILURE));
	if (check_texture(ptr) == EXIT_FAILURE)
		return (ft_putmsg_fd("Error\nCouldn't open texture file\n"
				, 2, EXIT_FAILURE));
	// if (check_map(ptr->map) == EXIT_FAILURE)
	// 	return (ft_putmsg_fd("Error\nInvalid map format\n", 2, EXIT_FAILURE));
	if (check_colors(ptr) == EXIT_FAILURE)
		return (ft_putmsg_fd("Error\nInvalid color values : value must"
				" be between 0 and 255\n", 2, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}
