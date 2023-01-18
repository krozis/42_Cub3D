/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:26:04 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/18 12:09:47 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	convert_colors(int r, int g, int b)
{
	int	color;

	color = (r * RGB_RED) + (g * RGB_GREEN) + (b * RGB_BLUE);
	return (color);
}

static void	ceiling_color(char *str, t_ptr *ptr, int i)
{
	int	ceiling[3];

	i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
		ceiling[0] = -1;
	else
		ceiling[0] = ft_atoi(&str[i]);
	while (str[i++] != ',')
		;
	if (!ft_isdigit(str[i]))
		ceiling[1] = -1;
	else
		ceiling[1] = ft_atoi(&str[i]);
	while (str[i++] != ',')
		;
	if (!ft_isdigit(str[i]))
		ceiling[2] = -1;
	else
		ceiling[2] = ft_atoi(&str[i]);
	if (check_colors(ceiling) == EXIT_SUCCESS)
		ptr->ceiling_color = convert_colors(ceiling[0], ceiling[1], ceiling[2]);
}

static void	floor_color(char *str, t_ptr *ptr, int i)
{
	int	floor[3];

	i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
		floor[0] = -1;
	else
		floor[0] = ft_atoi(&str[i]);
	while (str[i++] != ',')
		;
	if (!ft_isdigit(str[i]))
		floor[1] = -1;
	else
		floor[1] = ft_atoi(&str[i]);
	while (str[i++] != ',')
		;
	if (!ft_isdigit(str[i]))
		floor[2] = -1;
	else
		floor[2] = ft_atoi(&str[i]);
	if (check_colors(floor) == EXIT_SUCCESS)
		ptr->floor_color = convert_colors(floor[0], floor[1], floor[2]);
}

static void	set_colors(char *str, t_ptr *ptr)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == 'C')
		ceiling_color(str, ptr, i);
	if (str[i] == 'F')
		floor_color(str, ptr, i);
}

/**
 * TODO: if multiple F/C lines, the last one is used -> force only one?
 * TODO: can't read F/C line with spaces into the rgb code (ex: 25, 1, 50)
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
	ptr->floor_color = -1;
	ptr->ceiling_color = -1;
	if (!lines)
		return ;
	while (lines[i])
	{
		k = 0;
		while (empty_line(lines[i]) == EXIT_SUCCESS)
			i++;
		while (ft_isspace(lines[i][k]))
			k++;
		if (ft_incharset(lines[i][k], "FC"))
			set_colors(lines[i], ptr);
		i++;
	}
}
