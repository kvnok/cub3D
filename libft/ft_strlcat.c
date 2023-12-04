/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 11:22:54 by kkroon        #+#    #+#                 */
/*   Updated: 2022/11/02 16:39:57 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_space;
	size_t	og_srclen;

	dst_space = 0;
	og_srclen = ft_strlen(src);
	while (*dst && dstsize > 0)
	{
		dst_space++;
		dst++;
		dstsize--;
	}
	while (*src && dstsize > 1)
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
	}
	if (*src == 0 || dstsize == 1)
		*dst = '\0';
	return (og_srclen + dst_space);
}
