/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:33:24 by wzahir            #+#    #+#             */
/*   Updated: 2024/03/16 15:26:17 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	rra_bonus(t_list	**stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb_bonus(t_list	**stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr_bonus(t_list	**stack_a, t_list	**stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
