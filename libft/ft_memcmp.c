/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 16:28:13 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/09/27 17:18:54 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*mem1;
	unsigned char	*mem2;

	mem1 = (unsigned char *) s1;
	mem2 = (unsigned char *) s2;
	i = 0;
	while (i < n && mem1[i] == mem2[i])
		i++;
	if (i == n)
		return (0);
	return (mem1[i] - mem2[i]);
}

/*#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n);

int	main(void)
{
	int	std_ret;
	int	ft_ret;

	// 1. Identical strings
	std_ret = memcmp("hello", "hello", 5);
	ft_ret = ft_memcmp("hello", "hello", 5);
	printf("1. Identical strings\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 2. First string is smaller
	std_ret = memcmp("abc", "abd", 3);
	ft_ret = ft_memcmp("abc", "abd", 3);
	printf("2. First string is smaller\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 3. First string is greater
	std_ret = memcmp("abd", "abc", 3);
	ft_ret = ft_memcmp("abd", "abc", 3);
	printf("3. First string is greater\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 4. Difference in the middle
	std_ret = memcmp("hello", "heLlo", 5);
	ft_ret = ft_memcmp("hello", "heLlo", 5);
	printf("4. Difference in the middle\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 5. n = 0
	std_ret = memcmp("hello", "world", 0);
	ft_ret = ft_memcmp("hello", "world", 0);
	printf("5. n = 0\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 6. Difference outside n
	std_ret = memcmp("hello", "world", 1);
	ft_ret = ft_memcmp("hello", "world", 1);
	printf("6. Only first byte compared\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 7. Difference after first few bytes
	std_ret = memcmp("abcdef", "abcxyz", 3);
	ft_ret = ft_memcmp("abcdef", "abcxyz", 3);
	printf("7. Difference outside comparison range\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 8. Difference inside n
	std_ret = memcmp("abcdef", "abcxyz", 4);
	ft_ret = ft_memcmp("abcdef", "abcxyz", 4);
	printf("8. Difference inside comparison range\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 9. Empty strings
	std_ret = memcmp("", "", 0);
	ft_ret = ft_memcmp("", "", 0);
	printf("9. Empty strings\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 10. One string is a prefix
	std_ret = memcmp("abc", "abcdef", 3);
	ft_ret = ft_memcmp("abc", "abcdef", 3);
	printf("10. Same first n bytes\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 11. Binary data
	{
		unsigned char	a[] = {0x00, 0x01, 0x02, 0xFF};
		unsigned char	b[] = {0x00, 0x01, 0x03, 0xFF};

		std_ret = memcmp(a, b, 4);
		ft_ret = ft_memcmp(a, b, 4);
		printf("11. Binary data\n");
		printf("   std: %d\n", std_ret);
		printf("   ft : %d\n\n", ft_ret);
	}

	// 12. Unsigned byte comparison
	{
		unsigned char	a[] = {0xFF};
		unsigned char	b[] = {0x01};

		std_ret = memcmp(a, b, 1);
		ft_ret = ft_memcmp(a, b, 1);
		printf("12. 0xFF vs 0x01\n");
		printf("   std: %d\n", std_ret);
		printf("   ft : %d\n\n", ft_ret);
	}

	return (0);
}*/
