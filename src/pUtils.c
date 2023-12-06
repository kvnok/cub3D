/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pUtils.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 16:59:42 by kkroon        #+#    #+#                 */
/*   Updated: 2023/12/06 16:59:42 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	free_arr(char **string_arr)
{
	int	i;

	i = 0;
	while (string_arr[i] != NULL)
	{
		free(string_arr[i]);
		i++;
	}
	free(string_arr);
}

void	print_arr(char **string_arr)
{
	int	i;

	i = 0;
	while (string_arr[i] != NULL)
	{
		printf("%s\n", string_arr[i]);
		i++;
	}
}

int	parser_error(char *error_text)
{
	printf("Error\n");
	printf("%s", error_text);
	return (1);
}

char	**calloc_string_arr(int amount)
{
	char	**string_arr;
	int		i;

	string_arr = malloc((sizeof(char *) + 1) * amount);
	if (string_arr == NULL)
		return (NULL);
	i = 0;
	while (i <= amount)
	{
		string_arr[i] = NULL;
		i++;
	}
	return (string_arr);
}

int	get_length_arr(char **string_arr)
{
	int	i;

	i = 0;
	while (string_arr[i] != NULL)
	{
		i++;
	}
	return (i);
}
