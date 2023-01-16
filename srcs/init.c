/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:05:28 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/16 17:22:54 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	count_lines(char *av)
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

char	**get_lines(int fd, int num)
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
		return (NULL);
	lines = get_lines(fd, count_lines(av[1]));
	ptr->map = get_map(lines, count_lines(av[1]));
	get_textures(lines, ptr);
	get_colors(lines, ptr);
	while (lines[++i])
		secure_free((void **)&lines[i]);
	secure_free((void **)&lines);
	return (ptr);
}
