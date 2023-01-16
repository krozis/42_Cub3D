/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:03:38 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/16 15:37:19 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/libft.h"

int		main(int ac, char **av)
{
	t_ptr	*ptr;

	(void)ac;
	ptr = init(av);
	printf("test map\n");
	for (int i = 0; ptr->map[i]; i++)
		printf("%s", ptr->map[i]);
	printf("\nnorth texture = %s\n", ptr->n_text);
	printf("south texture = %s\n", ptr->s_text);
	printf("east  texture = %s\n", ptr->e_text);
	printf("west  texture = %s\n", ptr->w_text);
	printf("\ncolors\n");
	printf("floor = %d,%d,%d\n", ptr->floor[0], ptr->floor[1],ptr->floor[2]);
	printf("ceili = %d,%d,%d\n", ptr->ceiling[0], ptr->ceiling[1],ptr->ceiling[2]);
	free_them_all(ptr);
	return (1);
}