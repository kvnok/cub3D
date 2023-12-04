/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 11:26:48 by kkroon        #+#    #+#                 */
/*   Updated: 2022/11/02 13:14:35 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calc_atoi_num(const char *str, int i, int *num)
{
	while (ft_isdigit(str[i]))
	{
		*num = *num * 10;
		*num = *num + str[i] - 48;
		i++;
	}
	return (*num);
}

static int	ft_maybe_is_space(const char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (ft_maybe_is_space(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	ft_calc_atoi_num(str, i, &num);
	num = num * sign;
	return (num);
}
