/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda_calc.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ovan-rhe <ovan-rhe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/05 13:36:45 by ovan-rhe      #+#    #+#                 */
/*   Updated: 2023/12/05 13:36:45 by ovan-rhe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief Sets the correct step and sidedist according to the ray direction.
 * @param dda The dda data struct.
 */
static void	set_step_and_sidedist(t_dda *dda)
{
	if (dda->ray_dir.x < 0)
	{
		dda->step_map_x = -1;
		dda->side_dist_x = \
				(dda->player_pos.x - dda->map_pos.x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_map_x = 1;
		dda->side_dist_x = \
				(dda->map_pos.x + 1 - dda->player_pos.x) * dda->delta_dist_x;
	}
	if (dda->ray_dir.y < 0)
	{
		dda->step_map_y = -1;
		dda->side_dist_y = \
				(dda->player_pos.y - dda->map_pos.y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_map_y = 1;
		dda->side_dist_y = \
				(dda->map_pos.y + 1 - dda->player_pos.y) * dda->delta_dist_y;
	}
}

/**
 * @brief Sends the ray in steps till a wall is hit to determine how far away 
 * it is.
 * @param dda The dda data struct.
 */
static void	loop_till_collision(t_dda *dda)
{
	bool	hit;

	hit = false;
	while (!hit)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_pos.x += dda->step_map_x;
			dda->current_side = X_SIDE;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_pos.y += dda->step_map_y;
			dda->current_side = Y_SIDE;
		}
		if (dda->p->map[dda->map_pos.y][dda->map_pos.x] == '1')
			hit = true;
	}
}

/**
 * @brief Calculates the values for a given x axis on the screen.
 * @param dda The dda data struct.
 * @param x the x value of the screen.
 */
void	dda_per_x(t_dda *dda, int x)
{
	dda->camera_x = 2 * (x / (double)SCR_WIDTH) - 1;
	dda->ray_dir.x = dda->player_dir.x + \
											(dda->plane_x * dda->camera_x);
	dda->ray_dir.y = dda->player_dir.y + \
											(dda->plane_y * dda->camera_x);
	dda->map_pos.x = (int)dda->player_pos.x;
	dda->map_pos.y = (int)dda->player_pos.y;
	if (dda->ray_dir.x == 0)
		dda->delta_dist_x = INT32_MAX;
	else
		dda->delta_dist_x = fabs(1 / dda->ray_dir.x);
	if (dda->ray_dir.y == 0)
		dda->delta_dist_y = INT32_MAX;
	else
		dda->delta_dist_y = fabs(1 / dda->ray_dir.y);
	set_step_and_sidedist(dda);
	loop_till_collision(dda);
}

/**
 * @brief Calculates the location where to put pixels for the wall.
 * @param dda The dda data struct.
 */
void	draw_info_calc(t_dda *dda)
{
	if (dda->current_side == X_SIDE)
		dda->perp_wall_dist = dda->side_dist_x - dda->delta_dist_x;
	else
		dda->perp_wall_dist = dda->side_dist_y - dda->delta_dist_y;
	if (dda->perp_wall_dist < 1.0)
		dda->draw_info.line_h = SCR_HEIGHT;
	else
		dda->draw_info.line_h = (int)((1 / dda->perp_wall_dist) * SCR_HEIGHT);
	dda->draw_info.draw_start = \
						(SCR_HEIGHT / 2) - (dda->draw_info.line_h / 2);
	if (dda->draw_info.draw_start < 0)
		dda->draw_info.draw_start = 0;
	dda->draw_info.draw_end = \
						(SCR_HEIGHT / 2) + (dda->draw_info.line_h / 2);
	if (dda->draw_info.draw_end >= SCR_HEIGHT)
		dda->draw_info.draw_end = SCR_HEIGHT - 1;
}
