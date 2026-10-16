/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:34:46 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/10/16 21:17:31 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

int	ft_putn(unsigned long long num, int base, char *base_list);
int	ft_putnbr_signed(int n);
int	ft_putptr(void *ptr);
int	ft_putstr(char *s);
int	ft_format(char spec, va_list *ap);
int	ft_putchar(char c);
int	ft_printf(char *str, ...);

#endif
