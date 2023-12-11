/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   buffer.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ovan-rhe <ovan-rhe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/05 17:59:07 by ovan-rhe      #+#    #+#                 */
/*   Updated: 2023/12/05 17:59:07 by ovan-rhe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief Allocates memory for the buffer.
 * @param data The program data struct.
 */
void	img_buffer_init(t_program *data)
{
	int	y;

	data->img_buffer = (uint32_t **)malloc(sizeof(uint32_t *) * SCR_HEIGHT);
	if (!data->img_buffer)
	{
		print_error("Error\nmalloc() failure\n");
		cleanup(data, EXIT_FAILURE);
	}
	y = 0;
	while (y < SCR_HEIGHT)
	{
		data->img_buffer[y] = (uint32_t *)malloc(sizeof(uint32_t) * SCR_WIDTH);
		if (!data->img_buffer[y])
		{
			print_error("Error\nmalloc() failure\n");
			cleanup(data, EXIT_FAILURE);
		}
		y++;
	}
}

/**
 * @brief Fills the buffer with the right uint32_t values for the floor and 
 * ceiling.
 * @param data The program data struct.
 * @param buff The uint32_t 2D array.
 * @param dda The dda data struct.
 * @param x The current x on the screen to calculate.
 */
static void	fill_floor_ceiling(uint32_t **buff, t_dda *dda, int x)
{
	int	y;

	y = 0;
	while (y < dda->line.start && y < SCR_HEIGHT)
	{
		buff[y][x] = dda->p->ceiling_color;
		y++;
	}
	y = dda->line.end + 1;
	while (y < SCR_HEIGHT)
	{
		buff[y][x] = dda->p->floor_color;
		y++;
	}
}

/**
 * @brief Fills the buffer with the right uint32_t values for the wall.
 * @param buffer The uint32_t 2D array.
 * @param dda The dda data struct.
 * @param x The current x on the screen to calculate.
 */
void	fill_wall(uint32_t **buffer, t_dda *dda, int x)
{
	int	y;

	y = dda->line.start;
	while (y <= dda->line.end)
	{
		if (dda->current_side == X_SIDE)
			buffer[y][x] = COL_WALLX;
		else
			buffer[y][x] = COL_WALLY;
		y++;
	}
}

/**
 * @brief Wrapper function to fill the buffer with the right uint32_t values.
 * @param buffer The uint32_t 2D array.
 * @param dda The dda data struct.
 * @param x The current x on the screen to calculate.
 */
void	fill_buffer(uint32_t **buffer, t_dda *dda, int x)
{
	fill_floor_ceiling(buffer, dda, x);
	// fill_wall(buffer, dda, x);
	textures(buffer, dda, x);
}
