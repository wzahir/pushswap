/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:28:54 by wzahir            #+#    #+#             */
/*   Updated: 2024/03/10 13:30:51 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	ra_bonus(t_list	**stack_a)
{
	rotate(stack_a);
}

void	rb_bonus(t_list	**stack_b)
{
	rotate(stack_b);
}

void	rr_bonus(t_list	**stack_a, t_list	**stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
