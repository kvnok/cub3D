/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pElementsColor.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 17:17:27 by kkroon        #+#    #+#                 */
/*   Updated: 2023/12/06 17:17:27 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	extract_color(char *line, int32_t *val)
{
	char	**colors;
	int32_t	values[3];
	int		i;

	colors = ft_split(line, ',');
	if (colors == NULL)
		return (parser_error("ft_split() fail\n"));
	if (get_length_arr(colors) != 3)
		return (parser_error("incorrect amount values\n"));
	i = 0;
	while (i < 3)
	{
		values[i] = ft_atoi(colors[i]);
		if (values[i] > 255)
			return (parser_error("color value too big\n"));
		i++;
	}
	*val = pixel_select(values[0], values[1], values[2], 255);
	return (0);
}

int	set_dict_color(t_parser *p, int dict_index, char *line)
{
	int	i;
	int	comma_count;

	i = 0;
	comma_count = 0;
	if (strlen(line) > 11)
		return (parser_error("incorrect color length\n"));
	while (line[i])
	{
		if (line[i] != ',' && ft_isdigit(line[i]) == false)
			return (parser_error("incorrect char color\n"));
		if (line[i] == ',')
			comma_count++;
		if (comma_count > 2)
			return (parser_error("too many commas\n"));
		i++;
	}
	if (dict_index == F_INDEX)
		if (extract_color(line, &p->floor_color) == 1)
			return (parser_error("incorrect floor_color\n"));
	if (dict_index == C_INDEX)
		if (extract_color(line, &p->ceiling_color) == 1)
			return (parser_error("incorrect ceiling_color\n"));
	return (0);
}
