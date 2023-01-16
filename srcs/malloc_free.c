/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:14:14 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/16 17:23:49 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	secure_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_them_all(t_ptr *ptr)
{
	int	i;

	i = -1;
	while (ptr->map[++i])
		secure_free((void **)&ptr->map[i]);
	secure_free((void **)&ptr->map);
	secure_free((void **)&ptr->n_text);
	secure_free((void **)&ptr->s_text);
	secure_free((void **)&ptr->w_text);
	secure_free((void **)&ptr->e_text);
	secure_free((void **)&ptr);
}
