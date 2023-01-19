/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:37:30 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/19 20:05:15 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	set_texture(t_ptr *ptr, char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == 'N' && !ptr->text[N_TEXT])
		ptr->text[N_TEXT] = text(str);
	if (str[i] == 'S' && !ptr->text[S_TEXT])
		ptr->text[S_TEXT] = text(str);
	if (str[i] == 'W' && !ptr->text[W_TEXT])
		ptr->text[W_TEXT] = text(str);
	if (str[i] == 'E' && !ptr->text[E_TEXT])
		ptr->text[E_TEXT] = text(str);
	if (ft_incharset(str[i], "FC"))
		return (EXIT_CONTINUE);
	if (!ft_incharset(str[i], "NEWS"))
		return (EXIT_FAILURE);
	else if (ft_incharset(str[i], "NEWS"))
		return (EXIT_CONTINUE);
	return (EXIT_SUCCESS);
}

void	get_textures(char **lines, t_ptr *ptr)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	ptr->text[N_TEXT] = NULL;
	ptr->text[S_TEXT] = NULL;
	ptr->text[E_TEXT] = NULL;
	ptr->text[W_TEXT] = NULL;
	if (!lines)
		return ;
	while (count < 4)
	{
		while (lines[i] && empty_line(lines[i]) == EXIT_SUCCESS)
			i++;
		if (set_texture(ptr, lines[i]) == EXIT_FAILURE)
			return ;
		else if (set_texture(ptr, lines[i]) == EXIT_SUCCESS)
			count++;
		i++;
	}
}
