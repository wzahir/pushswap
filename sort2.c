/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:24:05 by wzahir            #+#    #+#             */
/*   Updated: 2024/03/20 14:02:54 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(t_list	*stack)
{
	int		min;
	t_list	*node;

	node = stack;
	if (!stack)
		return (0);
	min = node->content;
	while (node)
	{
		if (node->next != NULL && min > node->next->content)
			min = node -> next -> content;
		node = node -> next;
	}
	return (min);
}

void	ft_utile1(t_list	**stack_a, t_list	**stack_b)
{
	rra(stack_a);
	rra(stack_a);
	pb(stack_a, stack_b);
}

void	sort_4(t_list	**stack_a, t_list	**stack_b)
{
	if ((*stack_a)->content == min(*stack_a))
		pb(stack_a, stack_b);
	else if ((*stack_a)->next->content == min(*stack_a))
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->content == min(*stack_a))
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->next->content == min(*stack_a))
	{
		rra(stack_a);
		if (is_sorted(*stack_a))
			return ;
		pb(stack_a, stack_b);
	}
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_list	**stack_a, t_list	**stack_b)
{
	if ((*stack_a)->content == min(*stack_a))
		pb(stack_a, stack_b);
	else if ((*stack_a)->next->content == min(*stack_a))
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->content == min(*stack_a))
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->next->content == min(*stack_a))
		ft_utile1(stack_a, stack_b);
	else if ((*stack_a)->next->next->next->next->content == min(*stack_a))
	{
		rra(stack_a);
		if (is_sorted(*stack_a))
			return ;
		pb(stack_a, stack_b);
	}
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
