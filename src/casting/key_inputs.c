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

/**
 * @brief Checks if the player is hitting a wall.
 * @param x The x coordinate of the player.
 * @param y The y coordinate of the player.
 * @return true If the player is hitting a wall.
 * @return false If the player is not hitting a wall.
 */
static bool	hitting_wall(t_dda *dda, int x, int y)
{
	if (dda->p->map[y][x] != '0')
		return (true);
	return (false);
}

/**
 * @brief Moves the player forwards or backwards.
 * @param dda The dda data struct.
 * @param dir The direction to move to.
 */
static void	move_forwards_backwards(t_dda *dda, int dir)
{
	double	current_pos_x;
	double	dx;
	double	dy;
	double	spacing;

	current_pos_x = dda->player_pos.x;
	dx = dda->player_dir.x * MOVESPEED * dir;
	if (dx > 0)
		spacing = 0.32;
	else
		spacing = -0.32;
	if (!hitting_wall(dda, dda->player_pos.x + dx + spacing, dda->player_pos.y))
		dda->player_pos.x += dx;
	dy = dda->player_dir.y * MOVESPEED * dir;
	if (dy > 0)
		spacing = 0.32;
	else
		spacing = -0.32;
	if (!hitting_wall(dda, current_pos_x, dda->player_pos.y + dy + spacing))
		dda->player_pos.y += dy;
}

/**
 * @brief Moves the player left or right.
 * @param dda The dda data struct.
 * @param dir The direction to move to.
 */
static void	move_left_right(t_dda *dda, int dir)
{
	double	current_pos_x;
	double	dx;
	double	dy;
	double	spacing;

	current_pos_x = dda->player_pos.x;
	dx = -(dda->player_dir.y * MOVESPEED * dir);
	if (dx > 0)
		spacing = 0.32;
	else
		spacing = -0.32;
	if (!hitting_wall(dda, dda->player_pos.x + dx + spacing, dda->player_pos.y))
		dda->player_pos.x += dx;
	dy = dda->player_dir.x * MOVESPEED * dir;
	if (dy > 0)
		spacing = 0.32;
	else
		spacing = -0.32;
	if (!hitting_wall(dda, current_pos_x, dda->player_pos.y + dy + spacing))
		dda->player_pos.y += dy;
}

/**
 * @brief Turns the player to the left or right.
 * @param dda The dda data struct.
 * @param dir The direction to turn to.
 */
static void	turn_left_right(t_dda *dda, int dir)
{
	t_coors_double	old_dir;
	double			old_plane_x;

	old_dir.x = dda->player_dir.x;
	dda->player_dir.x = dda->player_dir.x * cos(ROTSPEED * dir) - \
										dda->player_dir.y * sin(ROTSPEED * dir);
	dda->player_dir.y = old_dir.x * sin(ROTSPEED * dir) + \
										dda->player_dir.y * cos(ROTSPEED * dir);
	old_plane_x = dda->plane_x;
	dda->plane_x = dda->plane_x * cos(ROTSPEED * dir) - \
											dda->plane_y * sin(ROTSPEED * dir);
	dda->plane_y = old_plane_x * sin(ROTSPEED * dir) + \
											dda->plane_y * cos(ROTSPEED * dir);
}

/**
 * @brief Checks if a key is pressed and executes the right function.
 * @param data The program data struct.
 */
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
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		turn_left_right(data->dda, LEFT);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		turn_left_right(data->dda, RIGHT);
}
