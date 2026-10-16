/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 20:31:52 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/10/16 21:31:46 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putptr(void *ptr)
{
	int	ret;

	if (ptr == NULL)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	ret = ft_putn((uintptr_t)ptr, 16, "0123456789abcdef");
	if (ret == -1)
		return (-1);
	return (2 + ret);
}
