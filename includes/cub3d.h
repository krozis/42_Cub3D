/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:14:59 by dcyprien          #+#    #+#             */
/*   Updated: 2023/02/03 13:51:15 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// WINDOWS INFORMATIONS
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define WIN_NAME "Cub3D"

//GRID and PLAYER INFORMATIONS
# define ROTATION_SPEED 0.03
# define MOVE_SPEED 0.075

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
# define MAP_PLAYER_COLOR 16724530

//INCLUDES
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
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
 * @param pos_x: player X position on the map
 * @param pos_y: player Y position on the map
 * @param dir_x: direction X of the player (which side the player is facing).
 * Can be 1, -1 or 0
 * @param dir_y: direction Y of the player (which side the player is facing).
 * Can be 1, -1 or 0
 * @param plane_x: value X of the camera plane
 * @param plane_y: value Y of the camera plane
*/
typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	char	dir;
}				t_player;

/**
 * @brief Raycasting structure
 * @param raydir_x: direction X of the ray
 * @param raydir_y: directyion Y of the ray
 * @param camera_x: X-coordinate on the camera plane that the X-coordinate
 * on the screen represent
 * @param map_x: X-coordinate of the current position of the ray
 * @param map_y: Y-coordinate of the current position of the ray
 * @param side_x: distance between current position of the ray and
 * next X side of a case
 * @param side_y: distance between current position of the ray and
 * next Y side of a case
 * @param delta_x: distance between next X side of a case and the one
 * after (next X side + 1)
 * @param delta_y: distance between next Y side of a case and the one
 * after (next Y side + 1)
 * @param perpwallDist: distance between next wall and the camera plane
 * (perpendicularly)
 * @param step_x: value of incrementation for the X value of the ray
 * @param step_y: value of incrementation for the Y value of the ray
 * @param side: int for saying if we hitted a wall on the X side or the Y side
 * @param hit: says if a wall has been hit or not
*/
typedef struct s_ray
{
	double	raydir_x;
	double	raydir_y;
	double	camera_x;
	int		map_x;
	int		map_y;
	int		side;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	perp_dist;
	int		step_x;
	int		step_y;
	int		hit;
	double	oldperpwall;
	double	wall_x;
	int		txt_nb;
	int		drawval[2];
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
	t_img	*screen;
	t_img	*n_texture;
	t_img	*s_texture;
	t_img	*e_texture;
	t_img	*w_texture;
	t_img	*minimap;
}				t_dply;

typedef struct s_keys
{
	bool	move_front;
	bool	move_back;
	bool	move_left;
	bool	move_right;
	bool	rotate_left;
	bool	rotate_mouse_left;
	bool	rotate_mouse_right;
	bool	rotate_right;
	bool	minimap;
}				t_keys;

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
	t_keys		keys;
}				t_ptr;

/*
 * MAIN / INIT / PARSING
*/

t_ptr	*init(char **av);
void	get_colors(char **lines, t_ptr *ptr);
void	init_structs(t_ptr *ptr);
void	init_ray(t_ptr *ptr);
void	init_dda(t_ptr *ptr);
void	set_dir(t_ptr *ptr, char c);
void	init_dda_2(t_ptr *ptr);

/*
	ERROR CHECKING FUNCTIONS
*/

int		verify_args(int ac, char **av);
int		check_errors(t_ptr *ptr);
int		check_colors(int color[3]);
int		check_ones(char **map, int i, int k);
int		check_color_line_ceiling(char *str, t_ptr *ptr, int start);
int		check_color_line_floor(char *str, t_ptr *ptr, int start);
int		check_digit(char *str);
int		text_is_dir(t_ptr *ptr);

/*
 * TEXTURES
*/

void	get_textures(char **lines, t_ptr *ptr);
int		check_texture(t_ptr *c3d);

/*
 * MAP
*/

char	**get_map(char **lines, int num);
int		check_chars(char **map);
int		check_integrity(char **map);

/*
	UTILITY FUNCTIONS
*/
void	free_them_all(t_ptr *ptr);
int		ismap(char *str);
void	close_fds(int *fds);
int		convert_colors(int r, int g, int b);

/*
 * DISPLAYING WITH MLX
*/

int		init_mlx(t_ptr *c3d);
int		free_mlx(t_ptr *c3d, bool txt, int exit_code);
int		background_image(t_ptr *c3d);

/*
 * RAYCASTING
*/

void	raycasting(t_ptr *ptr);
void	drawline(t_ptr *ptr, int x);
int		text_num(t_ptr *ptr);

/*
 * PLAYER
*/

int		init_player(t_player **player, char **map);

/*
 * MOVEMENT
*/

void	rotate(t_ptr *c3d);
void	move(t_ptr *c3d);
void	minimap(t_ptr *c3d);

#endif