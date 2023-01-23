/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:26:04 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/21 21:26:24 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	convert_colors(int r, int g, int b)
{
	return ((r * RGB_RED) + (g * RGB_GREEN) + b);
}

static void	ceiling_color(char *str, t_ptr *ptr, int i)
{
	int	ceiling[3];

	i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!ft_isdigit(str[i]) && !ft_isspace(str[i]))
		ceiling[0] = ERR_INV_VAL;
	else
		ceiling[0] = ft_atoi(&str[i]);
	while (str[i] && str[i++] != ',')
		;
	if (check_digit(&str[i]) == EXIT_FAILURE)
		ceiling[1] = ERR_INV_VAL;
	else
		ceiling[1] = ft_atoi(&str[i]);
	while (str[i] && str[i++] != ',')
		;
	if (check_digit(&str[i]) == EXIT_FAILURE)
		ceiling[2] = ERR_INV_VAL;
	else
		ceiling[2] = ft_atoi(&str[i]);
	if (check_colors(ceiling) == EXIT_SUCCESS)
		ptr->ceiling_color = convert_colors(ceiling[0], ceiling[1], ceiling[2]);
	else
		ptr->ceiling_color = ERR_INV_VAL;
}

static void	floor_color(char *str, t_ptr *ptr, int i)
{
	int	floor[3];

	i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!ft_isdigit(str[i]) && !ft_isspace(str[i]))
		floor[0] = ERR_INV_VAL;
	else
		floor[0] = ft_atoi(&str[i]);
	while (str[i] && str[i++] != ',')
		;
	if (check_digit(&str[i]) == EXIT_FAILURE)
		floor[1] = ERR_INV_VAL;
	else
		floor[1] = ft_atoi(&str[i]);
	while (str[i] && str[i++] != ',')
		;
	if (check_digit(&str[i]) == EXIT_FAILURE)
		floor[2] = ERR_INV_VAL;
	else
		floor[2] = ft_atoi(&str[i]);
	if (check_colors(floor) == EXIT_SUCCESS)
		ptr->floor_color = convert_colors(floor[0], floor[1], floor[2]);
	else
		ptr->floor_color = ERR_INV_VAL;
}

static void	set_colors(char *str, t_ptr *ptr)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == 'C' && check_color_line_ceiling(str, ptr, i + 1)
		== EXIT_SUCCESS)
		ceiling_color(str, ptr, i);
	if (str[i] == 'F' && check_color_line_floor(str, ptr, i + 1)
		== EXIT_SUCCESS)
		floor_color(str, ptr, i);
}

/**
 * @brief Get colors in the lines starting by F or C
 * 
 * @param lines the lines that have been read in the map file
 * @param ptr the main structure
 */
void	get_colors(char **lines, t_ptr *ptr)
{
	int	i;
	int	k;

	i = 0;
	ptr->floor_color = ERR_MISS_LINE;
	ptr->ceiling_color = ERR_MISS_LINE;
	if (!lines)
		return ;
	while (lines[i])
	{
		k = 0;
		while (lines[i] && empty_line(lines[i]) == EXIT_SUCCESS)
			i++;
		if (!lines[i])
			return ;
		while (lines[i][k] && ft_isspace(lines[i][k]))
			k++;
		if (ft_incharset(lines[i][k], "FC"))
			set_colors(lines[i], ptr);
		if (ptr->floor_color >= 0 && ptr->ceiling_color >= 0)
			break ;
		i++;
	}
}
