/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:49:01 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/19 17:12:59 by dcyprien         ###   ########.fr       */
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

int	check_color_line_ceiling(char *str, t_ptr *ptr, int start)
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
			ptr->ceiling_color = -3;
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_color_line_floor(char *str, t_ptr *ptr, int start)
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
			ptr->floor_color = -3;
			return (EXIT_FAILURE);
		}
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
