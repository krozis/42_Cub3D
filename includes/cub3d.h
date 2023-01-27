/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:14:59 by dcyprien          #+#    #+#             */
/*   Updated: 2023/01/27 16:45:55 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// WINDOWS INFORMATIONS
# define OPEN_MAX 1024
# define BUFFER_SIZE 1024
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define WIN_NAME "Cub3D"

//GRID and PLAYER INFORMATIONS
# define BOX_SIZE 64
# define PLAYER_SIZE 32
# define ROTATION_SPEED 0.05

//	ERROR CODES
# define ERR_TWO_START 4
# define ERR_NO_START 3
# define EXIT_CONTINUE 2
# define ERR_COLOR_CHAR -3
# define ERR_MISS_LINE -2
# define ERR_INV_VAL -1

// COLOR VALUES
# define RGB_RED 65536
# define RGB_GREEN 256
# define RGB_BLUE 1

//INCLUDES
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
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
 * @brief player structure
 * @param posX: player X position on the map
 * @param posY: player Y position on the map
 * @param dirX: direction X of the player (which side the player is facing). Can be 1, -1 or 0
 * @param dirY: direction Y of the player (which side the player is facing). Can be 1, -1 or 0
 * @param planeX: value X of the camera plane
 * @param planeY: value Y of the camera plane
*/
typedef struct	s_player
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	char		dir;
}				t_player;

/**
 * @brief Raycasting structure
 * @param raydirX: direction X of the ray
 * @param raydirY: directyion Y of the ray
 * @param cameraX: X-coordinate on the camera plane that the X-coordinate on the screen represent
 * @param mapX: X-coordinate of the current position of the ray
 * @param mapY: Y-coordinate of the current position of the ray
 * @param sideDistX: distance between current position of the ray and next X side of a case
 * @param sideDistY: distance between current position of the ray and next Y side of a case
 * @param deltaDistX: distance between next X side of a case and the one after (next X side + 1)
 * @param deltaDistY: distance between next Y side of a case and the one after (next Y side + 1)
 * @param perpwallDist: distance between next wall and the camera plane (perpendicularly)
 * @param stepX: value of incrementation for the X value of the ray
 * @param stepY: value of incrementation for the Y value of the ray
 * @param side: int for saying if we hitted a wall on the X side or the Y side
 * @param hit: says if a wall has been hit or not
*/
typedef struct	s_ray
{
	double	raydirX;
	double	raydirY;
	double	cameraX;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		side;
	int		hit;
	double	oldperpwall;
}				t_ray;

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
	t_img	*screen;
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
	char		**map;
	char		*text[4];
	int			ceiling_color;
	int			floor_color;
	t_player	*player;
	t_dply		dply;
	t_ray		*ray;
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
void	init_structs(t_ptr *ptr);
void	init_ray(t_ptr *ptr);
void	init_dda(t_ptr *ptr);
void	set_dir(t_ptr *ptr, char c);
//void	init_player(t_ptr *ptr);
void	init_dda_2(t_ptr *ptr);

/*
	UTILITY FUNCTIONS
*/
int		empty_line(char *str);
void	free_them_all(t_ptr *ptr);
int		ismap(char *str);
void	secure_free(void **ptr);
void	close_fds(int *fds);
int		convert_colors(int r, int g, int b);

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
int		check_color_line_ceiling(char *str, t_ptr *ptr, int start);
int		check_color_line_floor(char *str, t_ptr *ptr, int start);
int		check_digit(char *str);

/*
 * DISPLAYING WITH MLX
*/

int		init_mlx(t_ptr *c3d);
int		free_mlx(t_ptr *c3d, bool txt, bool bg, int exit_code);
int		background_image(t_ptr *c3d);

/*
 * RAYCASTING
*/

void	raycasting(t_ptr *ptr);
void	drawline(t_ptr *ptr, int x, int drawstart, int drawend);
void	set_raycasting(t_ptr *ptr);

/*
 * PLAYER
*/

int		init_player(t_player **player, char **map);

/*
 * MOVEMENT
*/

void	rotate(t_ptr *c3d, int key);

#endif