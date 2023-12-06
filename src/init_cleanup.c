/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_cleanup.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ovan-rhe <ovan-rhe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 14:23:34 by ovan-rhe      #+#    #+#                 */
/*   Updated: 2023/12/06 14:23:34 by ovan-rhe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_program	*data_init(void)
{
	t_program	*data;

	data = (t_program *)malloc(sizeof(data));
	if (!data)
	{
		print_error("Error\nmalloc() failure\n");
		return (NULL);
	}
	data->mlx = mlx_init(SCR_WIDTH, SCR_HEIGHT, "cub3d", true);
	if (!data->mlx)
	{
		print_error("Error\nmlx_init() failure\n");
		free(data);
		return (NULL);
	}
	img_buffer_init(data);
	data->dda = NULL;
	data->input = NULL;
	return (data);
}

void	cleanup(t_program *data, int exitCode)
{
	int	y;

	y = 0;
	while (data->img_buffer && y < SCR_HEIGHT)
	{
		free(data->img_buffer[y]);
		y++;
	}
	free(data->img_buffer);
	free(data->dda);
	free(data->input);
	if (data->mlx)
	{
		// mlx_close_window(data->mlx);
		// mlx_terminate(data->mlx);
	}
	free(data);
	exit(exitCode);
}
