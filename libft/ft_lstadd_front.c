/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 20:54:59 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/10/02 21:40:35 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = (*lst);
	*lst = new;
}

/*#include <stdio.h>
int main(void)
{
	int value = 90;
	int value2 = 505;
	t_list **list;
	t_list *ex_start = ft_lstnew(&value);
	t_list *new_start = ft_lstnew(&value2);
	list = &ex_start;
	ft_lstadd_front(list, new_start);
	printf("%d ",*((int *)((*list)->content)));
	return (0);
}*/
