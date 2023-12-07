/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ovan-rhe <ovan-rhe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 15:12:02 by ovan-rhe      #+#    #+#                 */
/*   Updated: 2023/12/06 15:12:02 by ovan-rhe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

# include <stdlib.h>
# include <math.h>
# include <stdbool.h>

# define X_SIDE 1
# define Y_SIDE 2

# define MAP_WIDTH 24
# define MAP_HEIGHT 24

# define MOVESPEED 0.15
# define ROTSPEED 0.08

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_coors_double
{
	double	x;
	double	y;
}	t_coors_double;

typedef struct s_coors_int
{
	int	x;
	int	y;
}	t_coors_int;

typedef struct s_draw_info
{
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_draw_info;

typedef struct	s_input_constants
{
	char				*path_north_texture;
	char				*path_south_texture;
	char				*path_east_texture;
	char				*path_west_texture;

	int32_t				floor_color;
	int32_t				ceiling_color;

	char				**map;
}	t_input_constants;

typedef struct s_dda
{
	double				plane_x;
	double				plane_y;
	t_coors_double		player_pos;
	t_vector			player_dir;

	t_input_constants	input;

	double				camera_x;
	t_vector			ray_dir;
	t_coors_int			map_pos;
	double				delta_dist_x;
	double				delta_dist_y;
	int					step_map_x;
	int					step_map_y;
	double				side_dist_x;
	double				side_dist_y;
	int					current_side;
	t_draw_info			draw_info;
}	t_dda;

/* functions ---------------------------------------------------------------- */

void	dda_per_x(t_dda *dda, int x);
void	draw_info_calc(t_dda *dda);
void	dda_loop(void *param);

#endif