/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 23:27:54 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/09/30 23:59:52 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	num(unsigned int i, char c)
{
	char chr = '.';
	if (c != '.' && i > 9)
		chr = '0';
	else if (c != '.' && i <= 9)
		chr = i + '0';
	return (chr);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	size_t				len_s;
	char				*ptr;

	if (!s || !f)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s == 0)
		return (ft_strdup(""));
	ptr = malloc(len_s + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*#include <stdio.h>
int main (void)
{
	char *str = ft_strmapi("hey.so.yeah", num);
	printf("%s\n", str);
	free(str);
	return (0);
}*/
