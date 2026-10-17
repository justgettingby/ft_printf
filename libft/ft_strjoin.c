/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:20:43 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/09/30 18:38:08 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, ft_strlen(s1));
	ft_memcpy(ptr + ft_strlen(s1), s2, ft_strlen(s2));
	ptr[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (ptr);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

// counters for the final summary
static int	g_total = 0;
static int	g_failed = 0;

// printing a NULL pointer with %s is undefined behavior, so we go through this
static const char	*show(const char *s)
{
	if (s == NULL)
		return ("(NULL)");
	return (s);
}

// runs ft_strjoin(s1, s2) and compares the result with `expected`
// expected == NULL means "ft_strjoin must return NULL"
static void	check(const char *name, const char *s1, const char *s2,
				const char *expected)
{
	char	*res;
	char	*copy1;
	char	*copy2;
	int		ok;

	g_total++;
	ok = 1;
	// keep private copies of the inputs to detect if ft_strjoin modifies them
	copy1 = (s1 != NULL) ? strdup(s1) : NULL;
	copy2 = (s2 != NULL) ? strdup(s2) : NULL;
	res = ft_strjoin(s1, s2);
	if (expected == NULL)
	{
		// a NULL result was required
		if (res != NULL)
		{
			printf("   -> expected NULL but got \"%s\"\n", res);
			ok = 0;
		}
	}
	else if (res == NULL)
	{
		// a string was required but we got NULL
		printf("   -> expected \"%s\" but got NULL\n", expected);
		ok = 0;
	}
	else
	{
		// content check with strcmp
		if (strcmp(res, expected) != 0)
		{
			printf("   -> content: expected \"%s\", got \"%s\"\n",
				expected, res);
			ok = 0;
		}
		// length check, done separately so the report shows which one failed
		if (strlen(res) != strlen(expected))
		{
			printf("   -> length: expected %zu, got %zu\n",
				strlen(expected), strlen(res));
			ok = 0;
		}
		// the result must be a new allocation, not one of the inputs
		if (res == s1 || res == s2)
		{
printf("   -> result points to one of the inputs (not a new string)\n");
			ok = 0;
		}
	}
	// the inputs must be unchanged after the call
	if ((copy1 != NULL && strcmp(copy1, s1) != 0)
		|| (copy2 != NULL && strcmp(copy2, s2) != 0))
	{
		printf("   -> ft_strjoin modified one of its inputs\n");
		ok = 0;
	}
	printf("[%s] %-28s s1=\"%s\" s2=\"%s\"\n", ok ? " OK " : "FAIL",
		name, show(s1), show(s2));
	if (!ok)
		g_failed++;
	free(res);
	free(copy1);
	free(copy2);
}

int	main(void)
{
	char	*big1;
	char	*big2;
	char	*bigexp;
	size_t	n;

	// normal cases
	check("normal", "Hello, ", "world!", "Hello, world!");
	check("single chars", "a", "b", "ab");
	check("spaces only", "   ", "  ", "     ");
	check("special characters", "\t\n", "\\\"", "\t\n\\\"");
	check("different lengths", "a", "bcdefghijklmnop", "abcdefghijklmnop");
	check("same string twice", "abc", "abc", "abcabc");

	// empty strings (valid input, must NOT return NULL)
	check("empty s1", "", "abc", "abc");
	check("empty s2", "abc", "", "abc");
	check("both empty", "", "", "");

	// NULL inputs (decided policy: any NULL returns NULL)
	check("NULL s1", NULL, "abc", NULL);
	check("NULL s2", "abc", NULL, NULL);
	check("both NULL", NULL, NULL, NULL);
	check("NULL s1, empty s2", NULL, "", NULL);
	check("empty s1, NULL s2", "", NULL, NULL);

	// same pointer passed as both arguments
	{
		const char	*same = "xyz";

		check("same pointer twice", same, same, "xyzxyz");
	}

	// long strings, to catch wrong allocation sizes
	n = 100000;
	big1 = malloc(n + 1);
	big2 = malloc(n + 1);
	bigexp = malloc(2 * n + 1);
	if (big1 == NULL || big2 == NULL || bigexp == NULL)
	{
		printf("test setup: malloc failed, skipping long strings\n");
		free(big1);
		free(big2);
		free(bigexp);
	}
	else
	{
		memset(big1, 'a', n);
		big1[n] = '\0';
		memset(big2, 'b', n);
		big2[n] = '\0';
		strcpy(bigexp, big1);
		strcat(bigexp, big2);
		check("long strings (100000 each)", big1, big2, bigexp);
		free(big1);
		free(big2);
		free(bigexp);
	}
	printf("\n%d/%d tests passed\n", g_total - g_failed, g_total);
	return (g_failed != 0);
}*/
