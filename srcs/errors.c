/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:26:55 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/19 17:17:34 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	verify_args(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		return (ft_putmsg_fd("Error\nUsage : ./cub3D [path to config file]\n"
				, 2, EXIT_FAILURE));
	if (!ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
		return (ft_putmsg_fd("Error\nConfig file must have .cub extension\n"
				, 2, EXIT_FAILURE));
	fd = open(av[1], __O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (ft_putmsg_fd("Error\nArgument is a directory.\n"
				, 2, EXIT_FAILURE));
	}
	return (EXIT_SUCCESS);
}

int	check_texture(t_ptr *ptr)
{
	int	fd[4];

	if (!ptr->text[N_TEXT])
		return (EXIT_FAILURE);
	fd[0] = open(ptr->text[N_TEXT], O_RDONLY);
	if (fd[0] < 0)
		return (EXIT_FAILURE);
	if (!ptr->text[S_TEXT])
		return (EXIT_FAILURE);
	fd[1] = open(ptr->text[S_TEXT], O_RDONLY);
	if (fd[1] < 0)
		return (EXIT_FAILURE);
	if (!ptr->text[E_TEXT])
		return (EXIT_FAILURE);
	fd[2] = open(ptr->text[E_TEXT], O_RDONLY);
	if (fd[2] < 0)
		return (EXIT_FAILURE);
	if (!ptr->text[W_TEXT])
		return (EXIT_FAILURE);
	fd[3] = open(ptr->text[W_TEXT], O_RDONLY);
	if (fd[3] < 0)
		return (EXIT_FAILURE);
	close_fds(fd);
	return (EXIT_SUCCESS);
}

int	check_map(char **map)
{
	if (check_empty_line(map) == EXIT_FAILURE)
		return (ft_putmsg_fd("Error\nMap has empty line\n", 2, EXIT_FAILURE));
	if (check_chars(map) == EXIT_FAILURE)
		return (ft_putmsg_fd("Error\nMap has unknown characters\n"
				, 2, EXIT_FAILURE));
	if (check_chars(map) == ERR_NO_START)
		return (ft_putmsg_fd("Error\nPlayer has no starting position\n"
				, 2, EXIT_FAILURE));
	if (check_chars(map) == ERR_TWO_START)
		return (ft_putmsg_fd("Error\nPlayer has two starting postion\n"
				, 2, EXIT_FAILURE));
	if (check_integrity(map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_errors(t_ptr *ptr)
{
	if (!ptr)
		return (ft_putmsg_fd("Error\nCouldn't open config file\n"
				, 2, EXIT_FAILURE));
	if (check_texture(ptr) == EXIT_FAILURE)
		return (ft_putmsg_fd("Error\nCouldn't open texture file\n"
				, 2, EXIT_FAILURE));
	if (check_map(ptr->map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ptr->ceiling_color == -2 || ptr->floor_color == -2)
		return (ft_putmsg_fd("Error\nMissing color line\n", 2, EXIT_FAILURE));
	if (ptr->ceiling_color == -1 || ptr->floor_color == -1)
		return (ft_putmsg_fd("Error\nInvalid color values : value must"
				" be between 0 and 255\n", 2, EXIT_FAILURE));
	if (ptr->ceiling_color == -3 || ptr->floor_color == -3)
		return (ft_putmsg_fd("Error\nUnknown character in color line\n"
				, 2, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}
