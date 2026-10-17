/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 16:48:58 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/09/28 09:22:59 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		while ((i + j) < len && big[i + j] == little[j] && big[i + j])
			j++;
		if (j == little_len)
			return (((char *) big) + i);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <bsd/string.h>
#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len);

static int	g_tests = 0;
static int	g_failed = 0;

static void	test_case(const char *name, const char *big,
			const char *little, size_t len)
{
	char	*expected;
	char	*actual;

	g_tests++;

	expected = strnstr(big, little, len);
	actual = ft_strnstr(big, little, len);

	if (expected == actual)
	{
		printf("[OK]   %-45s -> same pointer\n", name);
		return;
	}

	if (expected && actual && strcmp(expected, actual) == 0)
	{
		printf("[OK]   %-45s -> \"%s\"\n", name, actual);
		return;
	}

	g_failed++;
	printf("[FAIL] %-45s\n", name);
	printf("       big    = \"%s\"\n", big);
	printf("       little = \"%s\"\n", little);
	printf("       len    = %zu\n", len);
	printf("       std    = %s\n", expected ? expected : "NULL");
	printf("       ft     = %s\n", actual ? actual : "NULL");
}

static void	test_case_binary(const char *name, const char *big,
			const char *little, size_t len)
{
	char	*expected;
	char	*actual;

	g_tests++;

	expected = strnstr(big, little, len);
	actual = ft_strnstr(big, little, len);

	if (expected == actual)
	{
		printf("[OK]   %-45s -> same pointer\n", name);
		return;
	}

	if (expected && actual && strcmp(expected, actual) == 0)
	{
		printf("[OK]   %-45s -> same contents\n", name);
		return;
	}

	g_failed++;
	printf("[FAIL] %-45s\n", name);
	printf("       len    = %zu\n", len);
	printf("       std    = %s\n", expected ? expected : "NULL");
	printf("       ft     = %s\n", actual ? actual : "NULL");
}

int	main(void)
{
	char	big_with_null[] = "hello\0world";
	char	little_with_null[] = "world";
//	char	little_empty[] = "";
//	char	big_empty[] = "";
	char	buffer[1000];

	memset(buffer, 'a', sizeof(buffer) - 1);
	buffer[sizeof(buffer) - 1] = '\0';

	printf("===============================================\n");
	printf("             ft_strnstr TEST SUITE\n");
	printf("===============================================\n\n");

	// Basic tests
	test_case("basic match at beginning",
		"hello world", "hello", 11);

	test_case("basic match in middle",
		"hello world", "world", 11);

	test_case("basic match at end",
		"hello world", "world", 5);

	test_case("basic match one character",
		"hello world", "w", 11);

	test_case("no match",
		"hello world", "xyz", 11);

	test_case("little longer than big",
		"abc", "abcdef", 10);

	test_case("little same length as big",
		"abc", "abc", 3);

	test_case("little one shorter than big",
		"abcd", "abc", 4);

	// Empty strings
	test_case("empty little",
		"hello world", "", 11);

	test_case("empty big and empty little",
		"", "", 0);

	test_case("empty big",
		"", "a", 10);

	test_case("empty little with len zero",
		"hello", "", 0);

	// len == 0
	test_case("len zero",
		"hello", "h", 0);

	test_case("len zero with match at beginning",
		"hello", "hello", 0);

	test_case("len zero with empty little",
		"hello", "", 0);

	test_case("len zero with empty strings",
		"", "", 0);

	// Exact length boundaries
	test_case("match uses exactly len characters",
		"abcdef", "abc", 3);

	test_case("match starts at len boundary",
		"abcdef", "d", 4);

	test_case("match would extend past len",
		"abcdef", "def", 5);

	test_case("match exactly reaches len",
		"abcdef", "def", 6);

	test_case("one character too short",
		"abcdef", "def", 5);

	test_case("little length equals len",
		"abcdef", "abc", 3);

	test_case("little length greater than len",
		"abcdef", "abcd", 3);

	// Different positions
	test_case("match at index 0",
		"abcxxx", "abc", 6);

	test_case("match at index 1",
		"xabcxx", "abc", 6);

	test_case("match at index 2",
		"xxabcx", "abc", 6);

	test_case("match at final possible index",
		"xxxabc", "abc", 6);

	test_case("match just outside search range",
		"xxxabc", "abc", 5);

	// Repeated patterns
	test_case("repeated pattern first occurrence",
		"abcabcabc", "abc", 9);

	test_case("repeated pattern limited before first",
		"abcabcabc", "abc", 2);

	test_case("repeated pattern limited to first",
		"abcabcabc", "abc", 3);

	test_case("repeated pattern reaches second",
		"abcabcabc", "abc", 6);

	test_case("repeated single character",
		"aaaaaaaaaa", "a", 10);

	test_case("repeated single character near end",
		"aaaaaaaaaa", "aa", 10);

	test_case("repeated pattern no complete match",
		"aaaaab", "aaaab", 5);

	// Overlapping matches
	test_case("overlapping pattern",
		"aaaaa", "aaa", 5);

	test_case("overlap starts at second char",
		"baaaa", "aaa", 5);

	test_case("overlap with limited len",
		"aaaaa", "aaa", 4);

	test_case("overlap just too short",
		"aaaaa", "aaaa", 3);

	// Special characters
	test_case("spaces",
		"hello world", " ", 11);

	test_case("multiple spaces",
		"hello   world", "   ", 13);

	test_case("punctuation",
		"hello, world!", ",", 13);

	test_case("punctuation sequence",
		"hello, world!", ", ", 13);

	test_case("numbers",
		"abc123456xyz", "123456", 12);

	test_case("symbols",
		"abc!@#$%^&*()xyz", "@#$", 16);

	test_case("newline",
		"hello\nworld", "\n", 11);

	test_case("tab",
		"hello\tworld", "\t", 11);

	test_case("mixed characters",
		"  abc123!@#XYZ  ", "123!@", 16);

	// Case sensitivity
	test_case("case sensitive mismatch",
		"Hello World", "hello", 11);

	test_case("case sensitive match",
		"Hello World", "World", 11);

	test_case("uppercase vs lowercase",
		"ABCDEF", "abc", 6);

	// Prefix/suffix relationships
	test_case("little is prefix",
		"abcdef", "abc", 6);

	test_case("little is suffix",
		"abcdef", "def", 6);

	test_case("little contains big",
		"abc", "abcdef", 6);

	test_case("big and little identical",
		"same", "same", 4);

	test_case("one char big and little",
		"a", "a", 1);

	test_case("one char mismatch",
		"a", "b", 1);

	// len smaller than big length
	test_case("len cuts off before match",
		"hello world", "world", 5);

	test_case("len cuts off inside match",
		"hello world", "world", 9);

	test_case("len includes start of match",
		"hello world", "world", 7);

	test_case("len includes full match",
		"hello world", "world", 11);

	test_case("len much larger than big",
		"hello", "ell", 100);

	test_case("SIZE_MAX-like huge len",
		"hello", "ell", (size_t)-1);

	// Embedded null byte
	test_case_binary("embedded null: search visible part",
		big_with_null, "hello", sizeof(big_with_null));

	test_case_binary("embedded null: search after null",
		big_with_null, little_with_null, sizeof(big_with_null));

	test_case_binary("embedded null: search null",
		big_with_null, "\0", sizeof(big_with_null));

	test_case_binary("embedded null: empty little",
		big_with_null, "", sizeof(big_with_null));

	test_case_binary("embedded null: len before null",
		big_with_null, "hello", 5);

	test_case_binary("embedded null: len includes null",
		big_with_null, "hello", 6);

	// Search strings containing null
	test_case_binary("little starts with null",
		"abc", "\0", 3);

	test_case_binary("little is null character",
		"abc", "\0x", 3);

	// Long strings
	test_case("long string: beginning",
		buffer, "aaa", sizeof(buffer));

	test_case("long string: near beginning",
		buffer, "aaaaaa", 10);

	test_case("long string: limited",
		buffer, "aaaaaa", 5);

	test_case("long string: impossible pattern",
		buffer, "bbbb", sizeof(buffer));

	test_case("long string: entire buffer",
		buffer, buffer, sizeof(buffer));

	// Patterns that almost match
	test_case("almost match at beginning",
		"abcdef", "abce", 6);

	test_case("almost match in middle",
		"xxabcdefyy", "abcxef", 10);

	test_case("almost match at end",
		"xxabcdef", "abcdeg", 8);

	test_case("first chars match only",
		"abcdef", "abz", 6);

	test_case("last chars match only",
		"abcdef", "zef", 6);

	// Multiple candidate matches where only later one is valid
	test_case("first candidate fails, second succeeds",
		"abxabc", "abc", 6);

	test_case("multiple failed candidates",
		"abxabyabzabc", "abc", 12);

	test_case("candidate starts before len but ends after",
		"xxabcdef", "abcdef", 7);

	test_case("candidate starts before len and fits",
		"xxabcdef", "abcdef", 8);

	// Very small lengths
	test_case("len one matching first char",
		"abc", "a", 1);

	test_case("len one not matching",
		"abc", "b", 1);

	test_case("len two matching second char",
		"abc", "b", 2);

	test_case("len two not enough for two-char pattern",
		"abc", "bc", 2);

	test_case("len three matching two-char pattern",
		"abc", "bc", 3);

	// Different lengths around the exact boundary
	test_case("pattern exactly fits remaining buffer",
		"0123456789", "789", 10);

	test_case("pattern does not fit remaining buffer",
		"0123456789", "789", 9);

	test_case("pattern begins at final index but too long",
		"0123456789", "9", 10);

	// Lots of identical characters
	test_case("many a's pattern aaaa",
		"aaaaaaaaaaaaaaaa", "aaaa", 16);

	test_case("many a's pattern aaaab",
		"aaaaaaaaaaaaaaaa", "aaaab", 16);

	test_case("many a's pattern baaaa",
		"aaaaaaaaaaaaaaaa", "baaaa", 16);

	// Strings containing digits and repeated sections
	test_case("repeated numeric pattern",
		"123123123123", "123", 12);

	test_case("numeric pattern boundary",
		"123123123123", "312", 12);

	test_case("numeric pattern too short",
		"123123123123", "312", 8);

	// Whitespace edge cases
	test_case("only spaces",
		"     ", " ", 5);

	test_case("only tabs",
		"\t\t\t\t", "\t\t", 4);

	test_case("spaces not matching tabs",
		"    ", "\t", 4);

	// Single-character special cases
	test_case("single space",
		" ", " ", 1);

	test_case("single newline",
		"\n", "\n", 1);

	test_case("single tab",
		"\t", "\t", 1);

	test_case("single punctuation",
		"!", "!", 1);

	test_case("single digit",
		"7", "7", 1);

	// Large len should not change normal result
	test_case("large len with beginning match",
		"abcdef", "abc", (size_t)-1);

	test_case("large len with middle match",
		"abcdef", "cd", (size_t)-1);

	test_case("large len with no match",
		"abcdef", "xyz", (size_t)-1);

	printf("\n===============================================\n");
	printf("Tests:  %d\n", g_tests);
	printf("Failed: %d\n", g_failed);
	printf("Passed: %d\n", g_tests - g_failed);
	printf("===============================================\n");

	return (g_failed != 0);
}*/
