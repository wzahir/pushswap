/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:43:30 by wzahir            #+#    #+#             */
/*   Updated: 2024/03/20 17:05:38 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	ft_reverse_rotate(char *move, t_list **stack_a, t_list **stack_b)
{
	if (move[0] == 'r' && move[1] == 'r' && move[2] == 'a'
		&& move[3] == '\n')
		rra_bonus(stack_a);
	else if (move[0] == 'r' && move[1] == 'r' && move[2] == 'b'
		&& move[3] == '\n')
		rrb_bonus(stack_b);
	else if (move[0] == 'r' && move[1] == 'r' && move[2] == 'r'
		&& move[3] == '\n')
		rrr_bonus(stack_a, stack_b);
}

int	valide_move(char *move, t_list **stack_a, t_list **stack_b)
{
	if (move[0] == 's' && move[1] == 'a' && move[2] == '\n')
		sa_bonus(stack_a);
	else if (move[0] == 's' && move[1] == 'b' && move[2] == '\n')
		sb_bonus(stack_b);
	else if (move[0] == 's' && move[1] == 's' && move[2] == '\n')
		ss_bonus(stack_a, stack_b);
	else if (move[0] == 'r' && move[1] == 'a' && move[2] == '\n')
		ra_bonus(stack_a);
	else if (move[0] == 'r' && move[1] == 'b' && move[2] == '\n')
		rb_bonus(stack_b);
	else if (move[0] == 'r' && move[1] == 'r' && move[2] == '\n')
		rr_bonus(stack_a, stack_b);
	else if (move[0] == 'p' && move[1] == 'a' && move[2] == '\n')
		pa_bonus(stack_a, stack_b);
	else if (move[0] == 'p' && move[1] == 'b' && move[2] == '\n')
		pb_bonus(stack_a, stack_b);
	else if (move[0] == 'r' && move[1] == 'r'
		&& (move[2] == 'a' || move[2] == 'b' || move[2] == 'r')
		&& move[3] == '\n')
		ft_reverse_rotate(move, stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	read_move(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (valide_move(line, stack_a, stack_b) == 0)
		{
			free(line);
			write(2, "Error\n", 6);
			free_lst(stack_a);
			exit (1);
		}
		free(line);
		line = get_next_line(0);
	}
}

int	main(int ac, char	**av)
{
	t_list	*stack_a;
	t_list	*stack_b;

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
	read_move(&stack_a, &stack_b);
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_lst(&stack_a);
	if (ft_lstsize(stack_b))
		free_lst(&stack_b);
	return (0);
}
