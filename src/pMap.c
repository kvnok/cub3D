/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pMap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 16:59:37 by kkroon        #+#    #+#                 */
/*   Updated: 2023/12/06 16:59:37 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static bool	is_allowed_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	if (c == ' ' || c == '0' || c == '1')
		return (true);
	return (false);
}

static bool	error_check_player(t_parser *p, char c, int y, int x)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (p->player_pos.x != -1)
			return (false);
		p->player_pos.x = x;
		p->player_pos.y = y;
		p->starting_dir = c;
		p->map[y][x] = '0';
	}
	return (true);
}

int	get_player_from_map(t_parser *p)
{
	int		y;
	int		x;

	y = 0;
	while (p->map[y])
	{
		x = 0;
		while (p->map[y][x])
		{
			if (is_allowed_char(p->map[y][x]) == false)
				return (parser_error("char not allowed\n"));
			if (error_check_player(p, p->map[y][x], y, x) == false)
				return (parser_error("incorrect player\n"));
			x++;
		}
		y++;
	}
	if (p->player_pos.x == -1 || p->player_pos.y == -1)
		return (parser_error("player not found in map\n"));
	return (0);
}
