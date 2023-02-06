/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:14:14 by dcyprien          #+#    #+#             */
/*   Updated: 2023/02/06 17:31:37 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	free_them_all(t_c3d *c3d)
{
	int	i;

	i = -1;
	if (c3d)
	{
		if (c3d->map)
			while (c3d->map[++i])
				secure_free((void **)&c3d->map[i]);
		secure_free((void **)&c3d->map);
		secure_free((void **)&c3d->text[N_TEXT]);
		secure_free((void **)&c3d->text[S_TEXT]);
		secure_free((void **)&c3d->text[W_TEXT]);
		secure_free((void **)&c3d->text[E_TEXT]);
		secure_free((void **)&c3d->player);
		secure_free((void **)&c3d->ray);
		if (c3d->dply.mlx)
			free_mlx(c3d, true, EXIT_SUCCESS);
		secure_free((void **)&c3d);
	}
}
