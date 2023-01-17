/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:31:40 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/17 17:37:21 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	convert_colors(t_ptr *ptr)
{
	ptr->rgb_ceiling = (RGB_RED * ptr->ceiling[0]) + (RGB_GREEN * ptr->ceiling[1]) + ptr->ceiling[2];
	ptr->rgb_floor = (RGB_RED * ptr->floor[0]) + (RGB_GREEN * ptr->floor[1]) + ptr->floor[2];
}