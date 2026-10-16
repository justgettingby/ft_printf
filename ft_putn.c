/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 23:24:44 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/10/16 23:24:50 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putn(unsigned long long num, int base, char *base_list)
{
	char	n[64];
	int		i;

	if (num == 0)
	{
		if (write(1, &base_list[0], 1) == -1)
			return (-1);
		return (1);
	}
	i = 64;
	while (num != 0)
	{
		n[--i] = base_list[num % base];
		num /= base;
	}
	if (write(1, n + i, 64 - i) == -1)
		return (-1);
	return (64 - i);
}
