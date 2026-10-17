/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 21:29:20 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/10/03 02:21:22 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int		i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/*#include <stdio.h>
int main(void)
{
	int	num = 1;
	int	num2 = 2;
	int	num3 = 3;

	t_list *first = ft_lstnew(&num);
	t_list *second = ft_lstnew(&num2);
	t_list *third = ft_lstnew(&num3);
	first->next = second;
	second->next = third;
	printf("%d\n%d\n", ft_lstsize(first), ft_lstsize(NULL));
	return (0);
}*/
