/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 09:23:37 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/10/03 00:23:30 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += (nptr[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}

/*#include <stdio.h>
#include <stdlib.h>
int main (int argc, char **argv)
{
	if (argc < 2)
		return (0);
	for (int i = 1; i < argc; i++)
		printf("std: %d, ft: %d\n", atoi(argv[i]), ft_atoi(argv[i]));
	return (0);
}*/
