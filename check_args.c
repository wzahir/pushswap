/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:02:52 by wzahir            #+#    #+#             */
/*   Updated: 2024/03/20 17:10:20 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_list	*stack)
{
	t_list	*node1;
	t_list	*node2;

	node1 = stack;
	while (node1)
	{
		node2 = node1 -> next;
		while (node2)
		{
			if (node1 -> content == node2 -> content)
				return (0);
			node2 = node2 -> next;
		}
		node1 = node1 -> next;
	}
	return (1);
}

void	full_stack(t_list	**stack, char	**args)
{
	t_list	*node;	
	int		i;

	i = 0;
	while (args[i])
	{
		node = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, node);
		i++;
	}
	return ;
}

int	is_valid_number(char	*args)
{
	int	i;

	i = 0;
	if (args[i] == '-' || args[i] == '+')
		i++;
	if (args[i] == '\0')
		return (0);
	while (args[i])
	{
		if (ft_isdigit(args[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_utile(char **args)
{
	free(args);
	return (0);
}

int	check_args(t_list	**stack_a, char	**av)
{
	char	**args;
	int		i;
	int		j;
	int		count;

	i = 0;
	while (av[++i])
	{
		j = 0;
		args = ft_split(av[i], ' ');
		count = ft_count_word(av[i], ' ');
		if (args[j] == NULL)
			return (ft_utile(args));
		while (args[j])
		{
			if (is_valid_number(args[j]) == 0)
				return (ft_free1(args, count));
			if (ft_atoi(args[j]) < INT_MIN || ft_atoi(args[j]) > INT_MAX)
				return (ft_free1(args, count));
			j++;
		}
		full_stack(stack_a, args);
		ft_free1(args, count);
	}
	return (1);
}
