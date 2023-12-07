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
# include "MLX42_Int.h"
# include "libft.h"
# include "dda.h"
# include "parser.h"

# define SCR_WIDTH 1560
# define SCR_HEIGHT SCR_WIDTH * 3 / 4


typedef struct s_program
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	uint32_t	**img_buffer;
	t_dda		*dda;
}	t_program;

/* general--------------------------------------------------------------------*/

t_program	*data_init(void);
void		cleanup(t_program *data, int exitCode);
void		free_parser_vars(t_parser *p);

/* casting--------------------------------------------------------------------*/

t_dda		*dda_init(t_parser input);
void		img_buffer_init(t_program *data);
void		fill_buffer(uint32_t **buffer, t_dda *dda, int x);
void		key_input(t_program *data);

/* temp-----------------------------------------------------------------------*/

int			print_error(const char *errorMsg);

#endif
