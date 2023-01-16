/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:36:47 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/16 16:59:56 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*text(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	return (ft_substr(str, i, ft_strlen(str) - i));
}