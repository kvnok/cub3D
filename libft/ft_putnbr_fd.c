/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kkroon <kkroon@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 11:27:27 by kkroon        #+#    #+#                 */
/*   Updated: 2022/11/02 13:15:14 by kkroon        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	long long int	ncpy;

	ncpy = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		ncpy = ncpy * -1;
	}
	if (ncpy > 9)
		ft_putnbr_fd(ncpy / 10, fd);
	c = (ncpy % 10) + '0';
	write(fd, &c, 1);
}
