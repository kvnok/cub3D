/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/07 15:48:53 by kkroon        #+#    #+#                 */
/*   Updated: 2023/12/07 15:48:53 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "dda.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <time.h>

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

# define ELEMENT_AMOUNT 6

typedef struct s_parser	t_parser;

typedef struct s_vector	t_vector;

typedef int				(*t_func)(t_parser *, int, char *);

typedef struct s_dict
{
	char				*key;
	bool				flag;
	char				*value;
	t_func				func;
}						t_dict;

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
	t_vector			player_pos;
	char				starting_dir;
}						t_parser;

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

// pGetRawData.c
int						get_raw_elements_and_map(t_parser *p);

// pElements.c
int						set_dict_color(t_parser *p, int dict_index, char *line);
int						set_dict_path(t_parser *p, int dict_index, char *line);
int						set_element_values(t_parser *p);

// pMap.c
int						get_player_from_map(t_parser *p);

// pMapError.c
int						map_error_check(t_parser *p);

#endif
