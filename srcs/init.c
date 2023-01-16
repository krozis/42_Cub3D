/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:05:28 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/16 12:42:26 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/libft.h"

int		count_lines(char *av)
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
	lines = malloc(sizeof(char *) * num);
	while (tmp)
	{
		lines[i] = ft_strdup(tmp);
		i++;
		secure_free((void**)&tmp);
		tmp = get_next_line(fd);
	}
	lines[i] = NULL;
	return (lines);
}

void	*init(char **av)
{
	int	fd;
	char **lines;
	char *tmp;
	t_ptr *ptr;

	ptr = malloc(sizeof(t_ptr));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	lines = get_lines(fd, count_lines(av[1]));
	ptr->map = get_map(lines, count_lines(av[1]));
	get_textures(lines, ptr);
}