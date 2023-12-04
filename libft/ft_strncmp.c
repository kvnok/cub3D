/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 11:27:57 by kkroon        #+#    #+#                 */
/*   Updated: 2022/11/02 15:59:54 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_compare_length(const char *s1, const char *s2)
{
	if (ft_strlen(s1) > ft_strlen(s2))
		return (ft_strlen(s1));
	return (ft_strlen(s2));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		biggest;

	i = 0;
	biggest = ft_compare_length(s1, s2);
	if (n > biggest)
		n = biggest;
	if ((!ft_strlen(s1) || !ft_strlen(s2)) && !n)
		return (0);
	if (!n)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < (n - 1))
		i++;
	if ((unsigned char)s1[i] > (unsigned char)s2[i])
		return (1);
	else if ((unsigned char)s1[i] < (unsigned char)s2[i])
		return (-1);
	return (0);
}
