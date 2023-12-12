/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pGetRawData.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/07 15:23:18 by kkroon        #+#    #+#                 */
/*   Updated: 2023/12/07 15:23:18 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	alloc_raw(t_parser *p)
{
	int	arr_len;

	arr_len = get_length_arr(p->readout);
	if (arr_len < ELEMENT_AMOUNT + 3)
		return (print_error("config is too small\n"));
	p->raw_elements = malloc((ELEMENT_AMOUNT + 1) * sizeof(char *));
	if (p->raw_elements == NULL)
		return (print_error("p->raw_elements alloc fail\n"));
	p->raw_elements[ELEMENT_AMOUNT] = NULL;
	p->map = malloc((arr_len - ELEMENT_AMOUNT + 1) * sizeof(char *));
	if (p->map == NULL)
		return (print_error("p->map alloc fail\n"));
	p->map[arr_len - ELEMENT_AMOUNT] = NULL;
	return (0);
}

int	get_raw_elements_and_map(t_parser *p)
{
	int	i;

	i = 0;
	if (alloc_raw(p))
		return (print_error("raw malloc fail\n"));
	while (p->readout[i] != NULL)
	{
		if (i < ELEMENT_AMOUNT)
		{
			p->raw_elements[i] = ft_strdup(p->readout[i]);
			if (p->raw_elements[i] == NULL)
				return (print_error("element malloc fail\n"));
		}
		else
		{
			p->map[i - ELEMENT_AMOUNT] = ft_strdup(p->readout[i]);
			if (p->map[i - ELEMENT_AMOUNT] == NULL)
				return (print_error("element malloc fail\n"));
		}
		i++;
	}
	return (0);
}
