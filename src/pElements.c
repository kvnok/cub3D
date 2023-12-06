/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pElements.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 16:58:17 by kkroon        #+#    #+#                 */
/*   Updated: 2023/12/06 16:58:17 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	set_dict_path(t_parser *p, int dict_index, char *line)
{
	mlx_texture_t	*test;

	p->dict[dict_index].value = line;
	test = mlx_load_png(line);
	if (test == NULL)
		return (parser_error("incorrect texture path\n"));
	mlx_delete_texture(test);
	return (0);
}

int	select_function(t_parser *p, int dict_index, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	if (p->dict[dict_index].func(p, dict_index, line + i) == 1)
	{
		return (parser_error("Dict Function Pointer fail\n"));
	}
	return (0);
}

int	element_match_found(t_parser *p, int j, int i, bool *flag)
{
	if (p->dict[j].flag == true)
		return (parser_error("duplicate element\n"));
	p->dict[j].flag = true;
	*flag = true;
	if (select_function(p, j, p->readout[i]) == 1)
		return (parser_error("select_function() fail\n"));
	return (0);
}

int	set_element_values(t_parser *p)
{
	int		i;
	int		j;
	bool	flag;

	i = 0;
	j = 0;
	flag = false;
	while (i < 6)
	{
		j = 0;
		flag = false;
		while (j < 6)
		{
			if (strncmp(p->dict[j].key, p->readout[i],
					ft_strlen(p->dict[j].key)) == 0)
				if (element_match_found(p, j, i, &flag))
					return (parser_error("incorrect element"));
			j++;
		}
		if (flag == false)
			return (parser_error("no element match found\n"));
		i++;
	}
	return (0);
}
