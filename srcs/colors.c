/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:26:04 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/16 17:21:36 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_color(t_ptr *ptr)
{
	ptr->floor[0] = 0;
	ptr->floor[1] = 0;
	ptr->floor[2] = 0;
	ptr->ceiling[0] = 0;
	ptr->ceiling[1] = 0;
	ptr->ceiling[2] = 0;
}

void	floor_color(char *str, t_ptr *ptr, int i)
{
	i++;
	ptr->floor[0] = ft_atoi(&str[i]);
	while (str[i++] != ',')
		;
	ptr->floor[1] = ft_atoi(&str[i]);
	while (str[i++] != ',')
		;
	ptr->floor[2] = ft_atoi(&str[i]);
}

void	set_colors(char *str, t_ptr *ptr)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == 'C')
	{
		i++;
		ptr->ceiling[0] = ft_atoi(&str[i]);
		while (str[i++] != ',')
			;
		ptr->ceiling[1] = ft_atoi(&str[i]);
		while (str[i++] != ',')
			;
		ptr->ceiling[2] = ft_atoi(&str[i]);
	}
	if (str[i] == 'F')
		floor_color(str, ptr, i);
}

void	get_colors(char **lines, t_ptr *ptr)
{
	int	i;
	int	k;

	i = 0;
	init_color(ptr);
	while (lines[i])
	{
		k = 0;
		while (empty_line(lines[i]))
			i++;
		while (ft_isspace(lines[i][k]))
			k++;
		if (ft_incharset(lines[i][k], "FC"))
			set_colors(lines[i], ptr);
		i++;
	}
}
