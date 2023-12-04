/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 11:28:11 by kkroon        #+#    #+#                 */
/*   Updated: 2022/11/02 13:15:52 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_special_cpy(char const *s, int *i, char *newstr)
{
	int	j;

	j = 0;
	while (*i < (int)ft_strlen(s))
	{
		newstr[j] = s[*i];
		(*i)++;
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}

static char	*ft_normal_cpy(char const *s, int *i, char *newstr, size_t len)
{
	int	k;

	k = *i;
	while ((*i < ((int)len + (int)k)) && s[*i])
	{
		newstr[*i - k] = s[*i];
		(*i)++;
	}
	newstr[*i - k] = '\0';
	return (newstr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	int		i;
	int		flag;

	i = start;
	flag = 0;
	if (len > ft_strlen(s))
	{
		newstr = (char *) malloc(ft_strlen(s) * sizeof(char) + 1);
		flag = 1;
	}
	else
		newstr = (char *) malloc(len * sizeof(char) + 1);
	if (s == NULL || newstr == NULL)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
		return (ft_memset(newstr, '\0', 1));
	if (flag == 1)
		return (ft_special_cpy(s, &i, newstr));
	return (ft_normal_cpy(s, &i, newstr, len));
}
