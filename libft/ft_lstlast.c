/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralkhrai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 21:58:53 by ralkhrai          #+#    #+#             */
/*   Updated: 2026/10/03 02:40:05 by ralkhrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*#include <stdio.h>
int main(void)
{
	int content = 0;
	int cont_last = 1;	
	t_list	*head = ft_lstnew(&content);
	t_list	*second = ft_lstnew(&content);
	head->next = second;
	t_list	*third = ft_lstnew(&cont_last);
	second->next = third;
	printf("%p\n", ft_lstlast(NULL));
	printf("%d\n", *((int *)(ft_lstlast(head)->content)));
	return (0);
}*/
