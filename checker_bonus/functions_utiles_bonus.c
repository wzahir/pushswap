/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utiles_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:54:17 by wzahir            #+#    #+#             */
/*   Updated: 2024/03/20 17:07:20 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

long double	ft_atoi(const char *str)
{
	int				i;
	long double		nb;
	int				s;

	nb = 0;
	s = 1;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		s = -s;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * s);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	free_lst(t_list **head)
{
	t_list	*node;

	while (*head)
	{
		node = *head;
		*head = (*head)->next;
		free(node);
	}
}

int	ft_free1(char **args, int i)
{
	while (i > 0)
	{
		i--;
		free(args[i]);
	}
	free(args);
	return (0);
}
