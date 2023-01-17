/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:08:58 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/17 12:40:43 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**get_map(char **lines, int num)
{
	int		i;
	int		k;
	char	**map;

	k = 0;
	i = 0;
	while (lines[i] && ismap(lines[i]) == EXIT_FAILURE)
		i++;
	map = malloc(sizeof(char *) * ((num - i) + 1));
	while (lines[i])
	{
		map[k] = ft_strdup(lines[i]);
		i++;
		k++;
	}
	map[k] = NULL;
	return (map);
}
