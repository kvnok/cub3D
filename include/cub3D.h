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
# include "parser.h"
# include "dda.h"

# define SCR_WIDTH 1600
# define SCR_HEIGHT 1200

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

t_dda		*dda_init(t_parser *p);
void		img_buffer_init(t_program *data);
void		fill_buffer(uint32_t **buffer, t_dda *dda, int x);
void		key_input(t_program *data);

// Utilities
void		free_arr(char **string_arr);
void		print_arr(char **string_arr);
int			parser_error(char *error_text);
int			get_length_arr(char **string_arr);
void		print_dict(t_parser *p);
bool		is_tab_inside(char *s);
int32_t		pixel_select(int32_t r, int32_t g, int32_t b,
				int32_t a);
void		print_extracted_rgba(int32_t val, char *s);
int			p_free_err_print(char *str, char *message);
int			p_free_arr_print(char ***arr, char *message);
int			print_error(const char *errorMsg);

#endif
