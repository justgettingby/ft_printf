/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:23:50 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/09/27 13:48:42 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*#include <stdio.h>
#include <string.h>

int main()
{
    char str[50] = "0123456789";
    char str2[50] = "0123456789";
    int n = 0;
    int size = 3;
    bzero(str+n, size);
    ft_bzero(str2+n, size);
    printf("standard: \n");
    for (int i = 0; i < 10; i++)
	if (str[i] != '\0')
		printf("%c", str[i]);
	else
		printf("\\0");
    printf("\nmine: \n");
    for (int i = 0; i < 10; i++)
        if (str2[i] != '\0')
                printf("%c", str2[i]);
        else
                printf("\\0");



    return 0;
}*/
