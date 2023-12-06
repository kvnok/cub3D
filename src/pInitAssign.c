/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pInitAssign.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 16:59:21 by kkroon        #+#    #+#                 */
/*   Updated: 2023/12/06 16:59:21 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	parser_set_null(t_parser *p)
{
	p->filename = NULL;
	p->path_north_texture = NULL;
	p->path_south_texture = NULL;
	p->path_east_texture = NULL;
	p->path_west_texture = NULL;
	p->floor_color = 0;
	p->ceiling_color = 0;
	p->map = NULL;
	p->starting_dir = 0;
	p->readout = NULL;
	p->raw_elements = NULL;
	p->raw_map = NULL;
}

void	init_dict(t_parser *p)
{
	int	i;

	p->dict[N_INDEX].key = NORTH;
	p->dict[S_INDEX].key = SOUTH;
	p->dict[E_INDEX].key = EAST;
	p->dict[W_INDEX].key = WEST;
	p->dict[F_INDEX].key = FLOOR;
	p->dict[C_INDEX].key = CEILING;
	i = 0;
	while (i < 6)
	{
		p->dict[i].flag = false;
		p->dict[i].value = NULL;
		if (i < 4)
			p->dict[i].func = set_dict_path;
		else
			p->dict[i].func = set_dict_color;
		i++;
	}
}
