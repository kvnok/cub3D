/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ovan-rhe <ovan-rhe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/05 13:02:30 by ovan-rhe      #+#    #+#                 */
/*   Updated: 2023/12/05 13:02:30 by ovan-rhe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * Initializes the pre dda struct containing the "constant" values of dda.
 * @param dda The dda data struct.
 */
void	pre_dda_values_init(t_dda *dda)
{
	int				i;
	const char		dirs[4] = "NESW";
	const double	values[4][4] = {{0, -1, 0.66, 0}, {1, 0, 0, 0.66}, \
									{0, 1, -0.66, 0}, {-1, 0, 0, -0.66}};

	i = 0;
	while (i < 4)
	{
		if (dirs[i] == dda->p->starting_dir)
		{
			dda->player_dir.x = values[i][0];
			dda->player_dir.y = values[i][1];
			dda->plane_x = values[i][2];
			dda->plane_y = values[i][3];
			break ;
		}
		i++;
	}
}

static int	set_texture_struct(t_dda *dda)
{
	dda->t.n = NULL;
	dda->t.s = NULL;
	dda->t.w = NULL;
	dda->t.e = NULL;
	dda->t.n = mlx_load_png(dda->p->path_north_texture);
	if (!dda->t.n)
		return (1);
	dda->t.s = mlx_load_png(dda->p->path_south_texture);
	if (!dda->t.s)
		return (1);
	dda->t.w = mlx_load_png(dda->p->path_west_texture);
	if (!dda->t.w)
		return (1);
	dda->t.e = mlx_load_png(dda->p->path_east_texture);
	if (!dda->t.e)
		return (1);
	return (0);
}

/**
 * @brief Initilizes the dda struct and fills them with the "constant" values.
 * @param p The parser struct.
 * @return The initialized dda struct or NULL on error.
 */
t_dda	*dda_init(t_parser *p)
{
	t_dda	*dda;

	dda = (t_dda *)malloc(sizeof(t_dda));
	if (!dda)
	{
		print_error("Error\nmalloc() failure\n");
		return (NULL);
	}
	dda->p = NULL;
	dda->p = p;
	dda->player_pos.x = dda->p->player_pos.x + 0.5;
	dda->player_pos.y = dda->p->player_pos.y + 0.5;
	pre_dda_values_init(dda);
	if (set_texture_struct(dda))
	{
		print_error("Error\ntexture fail\n");
		return (NULL);
	}
	return (dda);
}
