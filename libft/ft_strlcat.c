/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 13:19:20 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/09/27 16:18:01 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size && dst[i] != '\0')
		i++;
	if (i == size)
		return (ft_strlen(src) + size);
	while ((i + j) < size - 1 && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	while (src[j] != '\0')
		j++;
	return (i + j);
}

/*#include <stdio.h>
#include <bsd/string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size);

int	main(void)
{
	char	std_dst[50];
	char	ft_dst[50];
	size_t	std_ret;
	size_t	ft_ret;

	// 1. Normal concatenation 
	strcpy(std_dst, "Hello ");
	strcpy(ft_dst, "Hello ");
	std_ret = strlcat(std_dst, "world", 50);
	ft_ret = ft_strlcat(ft_dst, "world", 50);
	printf("1. Normal concatenation\n");
	printf("   std: \"%s\" | ret: %zu\n", std_dst, std_ret);
	printf("   ft : \"%s\" | ret: %zu\n\n", ft_dst, ft_ret);

	// 2. Empty destination 
	strcpy(std_dst, "");
	strcpy(ft_dst, "");
	std_ret = strlcat(std_dst, "hello", 50);
	ft_ret = ft_strlcat(ft_dst, "hello", 50);
	printf("2. Empty destination\n");
	printf("   std: \"%s\" | ret: %zu\n", std_dst, std_ret);
	printf("   ft : \"%s\" | ret: %zu\n\n", ft_dst, ft_ret);

	// 3. Empty source 
	strcpy(std_dst, "hello");
	strcpy(ft_dst, "hello");
	std_ret = strlcat(std_dst, "", 50);
	ft_ret = ft_strlcat(ft_dst, "", 50);
	printf("3. Empty source\n");
	printf("   std: \"%s\" | ret: %zu\n", std_dst, std_ret);
	printf("   ft : \"%s\" | ret: %zu\n\n", ft_dst, ft_ret);

	// 4. Exact fit 
	strcpy(std_dst, "hello");
	strcpy(ft_dst, "hello");
	std_ret = strlcat(std_dst, " world", 12);
	ft_ret = ft_strlcat(ft_dst, " world", 12);
	printf("4. Exact fit\n");
	printf("   std: \"%s\" | ret: %zu\n", std_dst, std_ret);
	printf("   ft : \"%s\" | ret: %zu\n\n", ft_dst, ft_ret);

	// 5. Truncation
	strcpy(std_dst, "hello");
	strcpy(ft_dst, "hello");
	std_ret = strlcat(std_dst, " world", 8);
	ft_ret = ft_strlcat(ft_dst, " world", 8);
	printf("5. Truncation\n");
	printf("   std: \"%s\" | ret: %zu\n", std_dst, std_ret);
	printf("   ft : \"%s\" | ret: %zu\n\n", ft_dst, ft_ret);

	// 6. Heavy truncation 
	strcpy(std_dst, "hello");
	strcpy(ft_dst, "hello");
	std_ret = strlcat(std_dst, " world", 6);
	ft_ret = ft_strlcat(ft_dst, " world", 6);
	printf("6. Heavy truncation\n");
	printf("   std: \"%s\" | ret: %zu\n", std_dst, std_ret);
	printf("   ft : \"%s\" | ret: %zu\n\n", ft_dst, ft_ret);

	// 7. size = 0 
	strcpy(std_dst, "hello");
	strcpy(ft_dst, "hello");
	std_ret = strlcat(std_dst, " world", 0);
	ft_ret = ft_strlcat(ft_dst, " world", 0);
	printf("7. Size = 0\n");
	printf("   std: \"%s\" | ret: %zu\n", std_dst, std_ret);
	printf("   ft : \"%s\" | ret: %zu\n\n", ft_dst, ft_ret);

	// 8. size = 1 
	strcpy(std_dst, "");
	strcpy(ft_dst, "");
	std_ret = strlcat(std_dst, "hello", 1);
	ft_ret = ft_strlcat(ft_dst, "hello", 1);
	printf("8. Size = 1\n");
	printf("   std: \"%s\" | ret: %zu\n", std_dst, std_ret);
	printf("   ft : \"%s\" | ret: %zu\n\n", ft_dst, ft_ret);

	// 9. Destination already full 
	strcpy(std_dst, "123456789");
	strcpy(ft_dst, "123456789");
	std_ret = strlcat(std_dst, "abc", 10);
	ft_ret = ft_strlcat(ft_dst, "abc", 10);
	printf("9. Destination already full\n");
	printf("   std: \"%s\" | ret: %zu\n", std_dst, std_ret);
	printf("   ft : \"%s\" | ret: %zu\n\n", ft_dst, ft_ret);

	// 10. Source is longer than remaining space 
	strcpy(std_dst, "abc");
	strcpy(ft_dst, "abc");
	std_ret = strlcat(std_dst, "123456789", 8);
	ft_ret = ft_strlcat(ft_dst, "123456789", 8);
	printf("10. Source longer than remaining space\n");
	printf("   std: \"%s\" | ret: %zu\n", std_dst, std_ret);
	printf("   ft : \"%s\" | ret: %zu\n\n", ft_dst, ft_ret);

	// 11. Both empty 
	strcpy(std_dst, "");
	strcpy(ft_dst, "");
	std_ret = strlcat(std_dst, "", 10);
	ft_ret = ft_strlcat(ft_dst, "", 10);
	printf("11. Both empty\n");
	printf("   std: \"%s\" | ret: %zu\n", std_dst, std_ret);
	printf("   ft : \"%s\" | ret: %zu\n\n", ft_dst, ft_ret);

	// 12. Destination almost fills buffer 
	strcpy(std_dst, "12345678");
	strcpy(ft_dst, "12345678");
	std_ret = strlcat(std_dst, "XY", 10);
	ft_ret = ft_strlcat(ft_dst, "XY", 10);
	printf("12. Destination almost fills buffer\n");
	printf("   std: \"%s\" | ret: %zu\n", std_dst, std_ret);
	printf("   ft : \"%s\" | ret: %zu\n\n", ft_dst, ft_ret);

	return (0);
}*/
