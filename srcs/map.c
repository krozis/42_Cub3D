/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:08:58 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/16 12:36:29 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/libft.h"

char	**get_map(char **lines, int num)
{
	int		i;
	int		k;
	char	**map;

	k = 0;
	i = 0;
	while (!ismap(lines[i]))
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