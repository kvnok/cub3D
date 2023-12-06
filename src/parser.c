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

#include "../include/cub3D.h"

/*
raw_elements 0-5
raw_map 6-end

assigning readout[i]
might need to copy it over later
*/
int	get_raw_elements_and_map(t_parser *p)
{
	int	i;
	int	element_amount;
	int	arr_length;

	i = 0;
	element_amount = 6;
	arr_length = get_length_arr(p->readout);
	p->raw_elements = calloc_string_arr(element_amount);
	if (p->raw_elements == NULL)
		return (parser_error("p->raw_elements alloc fail\n"));
	p->raw_map = calloc_string_arr(arr_length - element_amount);
	while (p->readout[i] != NULL)
	{
		if (i < element_amount)
			p->raw_elements[i] = p->readout[i];
		else
			p->raw_map[i - element_amount] = p->readout[i];
		i++;
	}
	return (0);
}

int	parser(char **argv, t_parser *p)
{
	if (parser_init(argv, p) == 1)
		return (parser_error("parser_init() fail\n"));
	if (get_raw_elements_and_map(p) == 1)
		return (parser_error("get_raw_elements_and_map() fail\n"));
	if (set_element_values(p) == 1)
		return (parser_error("set_element_values() fail\n"));
	print_extracted_rgba(p->floor_color, "F: ");
	print_extracted_rgba(p->ceiling_color, "C: ");
	return (0);
}
	// print_arr(p->readout);
	// printf("-----------------\n");
	// print_arr(p->raw_elements);
	// printf("-----------------\n");
	// print_arr(p->raw_map);
	// printf("-----------------\n");
	// print_dict(p);
	// if (getPlayerFromMap())
		// return (0);
