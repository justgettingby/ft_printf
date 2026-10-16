/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_signed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 20:32:33 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/10/16 21:32:03 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_signed(int n)
{
	int			len;
	int			ret;
	long long	v;

	len = 0;
	v = n;
	if (v < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len++;
		v = -v;
	}
	ret = ft_putn((unsigned long long)v, 10, "0123456789");
	if (ret == -1)
		return (-1);
	return (len + ret);
}
