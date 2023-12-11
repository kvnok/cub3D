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

/**
 * @brief Initialize the mlx and image struct.
 * @param data The program data struct.
 * @return 0 on success, 1 on failure.
 */
static int	init_img_and_mlx(t_program *data)
{
	data->mlx = mlx_init(SCR_WIDTH, SCR_HEIGHT, "cub3d", true);
	if (!data->mlx)
	{
		print_error("Error\nmlx_init() failure\n");
		return (1);
	}
	data->img = mlx_new_image(data->mlx, SCR_WIDTH, SCR_HEIGHT);
	if (!data->img)
	{
		print_error("Error\nmlx_new_image() failure\n");
		mlx_terminate(data->mlx);
		return (1);
	}
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) == -1)
	{
		print_error("Error\nmlx_image_to_window() failure\n");
		mlx_delete_image(data->mlx, data->img);
		mlx_terminate(data->mlx);
		return (1);
	}
	return (0);
}

/**
 * @brief Initializes the program data struct.
 * @param data The program data struct.
 */
t_program	*data_init(void)
{
	t_program	*data;

	data = (t_program *)malloc(sizeof(data));
	if (!data)
	{
		print_error("Error\nmalloc() failure\n");
		return (NULL);
	}
	if (init_img_and_mlx(data))
		return (NULL);
	img_buffer_init(data);
	data->dda = NULL;
	return (data);
}

/**
 * @brief Frees the parser variables.
 * @param p The parser struct.
 */
void	free_parser_vars(t_parser *p)
{
	if (p->raw_elements != NULL)
		free_arr(p->raw_elements);
	if (p->map != NULL)
		free_arr(p->map);
	if (p->readout != NULL)
		free_arr(p->readout);
}

static void	free_textures(t_dda *dda)
{
	if (dda->t[N_INDEX] != NULL)
		mlx_delete_texture(dda->t[N_INDEX]);
	if (dda->t[S_INDEX] != NULL)
		mlx_delete_texture(dda->t[S_INDEX]);
	if (dda->t[W_INDEX] != NULL)
		mlx_delete_texture(dda->t[W_INDEX]);
	if (dda->t[E_INDEX] != NULL)
		mlx_delete_texture(dda->t[E_INDEX]);
}

/**
 * @brief Cleans up the program data struct and exits the program.
 * @param data The program data struct.
 * @param exit_code The exit code.
 */
void	cleanup(t_program *data, int exit_code)
{
	int	y;

	y = 0;
	free_parser_vars(data->dda->p);
	free_textures(data->dda);
	while (data->img_buffer && y < SCR_HEIGHT)
	{
		free(data->img_buffer[y]);
		y++;
	}
	free(data->img_buffer);
	free(data->dda);
	mlx_delete_image(data->mlx, data->img);
	if (data->mlx)
	{
		mlx_close_window(data->mlx);
		mlx_terminate(data->mlx);
	}
	free(data);
	exit(exit_code);
}
