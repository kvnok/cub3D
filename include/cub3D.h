/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ovan-rhe <ovan-rhe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 15:17:25 by ovan-rhe      #+#    #+#                 */
/*   Updated: 2023/12/06 15:17:25 by ovan-rhe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include "MLX42.h"
# include "dda.h"

# define SCR_WIDTH 1080
# define SCR_HEIGHT 740

# define COL_WALLX 0xFF0000FF
# define COL_WALLY 0xFF0000AA

typedef struct s_tmp
{
	t_vector		player_dir;
	t_coors_double	player_pos;
	uint32_t		col_ceiling;
	uint32_t		col_floor;
}	t_tmp;

typedef struct s_program
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	uint32_t	**img_buffer;
	t_dda		*dda;
	t_tmp		*input;
}	t_program;

/* general--------------------------------------------------------------------*/

t_program	*data_init(void);
void		cleanup(t_program *data, int exitCode);

/* casting--------------------------------------------------------------------*/

t_dda		*dda_init(t_tmp *input);
void		img_buffer_init(t_program *data);
void		fill_buffer(t_tmp *input, uint32_t **buffer, t_dda *dda, int x);
void		key_input(t_program *data);

/* temp-----------------------------------------------------------------------*/

t_tmp		*set_tmp_init(void);
int			print_error(const char *errorMsg);

#endif