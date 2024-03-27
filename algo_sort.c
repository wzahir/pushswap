/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 22:14:27 by wzahir            #+#    #+#             */
/*   Updated: 2024/03/18 22:49:37 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tab(int *tab, int size)
{
	int	j;
	int	i;
	int	swap;

	j = 0;
	while (j < size)
	{
		i = j + 1;
		while (i < size)
		{
			if (tab[j] > tab[i])
			{
				swap = tab[j];
				tab[j] = tab[i];
				tab[i] = swap;
			}
			i++;
		}
		j++;
	}
}

int	*full_array(int	*arr, t_list *stack, int size)
{
	int		i;

	i = 0;
	while (stack && i < size)
	{
		arr[i] = stack -> content;
		stack = stack -> next;
		i++;
	}
	return (arr);
}

void	algo_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	*arr;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	arr = full_array(arr, *stack_a, size);
	sort_tab(arr, size);
	push_to_b(stack_a, stack_b, arr, size);
	push_to_a(stack_a, stack_b, arr, size);
	free(arr);
}
