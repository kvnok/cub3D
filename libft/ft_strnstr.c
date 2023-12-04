/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 11:28:02 by kkroon        #+#    #+#                 */
/*   Updated: 2022/11/02 13:15:43 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	char		*ptr_to_hay;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 0;
	ptr_to_hay = (char *)haystack;
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i + j] && (haystack[i + j] == needle[j]))
				j++;
			if (j == ft_strlen(needle) && (i + j) <= len)
				return (ptr_to_hay);
		}
		ptr_to_hay++;
		i++;
	}
	return (NULL);
}
