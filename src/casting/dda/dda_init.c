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
 * @brief The plane vector is set according to the starting direction of the 
 * player.
 * @param dda The dda data.
 */
static void	set_plane(t_dda *dda)
{
	double	xDir;
	double	yDir;

	xDir = dda->player_dir.x;
	yDir = dda->player_dir.y;
	if (xDir == 0 && yDir == -1)
	{
		dda->plane_x = 0.66;
		dda->plane_y = 0;
	}
	else if (xDir == 1 && yDir == 0)
	{
		dda->plane_x = 0;
		dda->plane_y = 0.66;
	}
	else if (xDir == 0 && yDir == 1)
	{
		dda->plane_x = -0.66;
		dda->plane_y = 0;
	}
	else if (xDir == -1 && yDir == 0)
	{
		dda->plane_x = 0;
		dda->plane_y = -0.66;
	}
}

/**
 * Initializes the pre dda struct containing the "constant" values of dda.
 * @param dda The dda data struct.
 * @param input The input values.
 */
void	pre_dda_init(t_dda *dda, t_tmp input)
{
	dda->player_dir.x = input.player_dir.x;
	dda->player_dir.y = input.player_dir.y;
	dda->player_pos.x = input.player_pos.x;
	dda->player_pos.y = input.player_pos.y;
	set_plane(dda);
}

/**
 * @brief Initilizes the dda struct and fills them with the "constant" values.
 * @param input The input values.
 * @return The initialized dda struct or NULL on error.
 */
t_dda	*dda_init(t_tmp *input)
{
	t_dda	*dda;

	dda = (t_dda *)malloc(sizeof(t_dda));
	if (!dda)
	{
		print_error("Error\nmalloc() failure\n");
		return (NULL);
	}
	pre_dda_init(dda, *input);
	return (dda);
}
