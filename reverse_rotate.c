/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:18:51 by wzahir            #+#    #+#             */
/*   Updated: 2024/03/09 14:16:15 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*node;

	head = *stack;
	if (!head || !head -> next)
		return ;
	while (head -> next -> next)
		head = head -> next;
	node = head -> next;
	head -> next = NULL;
	ft_lstadd_front(stack, node);
}

void	rra(t_list	**stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list	**stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list	**stack_a, t_list	**stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
