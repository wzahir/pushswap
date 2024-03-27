/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:17:15 by wzahir            #+#    #+#             */
/*   Updated: 2024/03/20 14:06:26 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_var
{
	int	mid;
	int	offset;
	int	start;
	int	end;
}	t_var;

char		**ft_split(char const *s, char c);
int			ft_count_word(char const *s, char c);
long double	ft_atoi(const char	*str);
int			ft_isdigit(char c);
int			check_args(t_list	**stack_a, char	**av);
int			check_duplicate(t_list	*stack);
void		free_lst(t_list **head);
int			ft_free1(char **args, int i);

t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);

void		sa(t_list	**stack_a);
void		sb(t_list	**stack_b);
void		ss(t_list	**stack_a, t_list	**stack_b);

void		ra(t_list	**stack_a);
void		rb(t_list	**stack_b);
void		rr(t_list	**stack_a, t_list	**stack_b);

void		rra(t_list	**stack_a);
void		rrb(t_list	**stack_b);
void		rrr(t_list	**stack_a, t_list	**stack_b);

void		pa(t_list	**stack_a, t_list	**stack_b);
void		pb(t_list	**stack_a, t_list	**stack_b);

void		sort_2(t_list	**stack);
void		sort_3(t_list	**stack);
void		sort_4(t_list	**stack_a, t_list	**stack_b);
void		sort_5(t_list	**stack_a, t_list	**stack_b);
int			is_sorted(t_list	*stack);
void		sort_tab(int *tab, int size);
void		algo_sort(t_list **stack_a, t_list **stack_b, int size);
void		push_to_b(t_list **stack_a, t_list **stack_b, int *arr, int size);

void		put_index(t_list	**stack);
int			index_max(t_list *stack, int max);
void		search_index(t_list **stack, int max);
int			search_max(t_list *stack, int max);
void		push_max(t_list **stack_a, t_list **stack_b, int max);
void		push_to_a(t_list **stack_a, t_list	**stack_b, int	*arr, int size);

#endif
