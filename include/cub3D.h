/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 16:58:01 by kkroon        #+#    #+#                 */
/*   Updated: 2023/12/06 16:58:01 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../MLX42/include/MLX42/MLX42_Int.h"
# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <time.h>
# include <unistd.h>

# define NORTH "NO "
# define SOUTH "SO "
# define EAST "EA "
# define WEST "WE "
# define FLOOR "F "
# define CEILING "C "

# define N_INDEX 0
# define S_INDEX 1
# define E_INDEX 2
# define W_INDEX 3
# define F_INDEX 4
# define C_INDEX 5

typedef struct s_parser	t_parser;

typedef int				(*t_func)(t_parser *, int, char *);

// dictionary
// mostly used for elements
typedef struct s_dict
{
	char				*key;
	bool				flag;
	char				*value;
	t_func				func;
}						t_dict;

typedef struct s_vector
{
	int					x;
	int					y;
}						t_vector;

/*
filename.cub
paths to textures
floor color
ceiling color
map without player (N, W, S, E) in it
original player x and y
player starting direction
*/
typedef struct s_parser
{
	char				*filename;
	char				**readout;

	char				**raw_elements;
	t_dict				dict[6];
	char				*path_north_texture;
	char				*path_south_texture;
	char				*path_east_texture;
	char				*path_west_texture;
	int32_t				floor_color;
	int32_t				ceiling_color;

	char				**map;
	char				**map_cpy;
	t_vector			player_pos;
	char				starting_dir;
}						t_parser;

// parserUtils.c
void					free_arr(char **string_arr);
void					print_arr(char **string_arr);
int						parser_error(char *error_text);
char					**calloc_string_arr(int amount);
int						get_length_arr(char **string_arr);
void					print_dict(t_parser *p);
bool					is_tab_inside(char *s);
int32_t					pixel_select(int32_t r, int32_t g, int32_t b,
							int32_t a);
void					print_extracted_rgba(int32_t val, char *s);

// parser.c
int						parser(char **argv, t_parser *p);

// pInitMain.c
int						parser_init(char **argv, t_parser *p);

// pInitAssign.c
void					parser_set_null(t_parser *p);
void					init_dict(t_parser *p);

// pInitCheck.c
int						loop_through_elements(char *str, int *element_count);
int						check_element_count_and_newlines(char *s);
bool					is_file_name_correct(char *fileName);

// pInitRead.c
int						fill_string_from_file(char **str, int fd);
int						extract_text_from_file(char **str, t_parser *p);

// pElements.c
int						set_dict_color(t_parser *p, int dict_index, char *line);
int						set_dict_path(t_parser *p, int dict_index, char *line);
int						set_element_values(t_parser *p);

// pMap.c
int						get_player_from_map(t_parser *p);

#endif
