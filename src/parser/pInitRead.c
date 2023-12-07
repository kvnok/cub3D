/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pInitRead.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 16:59:32 by kkroon        #+#    #+#                 */
/*   Updated: 2023/12/06 16:59:32 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	fill_string_from_file(char **str, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			if ((*str)[0] == '\0' || int_strlen(*str) == 0)
			{
				free(line);
				return (parser_error("line read fail\n"));
			}
			break ;
		}
		*str = strjoin_free(str, &line);
		if (*str == NULL)
		{
			free(line);
			return (parser_error("strjoin() fail\n"));
		}
		if (line != NULL)
			free(line);
	}
	return (0);
}

int	extract_text_from_file(char **str, t_parser *p)
{
	int	fd;

	fd = open(p->filename, O_RDONLY);
	if (fd < 0)
	{
		return (parser_error("fd < 0\n"));
	}
	if (fill_string_from_file(str, fd))
	{
		close(fd);
		return (parser_error("fill_string_from_file() fail\n"));
	}
	close(fd);
	return (0);
}
