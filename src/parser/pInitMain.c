/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pInitMain.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 16:59:29 by kkroon        #+#    #+#                 */
/*   Updated: 2023/12/06 16:59:29 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	p_init_error_out(char *str, char *message)
{
	free(str);
	return (parser_error(message));
}

int	parser_init(char **argv, t_parser *p)
{
	char	*str;

	parser_set_null(p);
	init_dict(p);
	p->filename = argv[1];
	if (is_file_name_correct(p->filename) == false)
		return (parser_error("is_file_name_correct() false\n"));
	str = ft_calloc(sizeof(char *) + 1, 1);
	if (str == NULL)
		return (parser_error("str ft_calloc() fail\n"));
	if (extract_text_from_file(&str, p))
		return (p_init_error_out(str, "extract_text_from_file() fail\n"));
	if (is_tab_inside(str) == true)
		return (p_init_error_out(str, "tab found, not allowed!\n"));
	if (check_element_count_and_newlines(str))
		return (p_init_error_out(str, "count_elements fail\n"));
	p->readout = ft_split(str, '\n');
	free(str);
	if (p->readout == NULL)
		return (parser_error("p->readout ft_split() fail\n"));
	return (0);
}
