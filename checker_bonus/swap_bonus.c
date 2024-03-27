/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:38:42 by wzahir            #+#    #+#             */
/*   Updated: 2024/03/16 18:10:37 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_list	**stack)
{
	t_list	*head;
	t_list	*node;
	int		tmp;

	if (ft_lstsize(*stack) < 2)
		return ;
	head = *stack;
	node = head -> next;
	tmp = head -> content;
	head -> content = node -> content;
	node -> content = tmp;
}

void	sa_bonus(t_list	**stack_a)
{
	swap(stack_a);
}

void	sb_bonus(t_list	**stack_b)
{
	swap(stack_b);
}

void	ss_bonus(t_list	**stack_a, t_list	**stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
