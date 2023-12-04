/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 11:25:53 by kkroon        #+#    #+#                 */
/*   Updated: 2022/11/02 16:05:51 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_create_itoa_str(int ncount, int n, char *str)
{
	int	i;

	i = 0;
	while (i < ncount)
	{
		if (str[ncount - i - 1] == '-')
			break ;
		str[ncount - i - 1] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	str[ncount] = '\0';
	return (str);
}

static int	ft_get_ncount(int n, int *ncount)
{
	int	ncpy;

	ncpy = n;
	while (ncpy != 0)
	{
		ncpy = ncpy / 10;
		(*ncount)++;
	}
	if (n <= 0)
		(*ncount)++;
	return (*ncount);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		ncount;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ncount = 0;
	ft_get_ncount(n, &ncount);
	num = (char *)malloc((ncount + 1) * sizeof(char));
	if (num == NULL)
		return (NULL);
	ft_memset(num, '\0', ncount + 1);
	if (n < 0)
	{
		num[0] = '-';
		n = n * -1;
	}
	ft_create_itoa_str(ncount, n, num);
	return (num);
}
