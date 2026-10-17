/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 15:28:15 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/10/03 00:21:31 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while (i < n && str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	if (i == n)
		return (0);
	return (str1[i] - str2[i]);
}

/*#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	main(void)
{
	int	std_ret;
	int	ft_ret;

	// 1. Identical strings 
	std_ret = strncmp("hello", "hello", 5);
	ft_ret = ft_strncmp("hello", "hello", 5);
	printf("1. Identical strings\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 2. First string is smaller 
	std_ret = strncmp("hello", "world", 5);
	ft_ret = ft_strncmp("hello", "world", 5);
	printf("2. First string is smaller\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 3. First string is greater 
	std_ret = strncmp("world", "hello", 5);
	ft_ret = ft_strncmp("world", "hello", 5);
	printf("3. First string is greater\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 4. Difference after first character 
	std_ret = strncmp("abc", "axc", 3);
	ft_ret = ft_strncmp("abc", "axc", 3);
	printf("4. Difference after first character\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 5. n = 0 
	std_ret = strncmp("hello", "world", 0);
	ft_ret = ft_strncmp("hello", "world", 0);
	printf("5. n = 0\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 6. n = 1, same first character
	std_ret = strncmp("hello", "hey", 1);
	ft_ret = ft_strncmp("hello", "hey", 1);
	printf("6. n = 1, same first character\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 7. n = 1, different first character 
	std_ret = strncmp("hello", "world", 1);
	ft_ret = ft_strncmp("hello", "world", 1);
	printf("7. n = 1, different first character\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 8. Difference exactly at n 
	std_ret = strncmp("abcde", "abcxy", 3);
	ft_ret = ft_strncmp("abcde", "abcxy", 3);
	printf("8. Difference after n characters\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 9. Difference within n 
	std_ret = strncmp("abcde", "abxyz", 4);
	ft_ret = ft_strncmp("abcde", "abxyz", 4);
	printf("9. Difference within n\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 10. One string is a prefix of the other 
	std_ret = strncmp("abc", "abcdef", 6);
	ft_ret = ft_strncmp("abc", "abcdef", 6);
	printf("10. First string is a prefix\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 11. Reverse prefix comparison 
	std_ret = strncmp("abcdef", "abc", 6);
	ft_ret = ft_strncmp("abcdef", "abc", 6);
	printf("11. Second string is a prefix\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 12. Both empty 
	std_ret = strncmp("", "", 5);
	ft_ret = ft_strncmp("", "", 5);
	printf("12. Both empty\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 13. Empty vs non-empty 
	std_ret = strncmp("", "hello", 5);
	ft_ret = ft_strncmp("", "hello", 5);
	printf("13. Empty vs non-empty\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 14. Non-empty vs empty 
	std_ret = strncmp("hello", "", 5);
	ft_ret = ft_strncmp("hello", "", 5);
	printf("14. Non-empty vs empty\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	// 15. n smaller than actual difference 
	std_ret = strncmp("abcdef", "abcxyz", 2);
	ft_ret = ft_strncmp("abcdef", "abcxyz", 2);
	printf("15. Difference outside comparison range\n");
	printf("   std: %d\n", std_ret);
	printf("   ft : %d\n\n", ft_ret);

	return (0);
}*/
