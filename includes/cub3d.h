/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:14:59 by dcyprien          #+#    #+#             */
/*   Updated: 2023/02/06 17:31:37 by stelie           ###   ########.fr       */
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

//MINIMAP VALUES
# define MAP_P_X 668
# define MAP_P_Y 501
# define MAP_BOX_W 24
# define MAP_BOX_H 18
# define MAP_PLAYER_COLOR 16724530
# define MAP_WALL_COLOR	3289650
# define MAP_FLOOR_COLOR 7239790

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
 * @brief Structure for colors with 3 int: r, g and b
 */
typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

/**
 * @brief Coordinates structure with x and y 
 */
typedef struct s_point
{
	double	x;
	double	y;
}				t_point;

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
}				t_dply;

/**
 * @brief Structure to precise if a key is pressed or not(only booleans)
 */
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
	bool	mouse_free;
}				t_keys;

/**
 * @brief cub3D main structure
 * @param map: map in char[ ][ ] grid format
 * @param text: strigns containing the 4 paths to open texture files
 * @param ceiling_color: color of the ceiling in int value
 * @param floor_color: color of the floor in int value
 */
typedef struct s_c3d{
	char		**map;
	char		*text[4];
	int			ceiling_color;
	int			floor_color;
	t_player	*player;
	t_dply		dply;
	t_ray		*ray;
	t_keys		keys;
}				t_c3d;

/*
 * MAIN / INIT / PARSING
*/

t_c3d	*init(char **av);
int		init_player(t_player **player, char **map);
void	get_colors(char **lines, t_c3d *c3d);
void	init_structs(t_c3d *c3d);
void	init_ray(t_c3d *c3d);
void	init_dda(t_c3d *c3d);
void	set_dir(t_c3d *c3d, char c);
void	init_dda_2(t_c3d *c3d);

/*
	ERROR CHECKING FUNCTIONS
*/

int		verify_args(int ac, char **av);
int		check_errors(t_c3d *c3d);
int		check_colors(int color[3]);
int		check_ones(char **map, int i, int k);
int		check_color_line_ceiling(char *str, t_c3d *c3d, int start);
int		check_color_line_floor(char *str, t_c3d *c3d, int start);
int		check_digit(char *str);
int		text_is_dir(t_c3d *c3d);

/*
 * TEXTURES
*/

void	get_textures(char **lines, t_c3d *c3d);
int		check_texture(t_c3d *c3d);

/*
 * MAP
*/

char	**get_map(char **lines, int num);
int		check_chars(char **map);
int		check_integrity(char **map);

/*
	UTILITY FUNCTIONS
*/
void	free_them_all(t_c3d *c3d);
int		ismap(char *str);
void	close_fds(int *fds);

/*
 * DISPLAYING WITH MLX
*/

int		init_mlx(t_c3d *c3d);
int		free_mlx(t_c3d *c3d, bool txt, int exit_code);

/*
 * RAYCASTING
*/

void	raycasting(t_c3d *c3d);
void	drawline(t_c3d *c3d, int x);
int		text_num(t_c3d *c3d);

/*
 * MOVEMENT
*/

void	rotate(t_c3d *c3d);
void	move(t_c3d *c3d);

/*
 * DRAWING
*/

int		background(t_c3d *c3d);
void	minimap(t_c3d *c3d);
void	draw_pixel(t_img *img, int x, int y, t_rgb color);
void	draw_rect_full(t_img *img, t_point a, t_point b, t_rgb color);
void	draw_rect_trans(t_img *img, t_point a, t_point b, t_rgb color);

/*
 * COLOR
*/

int		rgb_to_int(int r, int g, int b);
t_rgb	int_to_rgb(int color);
t_rgb	get_pixel_color(t_img *img, int x, int y);
t_rgb	transparency(t_rgb color_one, t_rgb color_two);

/*
 * POINT
*/

t_point	init_point(int x, int y);
t_point	add_two_points(t_point a, t_point b);
t_point	add_point(t_point a, float x, float y);
t_point	abs_point(t_point p);

#endif