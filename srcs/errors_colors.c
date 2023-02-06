/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:49:01 by dcyprien          #+#    #+#             */
/*   Updated: 2023/02/06 17:31:37 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (!str[i] || !ft_isdigit(str[i]))
			return (EXIT_FAILURE);
		else
			return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

int	check_color_line_ceiling(char *str, t_c3d *c3d, int start)
{
	int	i;

	i = start;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] && !ft_isdigit(str[i]) && str[i] != ',')
		{
			c3d->ceiling_color = ERR_COLOR_CHAR;
			return (EXIT_FAILURE);
		}
		if (!str[i])
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_color_line_floor(char *str, t_c3d *c3d, int start)
{
	int	i;

	i = start;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] && !ft_isdigit(str[i]) && str[i] != ',')
		{
			c3d->floor_color = ERR_COLOR_CHAR;
			return (EXIT_FAILURE);
		}
		if (!str[i])
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_colors(int color[3])
{
	if (color[0] < 0 || color[0] > 255)
		return (EXIT_FAILURE);
	if (color[1] < 0 || color[1] > 255)
		return (EXIT_FAILURE);
	if (color[2] < 0 || color[2] > 255)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
