/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:37:30 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/16 12:54:48 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/libft.h"

int		empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!isspace(str[i]))
			return (0);
	}
	return (1);
}

void	set_texture(t_ptr *ptr, char *str)
{
	int	i;

	i = 0;
	while (str[i] && isspace(str[i]))
		i++;
	if (str[i] == )
}

void	get_textures(char **lines, t_ptr *ptr)
{
	int i;

	i = 0;
	ptr->n_text = NULL;
	ptr->s_text = NULL;
	ptr->e_text = NULL;
	ptr->w_text = NULL;
	while (!ptr->n_text || !ptr->s_text || !ptr->e_text && !ptr->w_text)
	{
		if (!empty_line(lines[i]))
			i++;
		set_texture(ptr, lines[i]);
	}
}