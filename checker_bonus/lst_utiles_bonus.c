/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utiles_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:51:26 by wzahir            #+#    #+#             */
/*   Updated: 2024/03/10 13:52:37 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!lst || !new)
		return ;
	node = *lst;
	if (*lst)
	{
		while (node -> next != NULL)
			node = node -> next;
		node -> next = new;
	}
	else
		*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int		k;
	t_list	*node;

	node = lst;
	k = 0;
	while (node != NULL)
	{
		k++;
		node = node -> next;
	}
	return (k);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}
