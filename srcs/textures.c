/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:37:30 by dcyprien          #+#    #+#             */
/*   Updated: 2023/02/02 11:46:34 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*text(char *str)
{
	int	i;
	int	k;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	k = i;
	while (str[k] && !ft_isspace(str[k]))
		k++;
	return (ft_substr(str, i, k - i));
}

static int	set_texture(t_ptr *c3d, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (EXIT_FAILURE);
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == 'N' && !c3d->text[N_TEXT])
		c3d->text[N_TEXT] = text(str);
	if (str[i] == 'S' && !c3d->text[S_TEXT])
		c3d->text[S_TEXT] = text(str);
	if (str[i] == 'W' && !c3d->text[W_TEXT])
		c3d->text[W_TEXT] = text(str);
	if (str[i] == 'E' && !c3d->text[E_TEXT])
		c3d->text[E_TEXT] = text(str);
	if (ft_incharset(str[i], "FC"))
		return (EXIT_CONTINUE);
	if (!ft_incharset(str[i], "NEWS"))
		return (EXIT_FAILURE);
	else if (ft_incharset(str[i], "NEWS"))
		return (EXIT_CONTINUE);
	return (EXIT_SUCCESS);
}

/**
 * @brief Stores the textures files names in the main cub3D structure.
 * 
 * @param c3d: a pointer to the main cub3D structure
 */
void	get_textures(char **lines, t_ptr *c3d)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	c3d->text[N_TEXT] = NULL;
	c3d->text[S_TEXT] = NULL;
	c3d->text[E_TEXT] = NULL;
	c3d->text[W_TEXT] = NULL;
	if (!lines)
		return ;
	while (count < 4)
	{
		while (lines[i] && empty_line(lines[i]) == EXIT_SUCCESS)
			i++;
		if (set_texture(c3d, lines[i]) == EXIT_FAILURE)
			return ;
		else if (set_texture(c3d, lines[i]) == EXIT_SUCCESS)
			count++;
		i++;
	}
}

/**
 * @brief Checks if the texture files are OK and can be opened.
 * 
 * @param c3d: a pointer to the main cub3D structure
 * @return EXIT_SUCCESS or EXIT_FAILURE
 */
int	check_texture(t_ptr *c3d)
{
	int	fd[4];

	if (!c3d->text[N_TEXT])
		return (EXIT_FAILURE);
	fd[0] = open(c3d->text[N_TEXT], O_RDONLY);
	if (fd[0] < 0)
		return (EXIT_FAILURE);
	if (!c3d->text[S_TEXT])
		return (EXIT_FAILURE);
	fd[1] = open(c3d->text[S_TEXT], O_RDONLY);
	if (fd[1] < 0)
		return (EXIT_FAILURE);
	if (!c3d->text[E_TEXT])
		return (EXIT_FAILURE);
	fd[2] = open(c3d->text[E_TEXT], O_RDONLY);
	if (fd[2] < 0)
		return (EXIT_FAILURE);
	if (!c3d->text[W_TEXT])
		return (EXIT_FAILURE);
	fd[3] = open(c3d->text[W_TEXT], O_RDONLY);
	if (fd[3] < 0)
		return (EXIT_FAILURE);
	close_fds(fd);
	return (EXIT_SUCCESS);
}
