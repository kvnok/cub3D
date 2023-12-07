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
 * @param input The parser struct.
 */
void	pre_dda_values_init(t_dda *dda, t_parser input)
{
	int				i;
	const char		dirs[4] = "NESW";
	const double	values[4][4] = {{0, -1, 0.66, 0}, {1, 0, 0, 0.66}, \
									{0, 1, -0.66, 0}, {-1, 0, 0, -0.66}};

	i = 0;
	while (i < 4)
	{
		if (dirs[i] == input.starting_dir)
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

/**
 * @brief Assigns the values that don't change during the dda process to the
 * dda struct.
 * @param dda The dda data struct;
 * @param input The parser struct.
 */
void	pre_dda_constants_init(t_dda *dda, t_parser input)
{
	dda->input.path_north_texture = input.path_north_texture;
	dda->input.path_east_texture = input.path_east_texture;
	dda->input.path_south_texture = input.path_south_texture;
	dda->input.path_west_texture = input.path_west_texture;
	dda->input.floor_color = input.floor_color;
	dda->input.ceiling_color = input.ceiling_color;
	dda->input.map = input.map;
	dda->player_pos.x = input.player_pos.x + 0.5;
	dda->player_pos.y = input.player_pos.y + 0.5;
}

/**
 * @brief Initilizes the dda struct and fills them with the "constant" values.
 * @param input The parser struct.
 * @return The initialized dda struct or NULL on error.
 */
t_dda	*dda_init(t_parser input)
{
	t_dda	*dda;

	dda = (t_dda *)malloc(sizeof(t_dda));
	if (!dda)
	{
		print_error("Error\nmalloc() failure\n");
		return (NULL);
	}
	pre_dda_values_init(dda, input);
	pre_dda_constants_init(dda, input);
	return (dda);
}
