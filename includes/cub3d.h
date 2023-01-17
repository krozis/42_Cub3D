/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:14:59 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/16 18:37:03 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define OPEN_MAX 1024
# define BUFFER_SIZE 1024
# define WIN_WIDTH 1024
# define WIN_HEIGHT 768
# define WIN_NAME "Cub3D"

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../lib/mlx-linux/mlx_int.h"
# include "../lib/mlx-linux/mlx.h"
# include "../lib/libft/includes/libft.h"

typedef enum e_textures
{
	N_TEXT,
	S_TEXT,
	W_TEXT,
	E_TEXT
}			t_textures;

typedef struct s_pic
{
	void	*img;
	int		height;
	int		width;
}				t_pic;

typedef struct s_display
{
	void	*mlx;
	void	*win;
	t_pic	textures[4];
}				t_dply;

typedef struct s_ptr{
	char	**map;
	char	*n_text;
	char	*s_text;
	char	*e_text;
	char	*w_text;
	void	*mlx_ptr;
	int		floor[3];
	int		ceiling[3];
	t_dply	dply;
}				t_ptr;

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
int		verify_args(int ac, char **av);
int		check_errors(t_ptr *ptr);
int		check_texture(t_ptr *ptr);
int		check_colors(t_ptr *ptr);

int		init_mlx(t_ptr *c3d);

#endif