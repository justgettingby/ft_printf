/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 09:42:23 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/10/03 02:52:28 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0 && size > ((size_t) -1) / nmemb)
		return (NULL);
	if ((nmemb * size) == 0)
		return (malloc(1));
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size);

static int	check_zeroed(void *ptr, size_t bytes)
{
	unsigned char	*p;
	size_t			i;

	if (!ptr)
		return (0);
	p = (unsigned char *)ptr;
	i = 0;
	while (i < bytes)
	{
		if (p[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

static void	test_normal_allocations(void)
{
	void	*std;
	void	*ft;

	printf("\n=== Normal allocations ===\n");

	// 1 byte
	std = calloc(1, 1);
	ft = ft_calloc(1, 1);
	printf("1 x 1:              %s\n",
		(std && ft && check_zeroed(std, 1) && check_zeroed(ft, 1))
		? "OK" : "FAIL");
	free(std);
	free(ft);

	// Array of integers
	std = calloc(10, sizeof(int));
	ft = ft_calloc(10, sizeof(int));
	printf("10 x sizeof(int):   %s\n",
		(std && ft
		&& check_zeroed(std, 10 * sizeof(int))
		&& check_zeroed(ft, 10 * sizeof(int)))
		? "OK" : "FAIL");
	free(std);
	free(ft);

	// Larger allocation
	std = calloc(1000, sizeof(char));
	ft = ft_calloc(1000, sizeof(char));
	printf("1000 x 1:           %s\n",
		(std && ft
		&& check_zeroed(std, 1000)
		&& check_zeroed(ft, 1000))
		? "OK" : "FAIL");
	free(std);
	free(ft);

	// Different element sizes
	std = calloc(42, 42);
	ft = ft_calloc(42, 42);
	printf("42 x 42:            %s\n",
		(std && ft
		&& check_zeroed(std, 42 * 42)
		&& check_zeroed(ft, 42 * 42))
		? "OK" : "FAIL");
	free(std);
	free(ft);
}

static void	test_zero_parameters(void)
{
	void	*std;
	void	*ft;

	printf("\n=== Zero parameters ===\n");

	// nmemb == 0
	std = calloc(0, 10);
	ft = ft_calloc(0, 10);
	printf("0 x 10:             %s\n",
		((std == NULL) == (ft == NULL)) ? "OK" : "DIFFERENT");
	free(std);
	free(ft);

	// size == 0
	std = calloc(10, 0);
	ft = ft_calloc(10, 0);
	printf("10 x 0:             %s\n",
		((std == NULL) == (ft == NULL)) ? "OK" : "DIFFERENT");
	free(std);
	free(ft);

	// Both == 0
	std = calloc(0, 0);
	ft = ft_calloc(0, 0);
	printf("0 x 0:              %s\n",
		((std == NULL) == (ft == NULL)) ? "OK" : "DIFFERENT");
	free(std);
	free(ft);
}

static void	test_overflow(void)
{
	void	*std;
	void	*ft;
	size_t	nmemb;
	size_t	size;

	printf("\n=== Overflow ===\n");

	// This multiplication must overflow size_t.
	nmemb = SIZE_MAX;
	size = 2;

	std = calloc(nmemb, size);
	ft = ft_calloc(nmemb, size);

	printf("SIZE_MAX x 2:       ");

	// The important requirement is that ft_calloc does not actually
	// allocate the wrapped-around amount of memory.
	if (ft == NULL)
		printf("OK (NULL)\n");
	else
	{
		printf("FAIL (returned non-NULL)\n");
		free(ft);
	}

	// Standard calloc is only used as a reference here.
	// Its exact overflow behavior is implementation-dependent.
	free(std);
}

static void	test_zero_initialization(void)
{
	unsigned char	*std;
	unsigned char	*ft;
	size_t			i;
	int				ok_std;
	int				ok_ft;

	printf("\n=== Zero initialization ===\n");

	std = calloc(256, sizeof(unsigned char));
	ft = ft_calloc(256, sizeof(unsigned char));

	ok_std = 1;
	ok_ft = 1;
	i = 0;

	while (i < 256)
	{
		if (std && std[i] != 0)
			ok_std = 0;
		if (ft && ft[i] != 0)
			ok_ft = 0;
		i++;
	}

	printf("Standard calloc:   %s\n", ok_std ? "ZEROED" : "NOT ZEROED");
	printf("ft_calloc:         %s\n", ok_ft ? "ZEROED" : "NOT ZEROED");

	free(std);
	free(ft);
}

static void	test_various_sizes(void)
{
	void	*std;
	void	*ft;
	size_t	tests[][2] = {
		{1, 1},
		{2, 8},
		{5, 16},
		{10, 32},
		{100, 64},
		{1000, 100},
		{4096, 1},
		{1, 4096},
		{128, 128}
	};
	size_t	i;
	size_t	total;
	int		ok;

	printf("\n=== Various sizes ===\n");

	i = 0;
	while (i < sizeof(tests) / sizeof(tests[0]))
	{
		total = tests[i][0] * tests[i][1];
		std = calloc(tests[i][0], tests[i][1]);
		ft = ft_calloc(tests[i][0], tests[i][1]);

		ok = 1;

		if (!std || !ft)
			ok = 0;
		else if (!check_zeroed(std, total) || !check_zeroed(ft, total))
			ok = 0;

		printf("%zu x %zu (%zu bytes): %s\n",
			tests[i][0], tests[i][1], total, ok ? "OK" : "FAIL");

		free(std);
		free(ft);
		i++;
	}
}

static void	test_malloc_failure(void)
{
	void	*ft;

	printf("\n=== malloc failure ===\n");

	// This asks for an impossibly large allocation.
	// It should make ft_calloc return NULL rather than crash.
	ft = calloc(SIZE_MAX, SIZE_MAX);

	if (ft == NULL)
		printf("Huge allocation:   OK (NULL)\n");
	else
	{
		printf("Huge allocation:   FAIL (non-NULL)\n");
		free(ft);
	}
}

int	main(void)
{
	printf("====================================\n");
	printf("        ft_calloc test suite\n");
	printf("====================================\n");

	test_normal_allocations();
	test_zero_parameters();
	test_overflow();
	test_zero_initialization();
	test_various_sizes();
	test_malloc_failure();

	printf("\n====================================\n");
	printf("             Done!\n");
	printf("====================================\n");

	return (0);
}*/
