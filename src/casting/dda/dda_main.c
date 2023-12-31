/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda_main.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ovan-rhe <ovan-rhe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/04 16:43:51 by ovan-rhe      #+#    #+#                 */
/*   Updated: 2023/12/04 16:43:51 by ovan-rhe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * @brief Loops over all the coordinates putting the correct pixel in the 
 * correct coordinate from the buffer
 * @param img_buffer The buffer containing the 2D uint32_t array
 * @param img The image the uint32_t values should be put on
 */
static void	pixels_to_image(uint32_t **img_buffer, mlx_image_t *img)
{
	int	y;
	int	x;

	y = 0;
	while (y < SCR_HEIGHT)
	{
		x = 0;
		while (x < SCR_WIDTH)
		{
			mlx_put_pixel(img, x, y, img_buffer[y][x]);
			x++;
		}
		y++;
	}
}

/**
 * @brief The main dda loop, calculating the pixel values for every x value.
 * @param param The parameter given to mlx_loop_hook 
 * (should be the program data struct)
 */
void	dda_loop(void *param)
{
	t_program	*data;
	int			x;

	data = (t_program *)param;
	ft_memset(data->img->pixels, 0, SCR_WIDTH * SCR_HEIGHT);
	x = 0;
	while (x < SCR_WIDTH)
	{
		dda_per_x(data->dda, x);
		draw_info_calc(data->dda);
		fill_buffer(data->img_buffer, data->dda, x);
		x++;
	}
	pixels_to_image(data->img_buffer, data->img);
	key_input(data);
}
