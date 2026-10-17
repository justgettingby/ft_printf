/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 14:46:55 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/09/28 17:34:31 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t			len;
	char			*ptr;
	size_t			i;

	i = 0;
	len = ft_strlen(s);
	ptr = malloc(sizeof(unsigned char) * len + 1);
	if (ptr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s);

static void	test_string(const char *str)
{
	char	*std;
	char	*ft;
	int		content_ok;
	int		separate;

	std = strdup(str);
	ft = ft_strdup(str);

	content_ok = (std && ft && strcmp(std, ft) == 0);
	separate = (std && ft && std != ft);

	printf("\"%s\": ", str);

	if (content_ok && separate)
		printf("OK");
	else
	{
		printf("FAIL");
		if (!std || !ft)
			printf(" [NULL]");
		else if (!content_ok)
			printf(" [CONTENT DIFFERENT]");
		else if (!separate)
			printf(" [SAME POINTER]");
	}

	printf("\n");

	free(std);
	free(ft);
}

static void	test_empty_string(void)
{
	char	*std;
	char	*ft;

	printf("\n=== Empty string ===\n");

	std = strdup("");
	ft = ft_strdup("");

	if (std && ft && strcmp(std, ft) == 0 && std != ft)
		printf("Empty string: OK\n");
	else
		printf("Empty string: FAIL\n");

	free(std);
	free(ft);
}

static void	test_independence(void)
{
	char	original[] = "Hello, world!";
	char	*std;
	char	*ft;

	printf("\n=== Independent allocation ===\n");

	std = strdup(original);
	ft = ft_strdup(original);

	if (!std || !ft)
	{
		printf("Allocation: FAIL\n");
		free(std);
		free(ft);
		return;
	}

	// Change the original after duplicating it.
	original[0] = 'X';

	if (strcmp(ft, "Hello, world!") == 0
		&& strcmp(std, "Hello, world!") == 0)
		printf("Original modification: OK\n");
	else
		printf("Original modification: FAIL\n");

	free(std);
	free(ft);
}

static void	test_special_characters(void)
{
	printf("\n=== Special characters ===\n");

	test_string(" ");
	test_string("     ");
	test_string("Hello World!");
	test_string("1234567890");
	test_string("!@#$%^&*()");
	test_string("Hello\\nWorld");
	test_string("\\t\\tHello\\t");
	test_string("a b c d");
}

static void	test_long_string(void)
{
	char	*str;
	char	*std;
	char	*ft;
	size_t	i;
	int		ok;

	printf("\n=== Long string ===\n");

	str = malloc(10001);
	if (!str)
	{
		printf("Could not create test string\n");
		return;
	}

	i = 0;
	while (i < 10000)
	{
		str[i] = 'A' + (i % 26);
		i++;
	}
	str[10000] = '\0';

	std = strdup(str);
	ft = ft_strdup(str);

	ok = 1;

	if (!std || !ft)
		ok = 0;
	else if (strcmp(std, ft) != 0)
		ok = 0;
	else if (std == ft)
		ok = 0;

	printf("10000 character string: %s\n", ok ? "OK" : "FAIL");

	free(str);
	free(std);
	free(ft);
}

static void	test_many_strings(void)
{
	const char	*tests[] = {
		"a",
		"abc",
		"Hello",
		"Hello world",
		"42",
		"42 School",
		"libft",
		"ft_strdup",
		"0123456789",
		"abcdefghijklmnopqrstuvwxyz",
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
		"hello\nworld",
		"hello\tworld",
		"hello\0hidden"
	};
	size_t		i;

	printf("\n=== Various strings ===\n");

	i = 0;
	while (i < sizeof(tests) / sizeof(tests[0]))
	{
		test_string(tests[i]);
		i++;
	}
}

int	main(void)
{
	printf("====================================\n");
	printf("         ft_strdup test suite\n");
	printf("====================================\n");

	printf("\n=== Basic strings ===\n");
	test_string("Hello");
	test_string("Hello, world!");
	test_string("42");
	test_string("42 School");
	test_string("libft");

	test_empty_string();
	test_special_characters();
	test_many_strings();
	test_long_string();
	test_independence();

	printf("\n====================================\n");
	printf("              Done!\n");
	printf("====================================\n");

	return (0);
}*/
