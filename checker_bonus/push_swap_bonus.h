/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:31:06 by wzahir            #+#    #+#             */
/*   Updated: 2024/03/16 18:09:41 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

char		*ft_strchr(char *s, int c);
size_t		ft_strlen(char *s);
char		*ft_strdup(char *s);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strjoin(char *s1, char *s2);
char		*get_next_line(int fd);

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

void		sa_bonus(t_list	**stack_a);
void		sb_bonus(t_list	**stack_b);
void		ss_bonus(t_list	**stack_a, t_list	**stack_b);

void		ra_bonus(t_list	**stack_a);
void		rb_bonus(t_list	**stack_b);
void		rr_bonus(t_list	**stack_a, t_list	**stack_b);

void		rra_bonus(t_list	**stack_a);
void		rrb_bonus(t_list	**stack_b);
void		rrr_bonus(t_list	**stack_a, t_list	**stack_b);

void		pa_bonus(t_list	**stack_a, t_list	**stack_b);
void		pb_bonus(t_list	**stack_a, t_list	**stack_b);

#endif
