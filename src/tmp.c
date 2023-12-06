/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ovan-rhe <ovan-rhe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 15:25:05 by ovan-rhe      #+#    #+#                 */
/*   Updated: 2023/12/06 15:25:05 by ovan-rhe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_tmp	*set_tmp_init(void)
{
	t_tmp	*tmp = (t_tmp *)malloc(sizeof(t_tmp));

	tmp->player_dir.x = 0;
	tmp->player_dir.y = -1;
	tmp->player_pos.x = 12;
	tmp->player_pos.y = 12;
	tmp->col_ceiling = 0x000000FF;
	tmp->col_floor = 0x794B26FF;
	tmp->tex_north = mlx_load_png("textures/north.png");
	tmp->tex_east = mlx_load_png("textures/east.png");
	tmp->tex_south = mlx_load_png("textures/south.png");
	tmp->tex_west = mlx_load_png("textures/west.png");
	return (tmp);
}

int	print_error(const char *errorMsg)
{
	printf("%s\n", errorMsg);
	return (1);
}
