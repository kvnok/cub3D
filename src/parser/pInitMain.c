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

int	parser_init(char **argv, t_parser *p)
{
	char	*str;

	parser_set_null(p);
	init_dict(p);
	p->filename = argv[1];
	if (is_file_name_correct(p->filename) == false)
		return (print_error("is_file_name_correct() false\n"));
	str = ft_calloc(sizeof(char *) + 1, 1);
	if (str == NULL)
		return (print_error("str ft_calloc() fail\n"));
	if (extract_text_from_file(&str, p))
		return (p_free_err_print(str, "extract_text_from_file() fail\n"));
	if (is_tab_inside(str) == true)
		return (p_free_err_print(str, "tab found, not allowed!\n"));
	if (check_element_count_and_newlines(str))
		return (p_free_err_print(str, "count_elements fail\n"));
	p->readout = ft_split(str, '\n');
	free(str);
	if (p->readout == NULL)
		return (print_error("p->readout ft_split() fail\n"));
	return (0);
}
