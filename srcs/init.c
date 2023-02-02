/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:05:28 by dcyprien          #+#    #+#             */
/*   Updated: 2023/02/02 11:47:56 by krozis           ###   ########.fr       */
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

static void	_init(t_ptr *c3d)
{
	ft_bzero(&(c3d->keys), sizeof(t_keys));
	c3d->ray = NULL;
	c3d->dply.win = NULL;
	c3d->dply.minimap = NULL;
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
t_ptr	*init(char **av)
{
	int		fd;
	char	**lines;
	t_ptr	*ptr;
	int		i;

	i = -1;
	ptr = malloc(sizeof(t_ptr));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		secure_free((void **)&ptr);
		return (NULL);
	}
	_init(ptr);
	lines = get_lines(fd, count_lines(av[1]));
	ptr->map = get_map(lines, count_lines(av[1]));
	get_textures(lines, ptr);
	get_colors(lines, ptr);
	while (lines && lines[++i])
		secure_free((void **)&lines[i]);
	secure_free((void **)&lines);
	close(fd);
	return (ptr);
}
