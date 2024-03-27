/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:40:44 by wzahir            #+#    #+#             */
/*   Updated: 2024/03/10 13:41:42 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa_bonus(t_list	**stack_a, t_list	**stack_b)
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
}

void	pb_bonus(t_list	**stack_a, t_list	**stack_b)
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
}
