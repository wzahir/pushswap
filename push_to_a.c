/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:11:19 by wzahir            #+#    #+#             */
/*   Updated: 2024/03/21 16:40:42 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **stack_a, int *size, int *k)
{
	rra(stack_a);
	(*k)--;
	(*size)--;
}

void	b_to_a(t_list **stack_a, t_list **stack_b, int *arr, int *size)
{
	push_max(stack_a, stack_b, arr[*size - 1]);
	(*size)--;
	if ((*stack_a)->next && (*stack_a)->content > (*stack_a)->next->content)
	{
		sa(stack_a);
		(*size)--;
	}
}

void	ft_pa(t_list **stack_a, t_list **stack_b, int *k)
{
	pa(stack_a, stack_b);
	ra(stack_a);
	(*k)++;
}

void	push_to_a(t_list **stack_a, t_list **stack_b, int *arr, int size)
{
	int	k;

	k = 0;
	while (*stack_b)
	{
		if (search_max(*stack_b, arr[size - 1]))
		{
			if ((*stack_b)->content == arr[size - 1]
				|| ft_lstlast(*stack_b)->content == arr[size - 1])
				b_to_a(stack_a, stack_b, arr, &size);
			else if ((*stack_b)->content == arr[size - 2])
				pa(stack_a, stack_b);
			else if ((k == 0 || (*stack_b)->content
					> ft_lstlast(*stack_a)->content) && (*stack_a))
				ft_pa(stack_a, stack_b, &k);
			else
				search_index(stack_b, arr[size - 1]);
		}
		else if (k > 0 && search_max(*stack_a, arr[size - 1])
			&& ft_lstlast(*stack_a)->content == arr[size - 1])
			ft_rra(stack_a, &size, &k);
	}
	while (k > 0 && size > 0)
		ft_rra(stack_a, &size, &k);
}
