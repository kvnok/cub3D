/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 11:28:08 by kkroon        #+#    #+#                 */
/*   Updated: 2022/11/02 17:26:19 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_loop_front(const char *set, const char *s1, int *i)
{
	int	flag;
	int	set_i;

	(*i) = 0;
	while (s1[*i])
	{
		flag = 0;
		set_i = 0;
		while (set[set_i])
		{
			if (s1[*i] == set[set_i])
			{
				flag = 1;
			}
			set_i++;
		}
		if (flag == 0)
			break ;
		(*i)++;
	}
	return (*i);
}

static int	ft_loop_back(const char *set, const char *s1, int *i)
{
	int	flag;
	int	set_i;

	(*i) = ft_strlen(s1) - 1;
	while (s1[*i])
	{
		flag = 0;
		set_i = 0;
		while (set[set_i])
		{
			if (s1[*i] == set[set_i])
			{
				flag = 1;
			}
			set_i++;
		}
		if (flag == 0)
			break ;
		(*i)--;
	}
	return (*i);
}

static char	*ft_cpy_and_increment(int f, int b, char *trim, char const *s1)
{
	int	i;

	i = 0;
	while (f <= b)
	{
		trim[i] = s1[f];
		i++;
		f++;
	}
	trim[i] = '\0';
	return (trim);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	int		i;
	int		front;
	int		back;

	if (s1[0] == '\0')
		return (ft_strdup(""));
	if (set[0] == '\0')
		return (ft_strdup(s1));
	back = 0;
	front = ft_loop_front(set, s1, &i);
	back = ft_loop_back(set, s1, &i);
	if (front == (int)ft_strlen(s1))
		return (ft_strdup(""));
	trimmed_str = (char *) malloc((back - front + 2) * sizeof(char));
	if (trimmed_str == NULL)
		return (NULL);
	return (ft_cpy_and_increment(front, back, trimmed_str, s1));
}
