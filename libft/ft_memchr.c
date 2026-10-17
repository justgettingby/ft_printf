/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 16:10:10 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/09/27 17:13:54 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(((unsigned char *)s) + i) == (unsigned char) c)
			return ((void *)(((unsigned char *) s) + i));
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n);

int	main(void)
{
	void	*std_ret;
	void	*ft_ret;

	// 1. Character found at the beginning
	std_ret = memchr("hello", 'h', 5);
	ft_ret = ft_memchr("hello", 'h', 5);
	printf("1. Character at beginning\n");
	printf("   std: %s\n", std_ret ? (char *)std_ret : "NULL");
	printf("   ft : %s\n\n", ft_ret ? (char *)ft_ret : "NULL");

	// 2. Character found in the middle
	std_ret = memchr("hello", 'l', 5);
	ft_ret = ft_memchr("hello", 'l', 5);
	printf("2. Character in middle\n");
	printf("   std: %s\n", std_ret ? (char *)std_ret : "NULL");
	printf("   ft : %s\n\n", ft_ret ? (char *)ft_ret : "NULL");

	// 3. Character found at the end
	std_ret = memchr("hello", 'o', 5);
	ft_ret = ft_memchr("hello", 'o', 5);
	printf("3. Character at end\n");
	printf("   std: %s\n", std_ret ? (char *)std_ret : "NULL");
	printf("   ft : %s\n\n", ft_ret ? (char *)ft_ret : "NULL");

	// 4. Character not found
	std_ret = memchr("hello", 'x', 5);
	ft_ret = ft_memchr("hello", 'x', 5);
	printf("4. Character not found\n");
	printf("   std: %s\n", std_ret ? (char *)std_ret : "NULL");
	printf("   ft : %s\n\n", ft_ret ? (char *)ft_ret : "NULL");

	// 5. n = 0
	std_ret = memchr("hello", 'h', 0);
	ft_ret = ft_memchr("hello", 'h', 0);
	printf("5. n = 0\n");
	printf("   std: %s\n", std_ret ? (char *)std_ret : "NULL");
	printf("   ft : %s\n\n", ft_ret ? (char *)ft_ret : "NULL");

	// 6. n stops before character
	std_ret = memchr("hello", 'o', 4);
	ft_ret = ft_memchr("hello", 'o', 4);
	printf("6. Character outside n\n");
	printf("   std: %s\n", std_ret ? (char *)std_ret : "NULL");
	printf("   ft : %s\n\n", ft_ret ? (char *)ft_ret : "NULL");

	// 7. n includes character
	std_ret = memchr("hello", 'o', 5);
	ft_ret = ft_memchr("hello", 'o', 5);
	printf("7. Character inside n\n");
	printf("   std: %s\n", std_ret ? (char *)std_ret : "NULL");
	printf("   ft : %s\n\n", ft_ret ? (char *)ft_ret : "NULL");

	// 8. Empty string
	std_ret = memchr("", 'a', 1);
	ft_ret = ft_memchr("", 'a', 1);
	printf("8. Empty string\n");
	printf("   std: %s\n", std_ret ? (char *)std_ret : "NULL");
	printf("   ft : %s\n\n", ft_ret ? (char *)ft_ret : "NULL");

	// 9. Searching for null terminator
	std_ret = memchr("hello", '\0', 6);
	ft_ret = ft_memchr("hello", '\0', 6);
	printf("9. Search for '\\0'\n");
	printf("   std: %s\n", std_ret ? "FOUND" : "NULL");
	printf("   ft : %s\n\n", ft_ret ? "FOUND" : "NULL");

	// 10. Null terminator excluded
	std_ret = memchr("hello", '\0', 5);
	ft_ret = ft_memchr("hello", '\0', 5);
	printf("10. '\\0' outside n\n");
	printf("   std: %s\n", std_ret ? "FOUND" : "NULL");
	printf("   ft : %s\n\n", ft_ret ? "FOUND" : "NULL");

	// 11. Character appears multiple times
	std_ret = memchr("banana", 'a', 6);
	ft_ret = ft_memchr("banana", 'a', 6);
	printf("11. Character appears multiple times\n");
	printf("   std: %s\n", std_ret ? (char *)std_ret : "NULL");
	printf("   ft : %s\n\n", ft_ret ? (char *)ft_ret : "NULL");

	// 12. n stops before second occurrence
	std_ret = memchr("banana", 'a', 2);
	ft_ret = ft_memchr("banana", 'a', 2);
	printf("12. Multiple occurrences, limited n\n");
	printf("   std: %s\n", std_ret ? (char *)std_ret : "NULL");
	printf("   ft : %s\n\n", ft_ret ? (char *)ft_ret : "NULL");

	// 13. Search using an int value
	std_ret = memchr("abcdef", 99, 6);
	ft_ret = ft_memchr("abcdef", 99, 6);
	printf("13. Integer character value\n");
	printf("   std: %s\n", std_ret ? (char *)std_ret : "NULL");
	printf("   ft : %s\n\n", ft_ret ? (char *)ft_ret : "NULL");

	// 14. Search for byte value 255
	std_ret = memchr("abcdef", 255, 6);
	ft_ret = ft_memchr("abcdef", 255, 6);
	printf("14. Character value 255\n");
	printf("   std: %s\n", std_ret ? (char *)std_ret : "NULL");
	printf("   ft : %s\n\n", ft_ret ? (char *)ft_ret : "NULL");

	return (0);
}*/
