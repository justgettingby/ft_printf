/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 21:00:05 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/10/16 22:31:42 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_literal(char *str, int *i)
{
	int	len;
	int	j;

	len = 0;
	while (str[*i + len] && str[*i + len] != '%')
		len++;
	j = write(1, str + *i, len);
	*i += len - 1;
	return (j);
}

static int	ft_step(char *str, int *i, va_list *ap)
{
	if (str[*i] != '%')
		return (ft_literal(str, i));
	if (str[*i + 1] == '\0')
		return (-1);
	(*i)++;
	return (ft_format(str[*i], ap));
}

int	ft_printf(char *str, ...)
{
	int		i;
	int		j;
	int		count;
	va_list	ap;

	va_start(ap, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		j = ft_step(str, &i, &ap);
		if (j == -1)
		{
			va_end(ap);
			return (-1);
		}
		count += j;
		i++;
	}
	va_end(ap);
	return (count);
}
