/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 11:27:43 by kkroon        #+#    #+#                 */
/*   Updated: 2022/11/02 13:15:25 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy_s1;
	int		i;

	copy_s1 = (char *) malloc((ft_strlen(s1) + 1) * sizeof(char));
	i = 0;
	if (copy_s1 == NULL)
		return (NULL);
	while (s1[i])
	{
		copy_s1[i] = s1[i];
		i++;
	}
	copy_s1[i] = '\0';
	return (copy_s1);
}
