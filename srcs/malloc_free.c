/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:14:14 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/17 10:57:52 by stelie           ###   ########.fr       */
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
	secure_free((void **)&ptr->text[N_TEXT]);
	secure_free((void **)&ptr->text[S_TEXT]);
	secure_free((void **)&ptr->text[W_TEXT]);
	secure_free((void **)&ptr->text[E_TEXT]);
	secure_free((void **)&ptr);
}
