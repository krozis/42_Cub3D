/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:31:35 by dcyprien          #+#    #+#             */
<<<<<<< HEAD:lib/libft.old/ft_isspace.c
/*   Updated: 2023/01/16 14:59:07 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
=======
/*   Updated: 2023/01/16 14:20:19 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
>>>>>>> cyp:srcs/libft/ft_isspace.c

int	ft_isspace(const char c)
{
	return (ft_cinset(c, "\t\n\r\v\f "));
}
