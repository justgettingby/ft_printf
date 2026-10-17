/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 15:45:32 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/09/30 15:45:40 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			s_len;
	size_t			i;
	char			*ptr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test(const char *s, unsigned int start, size_t len, const char *expected)
{
    char *result;

    result = ft_substr(s, start, len);

    if (!result)
    {
        printf("❌ NULL returned\n");
        printf("Input    : \"%s\"\n", s);
        printf("start=%u len=%zu\n\n", start, len);
        return;
    }

    if (strcmp(result, expected) == 0)
        printf("✅ PASS ");
    else
        printf("❌ FAIL ");

    printf("s=\"%s\" start=%u len=%zu\n", s, start, len);
    printf("Expected: \"%s\"\n", expected);
    printf("Got     : \"%s\"\n\n", result);

    free(result);
}

int main(void)
{
    printf("===== EMPTY STRING =====\n");
    test("", 0, 0, "");
    test("", 0, 5, "");
    test("", 5, 5, "");

    printf("===== SINGLE CHAR =====\n");
    test("a", 0, 0, "");
    test("a", 0, 1, "a");
    test("a", 0, 5, "a");
    test("a", 1, 1, "");
    test("a", 2, 10, "");

    printf("===== NORMAL CASES =====\n");
    test("hello", 0, 5, "hello");
    test("hello", 0, 3, "hel");
    test("hello", 1, 3, "ell");
    test("hello", 4, 1, "o");

    printf("===== LEN TOO BIG =====\n");
    test("hello", 0, 100, "hello");
    test("hello", 2, 100, "llo");
    test("hello", 4, 100, "o");

    printf("===== START AT END =====\n");
    test("hello", 5, 1, "");
    test("hello", 5, 100, "");

    printf("===== START PAST END =====\n");
    test("hello", 6, 1, "");
    test("hello", 50, 100, "");

    printf("===== LEN ZERO =====\n");
    test("abcdef", 0, 0, "");
    test("abcdef", 3, 0, "");
    test("abcdef", 6, 0, "");

    printf("===== RANDOM =====\n");
    test("abcdef", 2, 3, "cde");
    test("abcdef", 2, 4, "cdef");
    test("abcdef", 3, 2, "de");
    test("42 Amman", 3, 5, "Amman");
    test("rand is cool", 5, 2, "is");
    test("rand is cool", 8, 4, "cool");

    return (0);
}*/
