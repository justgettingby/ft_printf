/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 20:33:57 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/10/16 20:52:10 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_format(char spec, va_list *ap)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	if (spec == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	if (spec == 'p')
		return (ft_putptr(va_arg(*ap, void *)));
	if (spec == 'd' || spec == 'i')
		return (ft_putnbr_signed(va_arg(*ap, int)));
	if (spec == 'u')
		return (ft_putn(va_arg(*ap, unsigned int), 10, "0123456789"));
	if (spec == 'x')
		return (ft_putn(va_arg(*ap, unsigned int), 16, "0123456789abcdef"));
	if (spec == 'X')
		return (ft_putn(va_arg(*ap, unsigned int), 16, "0123456789ABCDEF"));
	if (spec == '%')
	{
		if (write(1, "%", 1) == -1)
			return (-1);
		return (1);
	}
	return (0);
}
