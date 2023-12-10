/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 16:58:27 by kkroon        #+#    #+#                 */
/*   Updated: 2023/12/06 16:58:27 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_program	*data;
	t_parser	p;

	if (argc != 2)
		return (parser_error("argc != 2\n"));
	if (parser(argv, &p))
	{
		free_parser_vars(&p);
		return (parser_error("parser() fail\n"));
	}
	data = data_init();
	if (!data)
		return (EXIT_FAILURE);
	data->dda = dda_init(&p);
	if (!data->dda)
		cleanup(data, EXIT_FAILURE);
	mlx_loop_hook(data->mlx, &dda_loop, (void *)data);
	mlx_loop(data->mlx);
	printf("test yep\n");
	cleanup(data, EXIT_SUCCESS);
}
