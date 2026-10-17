/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 00:26:19 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/10/05 23:02:26 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	inword;
	int	i;
	int	count;

	count = 0;
	i = 0;
	inword = 0;
	while (s[i])
	{
		if (s[i] != c && inword == 0)
		{
			inword = 1;
			count++;
		}
		if (s[i] == c && inword == 1)
			inword = 0;
		i++;
	}
	return (count);
}

static char	*ft_strdup_uptoc(char const *s, int *i, char c)
{
	int		j;
	char	*newstr;

	j = *i;
	while (s[j] && s[j] != c)
		j++;
	newstr = malloc(sizeof(char) * (j - *i + 1));
	if (!newstr)
		return (NULL);
	j = 0;
	while (s[*i] && s[*i] != c)
	{
		newstr[j] = s[*i];
		(*i)++;
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}

static void	ft_clear(char	***strs, int ptrsc)
{
	int	i;

	i = 0;
	while (i < ptrsc)
	{
		free((*strs)[i]);
		i++;
	}
	free(*strs);
}

static char	**corelogic(char const *s, char c, int words, char ***strs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			(*strs)[j] = ft_strdup_uptoc(s, &i, c);
			if (!(*strs)[j])
			{
				ft_clear(strs, j);
				return (NULL);
			}
			j++;
		}
	}
	(*strs)[words] = NULL;
	return (*strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	if (words > 0)
		strs = malloc(sizeof(char *) * (words + 1));
	else
	{
		strs = malloc(sizeof(char *) * 1);
		if (!strs)
			return (NULL);
		strs[0] = NULL;
		return (strs);
	}
	if (!strs)
		return (NULL);
	return (corelogic(s, c, words, &strs));
}

/*#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	char	**strs = ft_split(argv[1], ' ');
	printf("input: %s\nword count: %d\n", argv[1], count_words(argv[1], ' '));
	if (strs)
		for(int i = 0; strs[i] != NULL; i++)
			printf("%s\n", strs[i]);
	else printf("NULL!!!");
	if (strs) ft_clear(&strs, count_words(argv[1], ' ')+1);
	return (0);
}*/
