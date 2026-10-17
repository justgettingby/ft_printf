/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 11:52:27 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/09/27 15:02:30 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

/*#include <stdio.h>
#include <bsd/string.h>

int main(void)
{
	char	std_dst[50];
	char	ft_dst[50];
	size_t	std_ret;
	size_t	ft_ret;

	// 1. Normal copy 
	std_ret = strlcpy(std_dst, "hello", 10);
	ft_ret = ft_strlcpy(ft_dst, "hello", 10);
	printf("1. Normal copy\n");
	printf("   std: \"%s\" | ret: %zu\n", std_dst, std_ret);
	printf("   ft : \"%s\" | ret: %zu\n\n", ft_dst, ft_ret);

	// 2. Exact size 
	std_ret = strlcpy(std_dst, "hello", 6);
	ft_ret = ft_strlcpy(ft_dst, "hello", 6);
	printf("2. Exact size\n");
	printf("   std: \"%s\" | ret: %zu\n", std_dst, std_ret);
	printf("   ft : \"%s\" | ret: %zu\n\n", ft_dst, ft_ret);

	// 3. Truncation 
	std_ret = strlcpy(std_dst, "hello", 5);
	ft_ret = ft_strlcpy(ft_dst, "hello", 5);
	printf("3. Truncation\n");
	printf("   std: \"%s\" | ret: %zu\n", std_dst, std_ret);
	printf("   ft : \"%s\" | ret: %zu\n\n", ft_dst, ft_ret);

	// 4. Heavy truncation 
	std_ret = strlcpy(std_dst, "hello world", 3);
	ft_ret = ft_strlcpy(ft_dst, "hello world", 3);
	printf("4. Heavy truncation\n");
	printf("   std: \"%s\" | ret: %zu\n", std_dst, std_ret);
	printf("   ft : \"%s\" | ret: %zu\n\n", ft_dst, ft_ret);

	// 5. Size = 1 
	std_ret = strlcpy(std_dst, "hello", 1);
	ft_ret = ft_strlcpy(ft_dst, "hello", 1);
	printf("5. Size = 1\n");
	printf("   std: \"%s\" | ret: %zu\n", std_dst, std_ret);
	printf("   ft : \"%s\" | ret: %zu\n\n", ft_dst, ft_ret);

	// 6. Size = 0 
	memset(std_dst, 'X', sizeof(std_dst));
	memset(ft_dst, 'X', sizeof(ft_dst));
	std_ret = strlcpy(std_dst, "hello", 0);
	ft_ret = ft_strlcpy(ft_dst, "hello", 0);
	printf("6. Size = 0\n");
	printf("   std: first char = '%c' | ret: %zu\n", std_dst[0], std_ret);
	printf("   ft : first char = '%c' | ret: %zu\n\n", ft_dst[0], ft_ret);

	// 7. Empty source 
	std_ret = strlcpy(std_dst, "", 10);
	ft_ret = ft_strlcpy(ft_dst, "", 10);
	printf("7. Empty source\n");
	printf("   std: \"%s\" | ret: %zu\n", std_dst, std_ret);
	printf("   ft : \"%s\" | ret: %zu\n\n", ft_dst, ft_ret);

	// 8. Empty source + size 0 
	memset(std_dst, 'X', sizeof(std_dst));
	memset(ft_dst, 'X', sizeof(ft_dst));
	std_ret = strlcpy(std_dst, "", 0);
	ft_ret = ft_strlcpy(ft_dst, "", 0);
	printf("8. Empty source + size = 0\n");
	printf("   std: first char = '%c' | ret: %zu\n", std_dst[0], std_ret);
	printf("   ft : first char = '%c' | ret: %zu\n\n", ft_dst[0], ft_ret);

	// 9. One character 
	std_ret = strlcpy(std_dst, "a", 2);
	ft_ret = ft_strlcpy(ft_dst, "a", 2);
	printf("9. One character\n");
	printf("   std: \"%s\" | ret: %zu\n", std_dst, std_ret);
	printf("   ft : \"%s\" | ret: %zu\n\n", ft_dst, ft_ret);

	// 10. One character + size 1 
	std_ret = strlcpy(std_dst, "a", 1);
	ft_ret = ft_strlcpy(ft_dst, "a", 1);
	printf("10. One character + size = 1\n");
	printf("   std: \"%s\" | ret: %zu\n", std_dst, std_ret);
	printf("   ft : \"%s\" | ret: %zu\n\n", ft_dst, ft_ret);

	// 11. Source exactly fills size - 1 
	std_ret = strlcpy(std_dst, "123456789", 10);
	ft_ret = ft_strlcpy(ft_dst, "123456789", 10);
	printf("11. Exact fit (size - 1)\n");
	printf("   std: \"%s\" | ret: %zu\n", std_dst, std_ret);
	printf("   ft : \"%s\" | ret: %zu\n\n", ft_dst, ft_ret);

	// 12. Long source
	std_ret = strlcpy(std_dst, "This is a very long string", 5);
	ft_ret = ft_strlcpy(ft_dst, "This is a very long string", 5);
	printf("12. Long source\n");
	printf("   std: \"%s\" | ret: %zu\n", std_dst, std_ret);
	printf("   ft : \"%s\" | ret: %zu\n\n", ft_dst, ft_ret);

	return (0);
}*/
