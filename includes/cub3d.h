/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:14:59 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/19 14:38:07 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// WINDOWS INFORMATIONS
# define OPEN_MAX 1024
# define BUFFER_SIZE 1024
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define WIN_NAME "Cub3D"

//GRID and PLAYER INFORMATIONS
# define BOX_SIZE 64
# define PLAYER_SIZE 32

//	ERROR CODES
# define ERR_TWO_START 4
# define ERR_NO_START 3

// COLOR VALUES
# define RGB_RED 65536
# define RGB_GREEN 256
# define RGB_BLUE 1

//INCLUDES
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../lib/mlx-linux/mlx_int.h"
# include "../lib/mlx-linux/mlx.h"
# include "../lib/libft/includes/libft.h"

typedef enum e_textures_values
{
	N_TEXT,
	S_TEXT,
	W_TEXT,
	E_TEXT
}			t_txtval;

/**
 * @brief Displaying main structure
 * @param mlx: the identifier of the connection to the graphic server
 * @param win: the identifier of the window
 * @param bg: the background image (ceiling+floor)
 * @param textures[4]: the 4 mlx's images for the NSWE textures
 */
typedef struct s_display
{
	void	*mlx;
	void	*win;
	t_img	*bg;
	t_img	textures[4];
}				t_dply;

/**
 * @brief cub3D main structure
 * @param map: map in char[ ][ ] grid format
 * @param text: strigns containing the 4 paths to open texture files
 * @param ceiling_color: color of the ceiling in int value
 * @param floor_color: color of the floor in int value
 */
typedef struct s_ptr{
	char	**map;
	char	*text[4];
	int		ceiling_color;
	int		floor_color;
	t_dply	dply;
}				t_ptr;

/*
 * MAIN / INIT / PARSING
*/

t_ptr	*init(char **av);
char	**get_map(char **lines, int num);
void	get_textures(char **lines, t_ptr *ptr);
char	*text(char *str);
int		set_texture(t_ptr *ptr, char *str);
void	get_colors(char **lines, t_ptr *ptr);

/*
	UTILITY FUNCTIONS
*/
int		empty_line(char *str);
void	free_them_all(t_ptr *ptr);
int		ismap(char *str);
void	secure_free(void **ptr);
void	close_fds(int *fds);

/*
	ERROR CHECKING FUNCTIONS
*/
int		verify_args(int ac, char **av);
int		check_errors(t_ptr *ptr);
int		check_texture(t_ptr *ptr);
int		check_colors(int color[3]);
int		check_empty_line(char **map);
int		check_chars(char **map);
int		check_borders(char **map);
int		check_integrity(char **map);
int		check_ones(char **map, int i, int k);

/*
 * DISPLAYING WITH MLX
*/

int		init_mlx(t_ptr *c3d);
int		free_mlx(t_ptr *c3d, bool txt, bool bg, int exit_code);
int		background_image(t_ptr *c3d);

#endif