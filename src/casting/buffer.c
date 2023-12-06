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

static void	fill_floor_ceiling(t_tmp *data, uint32_t **buff, t_dda *dda, int x)
{
	int	y;

	y = 0;
	while (y < dda->draw_info.draw_start && y < SCR_HEIGHT)
	{
		buff[y][x] = data->col_ceiling;
		y++;
	}
	y = dda->draw_info.draw_end + 1;
	while (y < SCR_HEIGHT)
	{
		buff[y][x] = data->col_floor;
		y++;
	}
}

static void	fill_wall(uint32_t **buffer, t_dda *dda, int x)
{
	int	y;

	y = dda->draw_info.draw_start;
	while (y <= dda->draw_info.draw_end)
	{
		if (dda->current_side == X_SIDE)
			buffer[y][x] = COL_WALLX;
		else
			buffer[y][x] = COL_WALLY;
		y++;
	}
}

void	fill_buffer(t_tmp *input, uint32_t **buffer, t_dda *dda, int x)
{
	fill_floor_ceiling(input, buffer, dda, x);
	fill_wall(buffer, dda, x);
}