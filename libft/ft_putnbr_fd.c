/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 00:47:43 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/10/01 00:57:32 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_long_putnbr_fd(long num, int fd)
{
	char	c;

	if (num == 0)
		return ;
	c = (num % 10) + '0';
	ft_long_putnbr_fd(num / 10, fd);
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num == 0)
	{
		write (fd, "0", 1);
		return ;
	}
	if (num < 0)
	{
		num *= -1;
		write (fd, "-", 1);
	}
	ft_long_putnbr_fd (num, fd);
}

/*#include <limits.h>
int main (void)
{
	ft_putnbr_fd(INT_MAX, 1);
	return (0);
}*/
