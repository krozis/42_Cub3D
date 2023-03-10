/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:26:04 by dcyprien          #+#    #+#             */
/*   Updated: 2023/02/06 17:31:37 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ceiling_color(char *str, t_c3d *c3d, int i)
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
		c3d->ceiling_color = rgb_to_int(ceiling[0], ceiling[1], ceiling[2]);
	else
		c3d->ceiling_color = ERR_INV_VAL;
}

static void	floor_color(char *str, t_c3d *c3d, int i)
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
		c3d->floor_color = rgb_to_int(floor[0], floor[1], floor[2]);
	else
		c3d->floor_color = ERR_INV_VAL;
}

static void	set_colors(char *str, t_c3d *c3d)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == 'C' && check_color_line_ceiling(str, c3d, i + 1)
		== EXIT_SUCCESS)
		ceiling_color(str, c3d, i);
	if (str[i] == 'F' && check_color_line_floor(str, c3d, i + 1)
		== EXIT_SUCCESS)
		floor_color(str, c3d, i);
}

/**
 * @brief Get colors in the lines starting by F or C
 * 
 * @param lines the lines that have been read in the map file
 * @param c3d the main structure
 */
void	get_colors(char **lines, t_c3d *c3d)
{
	int	i;
	int	k;

	i = 0;
	c3d->floor_color = ERR_MISS_LINE;
	c3d->ceiling_color = ERR_MISS_LINE;
	if (!lines)
		return ;
	while (lines[i])
	{
		k = 0;
		while (lines[i] && is_empty(lines[i]))
			i++;
		if (!lines[i])
			return ;
		while (lines[i][k] && ft_isspace(lines[i][k]))
			k++;
		if (ft_incharset(lines[i][k], "FC"))
			set_colors(lines[i], c3d);
		if (c3d->floor_color >= 0 && c3d->ceiling_color >= 0)
			break ;
		i++;
	}
}
