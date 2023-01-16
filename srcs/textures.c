/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:37:30 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/16 16:59:56 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

 int		set_texture(t_ptr *ptr, char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == 'N')
		ptr->n_text = text(str);
	else if (str[i] == 'S')
		ptr->s_text = text(str);
	else if (str[i] == 'W')
		ptr->w_text = text(str);
	else if (str[i] == 'E')
		ptr->e_text = text(str);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	get_textures(char **lines, t_ptr *ptr)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	ptr->n_text = NULL;
	ptr->s_text = NULL;
	ptr->e_text = NULL;
	ptr->w_text = NULL;
	while (count < 4)
	{
		if (empty_line(lines[i]))
			i++;
		if (set_texture(ptr, lines[i]) == EXIT_FAILURE)
			return ;
		i++;
		count++;
	}
}