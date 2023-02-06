/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:05:28 by dcyprien          #+#    #+#             */
/*   Updated: 2023/02/06 17:31:37 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	count_lines(char *av)
{
	int		i;
	char	*tmp;
	int		fd;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (0);
	tmp = get_next_line(fd);
	if (!tmp)
		return (0);
	while (tmp)
	{
		secure_free((void **)&tmp);
		tmp = get_next_line(fd);
		i++;
	}
	secure_free((void **)&tmp);
	close(fd);
	return (i);
}

static char	**get_lines(int fd, int num)
{
	int		i;
	char	*tmp;
	char	**lines;

	i = 0;
	tmp = get_next_line(fd);
	if (!tmp)
		return (NULL);
	lines = malloc(sizeof(char *) * (num + 1));
	while (tmp)
	{
		lines[i] = ft_strdup(tmp);
		i++;
		secure_free((void **)&tmp);
		tmp = get_next_line(fd);
	}
	lines[i] = NULL;
	return (lines);
}

static void	_init(t_c3d *c3d)
{
	ft_bzero(&(c3d->keys), sizeof(t_keys));
	c3d->ray = NULL;
	c3d->dply.win = NULL;
	c3d->dply.mlx = NULL;
	c3d->player = NULL;
	c3d->map = NULL;
	c3d->ceiling_color = 0;
	c3d->floor_color = 0;
}

/**
 * @brief Initialize the main structure
 * 
 * @param av: Arguments given to the program
 * @return Returns a pointer to the main cub3D structure.
 */
t_c3d	*init(char **av)
{
	int		fd;
	char	**lines;
	t_c3d	*c3d;
	int		i;

	i = -1;
	c3d = malloc(sizeof(t_c3d));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		secure_free((void **)&c3d);
		return (NULL);
	}
	_init(c3d);
	lines = get_lines(fd, count_lines(av[1]));
	c3d->map = get_map(lines, count_lines(av[1]));
	get_textures(lines, c3d);
	get_colors(lines, c3d);
	while (lines && lines[++i])
		secure_free((void **)&lines[i]);
	secure_free((void **)&lines);
	close(fd);
	return (c3d);
}

int	ismap(char *str)
{
	int	i;

	i = 0;
	if (is_empty(str))
		return (EXIT_FAILURE);
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] && ft_isalpha(str[i]))
			return (EXIT_FAILURE);
		if (i >= (int)ft_strlen(str))
			break ;
		i++;
	}
	return (EXIT_SUCCESS);
}
