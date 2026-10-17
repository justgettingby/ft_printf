/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 00:00:44 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/10/01 00:20:05 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*void	r(unsigned int i, char *c)
{
	if (i > 0)
		*c = 'r';
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, (s + i));
		i++;
	}
}

/*#include <stdio.h>
int main (void)
{
	char str[] = "1hey!";
	ft_striteri(str, r);
	printf("%s\n", str);
	return (0);
}*/
