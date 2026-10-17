/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 18:55:19 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/10/02 20:53:47 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc (1 * sizeof(*node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	g_fail = 0;

static void	check(int condition, const char *msg)
{
	if (condition)
		printf("[OK]   %s\n", msg);
	else
	{
		printf("[FAIL] %s\n", msg);
		g_fail++;
	}
}

int	main(void)
{
	t_list	*n;
	t_list	*a;
	t_list	*b;
	char	*str;
	int		*num;
	int		local;
	void	*dirty;
	int		i;

	//TEST 1: heap string as content
	printf("\n--- Test 1: string content ---\n");
	str = strdup("hello");
	n = ft_lstnew(str);
	check(n != NULL, "returns non-NULL pointer");
	check(n->content == str, "content holds the SAME address given");
	check(strcmp((char *)n->content, "hello") == 0, "content data intact");
	check(n->next == NULL, "next is NULL");
	free(n->content);
	free(n);

	//TEST 2: NULL as content *
	printf("\n--- Test 2: NULL content ---\n");
	n = ft_lstnew(NULL);
	check(n != NULL, "node still allocated when content is NULL");
	check(n->content == NULL, "content is NULL");
	check(n->next == NULL, "next is NULL");
	free(n);

	//TEST 3: heap int as content
	printf("\n--- Test 3: int content ---\n");
	num = malloc(sizeof(int));
	*num = 42;
	n = ft_lstnew(num);
	check(n != NULL, "returns non-NULL pointer");
	check(*(int *)n->content == 42, "int value readable through content");
	check(n->next == NULL, "next is NULL");
	free(n->content);
	free(n);

	// TEST 4: content must be stored by pointer, not copied 
	printf("\n--- Test 4: no copy of content ---\n");
	local = 7;
	n = ft_lstnew(&local);
	check(n->content == &local, "content == &local (pointer stored as-is)");
	local = 99;
	check(*(int *)n->content == 99, "change to local is visible via content");
	free(n);

	// TEST 5: two nodes are independent allocations 
	printf("\n--- Test 5: independent nodes ---\n");
	a = ft_lstnew("A");
	b = ft_lstnew("B");
	check(a != b, "two calls return different addresses");
	check(a->next == NULL && b->next == NULL, "both next are NULL");
	check(a->content != b->content, "contents are different");
	free(a);
	free(b);

	// TEST 6: next must be set even if malloc returns dirty memory 
	printf("\n--- Test 6: next initialised on dirty memory ---\n");
	dirty = malloc(sizeof(t_list));
	memset(dirty, 0xFF, sizeof(t_list));
	free(dirty);
	n = ft_lstnew(NULL);
	check(n->next == NULL, "next is NULL even after dirty chunk was freed");
	free(n);

	// TEST 7: many allocations, all freed -> leak check 
	printf("\n--- Test 7: 1000 nodes created and freed ---\n");
	for (i = 0; i < 1000; i++)
	{
		n = ft_lstnew(NULL);
		if (!n || n->next != NULL)
		{
			g_fail++;
			break ;
		}
		free(n);
	}
	check(i == 1000, "all 1000 allocations succeeded and next was NULL");

printf("\n%s (%d failure(s))\n", g_fail ? "SOME F" : "ALL PASS", g_fail);
	return (g_fail != 0);
}*/
