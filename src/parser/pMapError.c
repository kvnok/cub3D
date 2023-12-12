/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pMapError.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/07 14:27:25 by kkroon        #+#    #+#                 */
/*   Updated: 2023/12/07 14:27:25 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_around(char n, char w, char s, char e)
{
	if (n == ' ' || w == ' ' || s == ' ' || e == ' ')
		return (1);
	return (0);
}

static int	check_nearby(t_parser *p, int mlen, int y, int x)
{
	int	llen;

	llen = int_strlen(p->map[y]);
	if (p->map[y][x] == '0')
	{
		if (y == 0 || y == mlen - 1 || x == 0 || x == llen - 1)
			return (print_error("wrong outside\n"));
		if (int_strlen(p->map[y - 1]) <= x || int_strlen(p->map[y + 1]) <= x)
			return (print_error("doesnt connect\n"));
		if (check_around(p->map[y - 1][x], p->map[y][x - 1], p->map[y + 1][x],
				p->map[y][x + 1]))
			return (print_error("wrong around\n"));
	}
	return (0);
}

int	map_error_check(t_parser *p)
{
	int	y;
	int	x;
	int	map_len;

	map_len = get_length_arr(p->map);
	y = 0;
	while (p->map[y])
	{
		x = 0;
		while (p->map[y][x])
		{
			if (check_nearby(p, map_len, y, x))
				return (print_error("map incorrection\n"));
			x++;
		}
		y++;
	}
	return (0);
}
