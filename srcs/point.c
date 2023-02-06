/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:08:46 by stelie            #+#    #+#             */
/*   Updated: 2023/02/06 16:33:40 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Adds the given x and y to the t_point a
 * @return Returns the t_point.
 */
t_point	add_point(t_point p, float x, float y)
{
	p.x += x;
	p.y += y;
	return (p);
}

/**
 * @brief add_two_points(a,b) is equivalent to (a + b).
 * @return The addition of the two t_point.
 */
t_point	add_two_points(t_point a, t_point b)
{
	a.x += b.x;
	a.y += b.y;
	return (a);
}

/**
 * @brief Initializes a t_point with the given x and y.
 * @return the created t_point.
 */
t_point	init_point(int x, int y)
{
	t_point	p;

	p.x = x;
	p.y = y;
	return (p);
}
