/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ovan-rhe <ovan-rhe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/05 21:44:03 by ovan-rhe      #+#    #+#                 */
/*   Updated: 2023/12/05 21:44:03 by ovan-rhe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(void)
{
	t_program	*data;

	data = data_init();
	if (!data)
		return (EXIT_FAILURE);
// temporary input generator----------------------------------------------------
	data->input = set_tmp_init();///////////////////////////////////////////////
// -----------------------------------------------------------------------------
	data->dda = dda_init(data->input);
	if (!data->dda)
		cleanup(data, EXIT_FAILURE);
	mlx_loop_hook(data->mlx, &dda_loop, (void *)data);
	mlx_loop(data->mlx);
	printf("test yep\n");
	cleanup(data, EXIT_SUCCESS);
}
