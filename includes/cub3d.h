/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:14:59 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/16 15:35:34 by dcyprien         ###   ########.fr       */
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
	int		floor[3];
	int		ceiling[3];
}				t_ptr;

char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_strcmp(char *s1, char *s2);
int		ft_isspace(const char c);
t_ptr	*init(char **av);
void	secure_free(void **ptr);
char	**get_map(char **lines, int num);
void	get_textures(char **lines, t_ptr *ptr);
int		ismap(char *str);
char	*text(char *str);
int		set_texture(t_ptr *ptr, char *str);
void	free_them_all(t_ptr *ptr);
int		empty_line(char *str);
void	get_colors(char **lines, t_ptr *ptr);

#endif