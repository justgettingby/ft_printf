/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 18:39:50 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/09/30 19:50:35 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	long	j;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	j = ft_strlen(s1) - 1;
	i = 0;
	while (in_set(s1[i], set) && s1[i])
		i++;
	if (i == ft_strlen(s1))
		return (ft_strdup(""));
	while (in_set(s1[j], set) && j >= 0)
		j--;
	ptr = malloc (j - i + 2);
	if (ptr == NULL)
		return (NULL);
	ptr = (char *)ft_memcpy(ptr, s1 + i, j - i + 1);
	ptr[j - i + 1] = '\0';
	return (ptr);
}
/*
// ---- paste from here at the bottom of ft_strtrim.c ----
// also add these three includes at the top of the file if they are missing:
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// remove or comment out this whole test section before submitting

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int	g_total = 0;
static int	g_failed = 0;

// NULL-safe printing helper (printing NULL with %s is undefined behavior)
static const char	*show(const char *s)
{
	if (s == NULL)
		return ("(NULL)");
	return (s);
}

// private duplicate of a string, so the test does not depend on ft_strdup
static char	*t_dup(const char *s)
{
	char	*d;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = strlen(s);
	d = malloc(len + 1);
	if (d != NULL)
		memcpy(d, s, len + 1);
	return (d);
}

// runs ft_strtrim(s1, set) and compares the result with `expected`
// expected == NULL means "ft_strtrim must return NULL"
static void	check(const char *name, const char *s1, const char *set,
				const char *expected)
{
	char	*res;
	char	*copy1;
	char	*copy2;
	int		ok;

	g_total++;
	ok = 1;
	// private copies of the inputs, to detect any modification by ft_strtrim
	copy1 = t_dup(s1);
	copy2 = t_dup(set);
	res = ft_strtrim(s1, set);
	if (expected == NULL)
	{
		if (res != NULL)
		{
			printf("   -> expected NULL but got \"%s\"\n", res);
			ok = 0;
		}
	}
	else if (res == NULL)
	{
		printf("   -> expected \"%s\" but got NULL\n", expected);
		ok = 0;
	}
	else
	{
		// content check
		if (strcmp(res, expected) != 0)
		{
			printf("   -> content: expected \"%s\", got \"%s\"\n",
				expected, res);
			ok = 0;
		}
		// length check, reported separately
		if (strlen(res) != strlen(expected))
		{
			printf("   -> length: expected %zu, got %zu\n",
				strlen(expected), strlen(res));
			ok = 0;
		}
		// the result must always be a new allocation, even if nothing was
		// trimmed, otherwise a later free() by the caller would be wrong
		if (res == s1 || res == set)
		{
printf("   -> result points to one of the inputs (not a new string)\n");
			ok = 0;
		}
	}
	// the inputs must be unchanged after the call
	if ((copy1 != NULL && strcmp(copy1, s1) != 0)
		|| (copy2 != NULL && strcmp(copy2, set) != 0))
	{
		printf("   -> ft_strtrim modified one of its inputs\n");
		ok = 0;
	}
	printf("[%s] %-30s s1=\"%s\" set=\"%s\"\n", ok ? " OK " : "FAIL",
		name, show(s1), show(set));
	if (!ok)
		g_failed++;
	free(res);
	free(copy1);
	free(copy2);
}

int	main(void)
{
	char	*big1;
	char	*bigexp;
	size_t	n;

	// normal cases
	check("both ends", "  hello  ", " ", "hello");
	check("start only", "   hello", " ", "hello");
	check("end only", "hello   ", " ", "hello");
	check("nothing to trim", "hello", " ", "hello");
	check("several set chars", "xyzhixyz", "xyz", "hi");
	check("set order differs", "zyxhizyx", "xyz", "hi");
	check("repeated set chars", "aaabaaa", "aa", "b");
	check("classic libft example", "abcHELLOcba", "abc", "HELLO");
	check("whitespace set", " \t\n hi \n\t ", " \t\n", "hi");

	// set characters inside the string must be kept
	check("set chars in the middle", "  a b  c  ", " ", "a b  c");
	check("only middle occurrence", "hello world", " ", "hello world");
	check("trim stops at first non-set", "aabaa", "a", "b");
	check("different chars each side", "abhelloba", "ab", "hello");

	// everything is trimmed (valid input, result is an empty string, not NULL)
	check("whole string in set", "aaaa", "a", "");
	check("whole string, mixed set", "abababab", "ab", "");
	check("single char in set", "a", "a", "");
	check("only spaces", "     ", " ", "");

	// single character edge cases
	check("single char not in set", "a", "b", "a");
	check("single char, other in set", "b", "ab", "");
	check("one char left in middle", "aba", "a", "b");

	// case sensitivity
	check("case sensitive", "AbA", "a", "AbA");
	check("case sensitive, upper set", "aBa", "a", "B");

	// set chars that do not appear in s1
	check("set absent from string", "hello", "xyz", "hello");
	check("set longer than string", "hi", "abcdefghijk", "");
	check("set longer, no match", "hi", "abcdefgxyz", "hi");

	// empty strings
	check("empty s1", "", "abc", "");
	check("empty set", "  hello  ", "", "  hello  ");
	check("both empty", "", "", "");

	// characters outside the ASCII range (catches signed char problems)
	check("high byte trimmed", "\xff" "a" "\xff", "\xff", "a");
	check("high byte kept", "\xff" "a" "\xff", "a", "\xff" "a" "\xff");

	// set contains special characters
	check("newline and tab", "\n\thi\t\n", "\n\t", "hi");
	check("backslash and quote", "\\\"ok\"\\", "\\\"", "ok");

	// NULL inputs (policy: any NULL returns NULL, same as ft_strjoin)
	check("NULL s1", NULL, " ", NULL);
	check("NULL set", "hello", NULL, NULL);
	check("both NULL", NULL, NULL, NULL);
	check("NULL s1, empty set", NULL, "", NULL);
	check("empty s1, NULL set", "", NULL, NULL);

	// same pointer for both arguments: everything in s1 is in set
	{
		const char	*same = "abc";

		check("same pointer twice", same, same, "");
	}

	// long strings, to catch wrong allocation sizes and slow loops
	n = 50000;
	big1 = malloc(2 * n + 4);
	bigexp = malloc(4);
	if (big1 == NULL || bigexp == NULL)
	{
		printf("test setup: malloc failed, skipping long strings\n");
		free(big1);
		free(bigexp);
	}
	else
	{
		memset(big1, 'x', n);
		memcpy(big1 + n, "mid", 3);
		memset(big1 + n + 3, 'x', n);
		big1[2 * n + 3] = '\0';
		strcpy(bigexp, "mid");
		check("long, trimmed both ends", big1, "x", bigexp);
		check("long, nothing to trim", big1, "y", big1);
		memset(big1, 'x', 2 * n);
		big1[2 * n] = '\0';
		check("long, all trimmed", big1, "x", "");
		free(big1);
		free(bigexp);
	}
	printf("\n%d/%d tests passed\n", g_total - g_failed, g_total);
	return (g_failed != 0);
}*/
