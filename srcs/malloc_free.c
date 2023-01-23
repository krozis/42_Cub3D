/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:14:14 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/23 12:47:23 by stelie           ###   ########.fr       */
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
	if (ptr)
	{
		if (ptr->map)
			while (ptr->map[++i])
				secure_free((void **)&ptr->map[i]);
		secure_free((void **)&ptr->map);
		secure_free((void **)&ptr->text[N_TEXT]);
		secure_free((void **)&ptr->text[S_TEXT]);
		secure_free((void **)&ptr->text[W_TEXT]);
		secure_free((void **)&ptr->text[E_TEXT]);
		secure_free((void **)&ptr->player);
		secure_free((void **)&ptr->ray);
		if (ptr->dply.mlx)
			free_mlx(ptr, true, true, EXIT_SUCCESS);
		secure_free((void **)&ptr);
	}
}
