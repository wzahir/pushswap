/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:17:41 by wzahir            #+#    #+#             */
/*   Updated: 2024/03/20 17:41:10 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorted(t_list	**stack_a, t_list	**stack_b, int size)
{
	if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else
		algo_sort(stack_a, stack_b, size);
}

int	is_sorted(t_list	*stack)
{
	t_list	*node;

	node = stack;
	while (node != NULL && node->next != NULL)
	{
		if (node->content > (node -> next)->content)
			return (0);
		node = node -> next;
	}
	return (1);
}

int	main(int ac, char	**av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (check_args(&stack_a, av) == 0 || check_duplicate(stack_a) == 0)
	{
		write(2, "Error\n", 6);
		free_lst(&stack_a);
		return (0);
	}
	size = ft_lstsize(stack_a);
	if (is_sorted(stack_a) == 1)
	{
		free_lst(&stack_a);
		return (0);
	}
	else
		ft_sorted(&stack_a, &stack_b, size);
	free_lst(&stack_a);
	return (0);
}
