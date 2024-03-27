/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:18:20 by wzahir            #+#    #+#             */
/*   Updated: 2024/03/16 18:18:04 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*head_a;
	t_list	*head_b;

	if (!*stack_b)
		return ;
	head_a = *stack_a;
	head_b = *stack_b;
	*stack_b = head_b -> next;
	*stack_a = head_b;
	head_b -> next = head_a;
	write(1, "pa\n", 3);
}

void	pb(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*head_a;
	t_list	*head_b;

	if (!*stack_a)
		return ;
	head_a = *stack_a;
	head_b = *stack_b;
	*stack_a = head_a -> next;
	*stack_b = head_a;
	head_a -> next = head_b;
	write(1, "pb\n", 3);
}
