/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 14:31:48 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/10/03 00:09:50 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s) + 1;
	while (i > 0)
	{
		i--;
		if (s[i] == (char) c)
			return ((char *)s + i);
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

int main()
{
    // initializing string
    char *str = "tripouille";

    // character to be searched
    char chr = 't';

    // Storing pointer returned by
    char* ptr =ft_strrchr(str, chr + 256);

    // getting the position of the character
    if (ptr) {
        printf("Last occurrence of %c in %s is at index %ld",
               chr, str, ptr - str);
    }
    // condition for character not present
    else {
        printf("%c is not present in %s ", chr, str);
    }
    return 0;
}*/
