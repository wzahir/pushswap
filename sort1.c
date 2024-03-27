/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:34:46 by wzahir            #+#    #+#             */
/*   Updated: 2024/03/20 14:02:37 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_list	*stack)
{
	int		max;
	t_list	*node;

	node = stack;
	if (!stack)
		return (0);
	max = node -> content;
	while (node)
	{
		if (node->next != NULL && max < node->next->content)
			max = node->next->content;
		node = node->next;
	}
	return (max);
}

void	sort_2(t_list	**stack)
{
	if ((*stack)->content > (*stack)->next->content)
		sa(stack);
	else
		return ;
}

void	sort_3(t_list	**stack)
{
	if ((*stack)->content == max(*stack))
		ra(stack);
	else if ((*stack)->next->content == max(*stack))
		rra(stack);
	sort_2(stack);
}
