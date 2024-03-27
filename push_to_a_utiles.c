/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:58:32 by wzahir            #+#    #+#             */
/*   Updated: 2024/03/09 23:00:41 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_index(t_list	**stack)
{
	int		i;
	t_list	*node;

	i = 0;
	node = *stack;
	while (node)
	{
		node -> index = i;
		node = node -> next;
		i++;
	}
}

int	index_max(t_list *stack, int max)
{
	while (stack)
	{
		if (stack->content == max)
			return (stack->index);
		stack = stack->next;
	}
	return (-1);
}

void	search_index(t_list **stack, int max)
{
	put_index(stack);
	if ((*stack) && index_max(*stack, max) <= (ft_lstsize(*stack) / 2))
		rb(stack);
	else
		rrb(stack);
}

int	search_max(t_list *stack, int max)
{
	while (stack)
	{
		if (stack->content == max)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	push_max(t_list **stack_a, t_list **stack_b, int max)
{
	if ((*stack_b)->content == max)
		pa(stack_a, stack_b);
	else if (ft_lstlast(*stack_b)->content == max)
	{
		rrb(stack_b);
		pa(stack_a, stack_b);
	}
}
