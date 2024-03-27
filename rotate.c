/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:19:16 by wzahir            #+#    #+#             */
/*   Updated: 2024/02/16 18:38:11 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list	**stack)
{
	t_list	*head;
	t_list	*node;

	head = *stack;
	node = ft_lstlast(head);
	if (!head || head -> next == NULL)
		return ;
	*stack = head -> next;
	node -> next = head;
	head -> next = NULL;
}

void	ra(t_list	**stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_list	**stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_list	**stack_a, t_list	**stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write (1, "rr\n", 3);
}
