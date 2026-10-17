/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 14:07:48 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/09/27 16:57:37 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != (char) c)
		i++;
	if ((char) c != s[i])
		return (NULL);
	return ((char *) s + i);
}

/*#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "GeeksforGeeks";
	char *us;
	char *ptr = ft_strchr(us, '\0');
    if (ptr != NULL)
        printf("Character found at position: %ld\n", ptr - str);
    else
        printf("Character not found\n");

    return 0;
}*/
