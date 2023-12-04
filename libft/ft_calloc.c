/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 11:26:36 by kkroon        #+#    #+#                 */
/*   Updated: 2022/11/02 13:14:43 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = (char *) malloc((size * count) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (size * count));
	return (ptr);
}
