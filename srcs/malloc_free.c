/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:14:14 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/17 15:33:44 by dcyprien         ###   ########.fr       */
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

void	close_fds(int *fds)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (fds[i] > 0)
			close(fds[i]);
		i++;
	}
}

void	free_them_all(t_ptr *ptr)
{
	int	i;

	i = -1;
	if (ptr->map)
		while (ptr->map[++i])
			secure_free((void **)&ptr->map[i]);
	secure_free((void **)&ptr->map);
	secure_free((void **)&ptr->text[N_TEXT]);
	secure_free((void **)&ptr->text[S_TEXT]);
	secure_free((void **)&ptr->text[W_TEXT]);
	secure_free((void **)&ptr->text[E_TEXT]);
	secure_free((void **)&ptr);
}
