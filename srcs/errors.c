/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:26:55 by dcyprien          #+#    #+#             */
/*   Updated: 2023/02/02 12:31:03 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_empty_line(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (is_empty(map[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	check_extension(char *av)
{
	int	i;

	i = ft_strlen(av) - 1;
	if (av[i] != 'b' || av[i - 1] != 'u' || av[i - 2] != 'c'
		|| av[i - 3] != '.')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	check_map(char **map)
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
		return (ft_putmsg_fd("Error\nPlayer has several starting postions\n"
				, 2, EXIT_FAILURE));
	if (check_integrity(map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * @brief Check if the given parameter is a valid .cub map.
 * @return EXIT_FAILURE or EXIT_SUCCESS
 */
int	verify_args(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		return (ft_putmsg_fd("Error\nUsage : ./cub3D [path to config file]\n"
				, 2, EXIT_FAILURE));
	if (check_extension(av[1]) == EXIT_FAILURE)
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

/**
 * @brief main error checker
 * @return EXIT_FAILURE or EXIT_SUCCESS
 */
int	check_errors(t_ptr *ptr)
{
	if (!ptr)
		return (ft_putmsg_fd("Error\nCouldn't open config file\n"
				, 2, EXIT_FAILURE));
	if (check_texture(ptr) == EXIT_FAILURE)
		return (ft_putmsg_fd("Error\nCouldn't open texture file\n"
				, 2, EXIT_FAILURE));
	if (text_is_dir(ptr) == EXIT_FAILURE)
		return (ft_putmsg_fd("Error\nA texture file is a directory\n"
				, 2, EXIT_FAILURE));
	if (check_map(ptr->map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ptr->ceiling_color == ERR_MISS_LINE
		|| ptr->floor_color == ERR_MISS_LINE)
		return (ft_putmsg_fd("Error\nMissing color line\n", 2, EXIT_FAILURE));
	if (ptr->ceiling_color == ERR_INV_VAL || ptr->floor_color == ERR_INV_VAL)
		return (ft_putmsg_fd("Error\nInvalid color values : value must"
				" be between 0 and 255\n", 2, EXIT_FAILURE));
	if (ptr->ceiling_color == ERR_COLOR_CHAR
		|| ptr->floor_color == ERR_COLOR_CHAR)
		return (ft_putmsg_fd("Error\nUnknown character in color line\n"
				, 2, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}
