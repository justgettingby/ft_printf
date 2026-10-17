/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 14:29:19 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/09/23 14:42:15 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	unsigned char	zero;
	unsigned char	nine;

	zero = '0';
	nine = '9';
	return (c >= zero && c <= nine);
}
/*#include <stdio.h>
int main(void)
{
	for (int i = -256; i < 256; i++)
		printf("%d: %d\n", i, ft_isdigit(i));
	return (0);
}*/
