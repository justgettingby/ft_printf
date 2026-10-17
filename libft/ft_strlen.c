/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:45:49 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/09/27 12:33:45 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	int i = 1;
	while (i < argc)
	{
		printf("%s %zu\n", argv[i], ft_strlen(argv[i]));
		i++;
	}
	return (0);
}*/
