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

/*
raw_elements 0-5
map 6-end

assigning readout[i]
might need to copy it over later
*/
int	get_raw_elements_and_map(t_parser *p)
{
	int	i;
	int arr_len;

	i = 0;
	arr_len = get_length_arr(p->readout);
	if (arr_len < ELEMENT_AMOUNT + 3)
		return (parser_error("config is too small\n"));
	p->raw_elements = malloc((ELEMENT_AMOUNT + 1) * sizeof(char *));
	if (p->raw_elements == NULL)
		return (parser_error("p->raw_elements alloc fail\n"));
	p->raw_elements[ELEMENT_AMOUNT] = NULL;
	p->map = malloc((arr_len - ELEMENT_AMOUNT + 1) * sizeof(char *));
	if (p->map == NULL)
		return (parser_error("p->map alloc fail\n"));
	p->map[arr_len - ELEMENT_AMOUNT] = NULL;
	while (p->readout[i] != NULL)
	{
		if (i < ELEMENT_AMOUNT)
		{
			p->raw_elements[i] = ft_strdup(p->readout[i]);
			if (p->raw_elements[i] == NULL)
				return parser_error("element malloc fail\n");
		}
		else
		{
			p->map[i - ELEMENT_AMOUNT] = ft_strdup(p->readout[i]);
			if (p->map[i - ELEMENT_AMOUNT] == NULL)
				return parser_error("element malloc fail\n");
		}
		i++;
	}
	return (0);
}

int	parser(char **argv, t_parser *p)
{
	if (parser_init(argv, p))
		return (parser_error("parser_init() fail\n"));
	if (get_raw_elements_and_map(p))
		return (parser_error("get_raw_elements_and_map() fail\n"));
	if (set_element_values(p))
		return (parser_error("set_element_values() fail\n"));
	if (get_player_from_map(p))
		return (parser_error("get_player_from_map() fail\n"));
	if (map_error_check(p))
		return (parser_error("map_error_check() fail\n"));
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
