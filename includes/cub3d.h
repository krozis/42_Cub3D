/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:14:59 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/16 12:31:17 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define OPEN_MAX 1024
# define BUFFER_SIZE 1024

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_ptr{
	char	**map;
	char	*n_text;
	char	*s_text;
	char	*e_text;
	char	*w_text;
	void	*mlx_ptr;
}				t_ptr;

char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_strcmp(char *s1, char *s2);
int		ft_isspace(const char c);

#endif