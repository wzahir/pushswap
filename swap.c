/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:19:36 by wzahir            #+#    #+#             */
/*   Updated: 2024/03/20 16:38:30 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list	**stack)
{
	t_list	*head;
	t_list	*node;
	int		tmp;

	head = *stack;
	node = head -> next;
	if (!head || !node)
		return ;
	tmp = head -> content;
	head -> content = node -> content;
	node -> content = tmp;
}

void	sa(t_list	**stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_list	**stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_list	**stack_a, t_list	**stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
