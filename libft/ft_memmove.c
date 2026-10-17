/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 09:28:00 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/10/02 23:38:49 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			i--;
			*(((unsigned char *) dest) + i) = *(((unsigned char *) src) + i);
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			*(((unsigned char *) dest) + i) = *(((unsigned char *) src) + i);
			i++;
		}
	}
	return (dest);
}
/*#include <stdio.h>
#include <string.h>
void *ft_memcpy(void *dest, const void *src, size_t n);
int main()
{
    char str1[100] = "Learningisfun";
    char str2[100] = "Learningisfun";

    printf("Original string (str1) : %s\n", str1);
    printf("Original string (str2) : %s\n", str2);

    // Using memcpy on first copy
   printf("memcpy dest  : %s\n", (char*)ft_memcpy(str1 + 8, str1, 13));

    // Using memmove on second independent copy
    printf("memmove dest : %s\n", (char*)ft_memmove(str2 + 8, str2, 13));

    return 0;
}*/
