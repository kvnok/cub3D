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

int map_error_check(t_parser *p)
{
	int i;

	i = 0;
	while(p->map[i])
	{
		i++;
	}
	return 0;
}
