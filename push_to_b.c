/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:04:17 by wzahir            #+#    #+#             */
/*   Updated: 2024/03/21 12:04:34 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choice_div(int size)
{
	int	div;

	div = 0;
	if (size <= 10)
		div = 5;
	else if (size <= 100)
		div = 6;
	else
		div = 13;
	return (div);
}

void	a_to_b(t_list	**stack_a, t_list	**stack_b, int	*arr, t_var	var)
{
	while (*stack_a && ft_lstsize(*stack_b) <= (var.end - var.start))
	{
		if ((*stack_a)->content >= arr[var.start]
			&& (*stack_a)->content <= arr[var.end])
		{
			pb(stack_a, stack_b);
			if (ft_lstsize(*stack_b) > 1 && (*stack_b)->content < arr[var.mid])
				rb(stack_b);
		}
		else
			ra(stack_a);
	}
}

void	push_to_b(t_list **stack_a, t_list **stack_b, int *arr, int size)
{
	t_var	var;
	int		div;

	div = choice_div(size);
	var.mid = (size / 2) - 1;
	var.offset = size / div;
	var.start = var.mid - var.offset;
	var.end = var.mid + var.offset;
	while (*stack_a)
	{
		a_to_b(stack_a, stack_b, arr, var);
		var.start = var.start - var.offset;
		if (var.start < 0)
			var.start = 0;
		var.end = var.end + var.offset;
		if (var.end >= size)
			var.end = size - 1;
	}
}
