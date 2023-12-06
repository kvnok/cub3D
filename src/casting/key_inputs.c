/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_inputs.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ovan-rhe <ovan-rhe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 16:13:46 by ovan-rhe      #+#    #+#                 */
/*   Updated: 2023/12/06 16:13:46 by ovan-rhe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define FORWARD 1
#define BACK -1
#define LEFT -1
#define RIGHT 1

static bool	hitting_wall(int x, int y)
{
	if (world_map[y][x] != '0')
		return (true);
	return (false);
}

static void	move_forwards_backwards(t_dda *dda, int direction)
{
	t_coors_double	new_pos;

	new_pos.x = dda->player_pos.x + (dda->player_dir.x * MOVESPEED * direction);
	new_pos.y = dda->player_pos.y + (dda->player_dir.y * MOVESPEED * direction);
	if (!hitting_wall(new_pos.x, new_pos.y))
	{
		dda->player_pos.x = new_pos.x;
		dda->player_pos.y = new_pos.y;
	}
}

static void	move_left_right(t_dda *dda, int direction)
{
	t_coors_double	new_pos;

	new_pos.x = dda->player_pos.x - (dda->player_dir.y * MOVESPEED * direction);
	new_pos.y = dda->player_pos.y + (dda->player_dir.x * MOVESPEED * direction);
	if (!hitting_wall(new_pos.x, new_pos.y))
	{
		dda->player_pos.x = new_pos.x;
		dda->player_pos.y = new_pos.y;
	}
}

void	key_input(t_program *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		cleanup(data, EXIT_SUCCESS);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_forwards_backwards(data->dda, FORWARD);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_left_right(data->dda, LEFT);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_forwards_backwards(data->dda, BACK);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_left_right(data->dda, RIGHT);
	// if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	// 	// turn left
	// if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	// 	// move right
}
