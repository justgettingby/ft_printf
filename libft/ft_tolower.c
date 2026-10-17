/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 13:59:58 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/09/27 16:27:23 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*#include <stdio.h>

int main (void)
{
        for(int i = -300; i <= 300; i++)
        {
                printf("befor: %c after: %c\n", i, ft_tolower(i));
        }
        return (0);
}*/
