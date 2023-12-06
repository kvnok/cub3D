/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pUtils2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 17:13:27 by kkroon        #+#    #+#                 */
/*   Updated: 2023/12/06 17:13:27 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	print_dict(t_parser *p)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		printf("----------------\n");
		printf("key:|%s|\n", p->dict[i].key);
		printf("flag:%d\n", p->dict[i].flag);
		printf("value:|%s|\n", p->dict[i].value);
		printf("----------------\n");
		i++;
	}
}

int32_t	pixel_select(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	print_extracted_rgba(int32_t val, char *s)
{
	printf("%s", s);
	printf("|%d|", ((val >> 24) & 0xFF));
	printf("%d|", ((val >> 16) & 0xFF));
	printf("%d|", ((val >> 8) & 0xFF));
	printf("%d|\n", ((val >> 0) & 0xFF));
}
