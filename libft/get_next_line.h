/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 17:23:48 by kkroon        #+#    #+#                 */
/*   Updated: 2022/12/20 16:46:27 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*strjoin_free(char **s1, char **s2);
char	*save(char **line, char **afternewline);
char	*reading(int fd, char *buffer, char **line, char **afternewline);
int		int_strlen(char *s);
void	*malloc_and_bzero(int count, int size);
char	*cut_free(char **s, int start, int len, char **extra);
int		find_newline(char *s);
char	*cleanup(char **storage, char **leftover);

#endif
