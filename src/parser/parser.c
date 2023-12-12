/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 16:59:16 by kkroon        #+#    #+#                 */
/*   Updated: 2023/12/06 16:59:16 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parser(char **argv, t_parser *p)
{
	if (parser_init(argv, p))
		return (print_error("parser_init() fail\n"));
	if (get_raw_elements_and_map(p))
		return (print_error("get_raw_elements_and_map() fail\n"));
	if (set_element_values(p))
		return (print_error("set_element_values() fail\n"));
	if (get_player_from_map(p))
		return (print_error("get_player_from_map() fail\n"));
	if (map_error_check(p))
		return (print_error("map_error_check() fail\n"));
	return (0);
}

	// print_arr(p->readout);
	// printf("-----------------\n");
	// print_arr(p->raw_elements);
	// printf("-----------------\n");
	// print_arr(p->map);
	// printf("-----------------\n");
	// print_dict(p);
	// print_extracted_rgba(p->floor_color, "F: ");
	// print_extracted_rgba(p->ceiling_color, "C: ");
	// printf("player: (y: %d, x: %d)\n", p->player_pos.y, p->player_pos.x);
