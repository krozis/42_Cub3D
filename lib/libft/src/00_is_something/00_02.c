/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_02.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:15:21 by krozis            #+#    #+#             */
/*   Updated: 2023/02/02 12:29:11 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief Tells if a character is a lowercase letter.
 * @return returns true if c is a lowercase letter, false if not.
*/
bool	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (true);
	return (false);
}

/*
 * @brief Tells if a character is an uppercase letter.
 * @return returns true if c is an uppercase letter, false if not.
*/
bool	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (true);
	return (false);
}

/**
 * @brief Tells if a string is empty (size < 1 or full of spaces)
 * @return true or false 
 */
bool	is_empty(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (true);
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (false);
		i++;
	}
	return (true);
}
