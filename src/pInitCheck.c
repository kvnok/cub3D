/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pInitCheck.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 16:59:25 by kkroon        #+#    #+#                 */
/*   Updated: 2023/12/06 16:59:25 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

// count elements
int	loop_through_elements(char *str, int *element_count)
{
	int	i;

	i = 1;
	if (ft_isalpha(str[0]) == 1)
		(*element_count)++;
	while (str[i])
	{
		if (str[i - 1] == '\n' && str[i] != '\n'
			&& ft_isalpha(str[i]) == false)
			break ;
		if (str[i - 1] == '\n' && ft_isalpha(str[i]) == true)
			(*element_count)++;
		if (*element_count == 6)
		{
			while (str[i] && str[i] != '\n')
				i++;
			break ;
		}
		i++;
	}
	return (i);
}

/*
looping through the first part
incrementing
*/
int	check_element_count_and_newlines(char *s)
{
	int	element_count;
	int	i;

	element_count = 0;
	i = loop_through_elements(s, &element_count);
	if (element_count != 6)
		return (parser_error("Does not have 6 elements\n"));
	while (s[i] && s[i] == '\n')
		i++;
	while (s[i])
	{
		if (s[i - 1] == '\n' && s[i] == '\n')
			return (parser_error("map contains extra newline\n"));
		if (s[i] == '\n' && !(s[i - 1] == '1' || s[i - 1] == '0'))
			return (parser_error("invalid map line\n"));
		i++;
	}
	return (0);
}

bool	is_file_name_correct(char *fileName)
{
	int	len;

	len = int_strlen(fileName);
	if (len <= 4 || fileName[len - 5] == '/')
		return (false);
	if (fileName[len - 4] == '.' && fileName[len - 3] == 'c'
		&& fileName[len - 2] == 'u' && fileName[len - 1] == 'b')
		return (true);
	return (false);
}

bool	is_tab_inside(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\t')
			return (true);
		i++;
	}
	return (false);
}
