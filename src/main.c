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

#include "../include/cub3D.h"

int	main(int argc, char **argv)
{
	t_parser	p;

	if (argc != 2)
		return (parser_error("argc != 2\n"));
	if (parser(argv, &p) == 1)
	{
		free_arr(p.readout);
		return (parser_error("parser() fail\n"));
	}
	free_arr(p.readout);
	return (0);
}
