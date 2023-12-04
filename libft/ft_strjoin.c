/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 17:05:53 by kkroon        #+#    #+#                 */
/*   Updated: 2022/11/02 13:15:30 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	size_t		i;
	size_t		s1len;
	size_t		s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	s3 = (char *) malloc((s1len + s2len + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	while (i < s1len + s2len)
	{
		if (i < s1len)
			s3[i] = s1[i];
		if (i >= s1len)
			s3[i] = s2[i - s1len];
		i++;
	}
	s3[i] = '\0';
	return (s3);
}
