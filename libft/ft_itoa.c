/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 20:26:30 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/09/30 21:35:34 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	absu(long n)
{
	if (n > 0)
		return (n);
	return (n * -1);
}

static int	num_len(long num)
{
	int	i;

	i = 1;
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num >= 10)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	num;
	int		sign;
	char	*ptr;
	int		i;

	sign = 0;
	if (n < 0)
		sign = 1;
	num = absu((long) n);
	ptr = malloc(num_len((long) n) + 1);
	if (!ptr)
		return (NULL);
	ptr[num_len(n)] = '\0';
	i = (num_len(n) - 1);
	while (i >= sign)
	{
		ptr[i] = ((num % 10) + '0');
		num /= 10;
		i--;
	}
	if (sign == 1)
		ptr[i] = '-';
	return (ptr);
}
/*
// ---- paste from here at the bottom of ft_itoa.c ----
// also add these includes at the top of the file if they are missing:
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <limits.h>

static long	g_total = 0;
static long	g_failed = 0;

// compares ft_itoa(n) with the output of printf("%d", n), which is the reference
// verbose == 1 prints one line per call, verbose == 0 prints only failures
static void	check(int n, int verbose)
{
	char	*res;
	char	exp[16];
	int		ok;

	ok = 1;
	g_total++;
	// the longest possible result is "-2147483648": 11 characters + terminator
	snprintf(exp, sizeof(exp), "%d", n);
	res = ft_itoa(n);
	if (res == NULL)
	{
		ok = 0;
		if (g_failed < 20)
			printf("   -> n=%d: got NULL, expected \"%s\"\n", n, exp);
	}
	else
	{
		if (strcmp(res, exp) != 0)
		{
			ok = 0;
			if (g_failed < 20)
				printf("   -> n=%d: expected \"%s\", got \"%s\"\n", n, exp, res);
		}
		// length checked separately from content
		if (strlen(res) != strlen(exp))
		{
			ok = 0;
			if (g_failed < 20)
				printf("   -> n=%d: length expected %zu, got %zu\n",
					n, strlen(exp), strlen(res));
		}
		free(res);
	}
	if (verbose || !ok)
		printf("[%s] ft_itoa(%d)\n", ok ? " OK " : "FAIL", n);
	if (!ok)
		g_failed++;
}

// small deterministic random generator (xorshift32) covering all 32 bits,
// unlike rand() which only guarantees 15 bits
static unsigned int	next_random(unsigned int *state)
{
	*state ^= *state << 13;
	*state ^= *state >> 17;
	*state ^= *state << 5;
	return (*state);
}

int	main(int argc, char **argv)
{
	static const int	edges[] = {0, 1, -1, 2, -2, 9, -9, 10, -10, 11, -11,
		42, -42, 99, -99, 100, -100, 101, -101, 999, -999, 1000, -1000,
		12345, -12345, 65535, 65536, -65536, 2147483646, 2147483647,
		-2147483647, INT_MAX, INT_MIN, INT_MAX - 1, INT_MIN + 1};
	size_t				i;
	long long			p;
	long long			v;
	unsigned int		state;
	int					full;

	full = (argc > 1 && strcmp(argv[1], "full") == 0);
	// 1. hand-picked edge cases, printed one by one
	printf("== edge cases ==\n");
	i = 0;
	while (i < sizeof(edges) / sizeof(edges[0]))
		check(edges[i++], 1);
	// 2. every power of ten, and its neighbours, positive and negative
	// (digit count changes exactly at these boundaries)
	printf("== powers of ten and neighbours ==\n");
	p = 1;
	while (p <= 1000000000LL)
	{
		check((int)p, 1);
		check((int)(p - 1), 1);
		check((int)(p + 1), 1);
		check((int)-p, 1);
		check((int)(-p - 1), 1);
		check((int)(-p + 1), 1);
		p *= 10;
	}
	// 3. every value from -1,000,000 to 1,000,000, failures only
	printf("== sweep -1000000 .. 1000000 ==\n");
	v = -1000000;
	while (v <= 1000000)
		check((int)v++, 0);
	// 4. two million pseudo-random ints over the full range, failures only
	printf("== 2000000 pseudo-random values ==\n");
	state = 2463534242u;
	i = 0;
	while (i++ < 2000000)
		check((int)next_random(&state), 0);
	// 5. optional: the whole domain of int
	if (full)
	{
		printf("== exhaustive: all 4294967296 ints ==\n");
		v = INT_MIN;
		while (v <= INT_MAX)
		{
			check((int)v, 0);
			if ((v & 0x0FFFFFFF) == 0)
				printf("   ... reached %lld\n", v);
			v++;
		}
	}
	printf("\n%ld/%ld checks passed%s\n", g_total - g_failed, g_total,
		full ? " (exhaustive)" : "");
	return (g_failed != 0);
}*/
