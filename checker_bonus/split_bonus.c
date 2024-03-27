/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:49:40 by wzahir            #+#    #+#             */
/*   Updated: 2024/03/16 13:27:52 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_count_word(char const *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			k++;
		while (s[i] != c && s[i])
			i++;
	}
	return (k);
}

static char	**ft_free(char **p, int word)
{
	while (word > 0)
	{
		word--;
		free(p[word]);
	}
	free(p);
	return (NULL);
}

static char	*ft_fill_words(char *str, char const *s,
		int i, int len_word)
{
	int	j;

	j = 0;
	while (len_word > 0)
	{
		str[j] = s[i - len_word];
		j++;
		len_word--;
	}
	str[j] = '\0';
	return (str);
}

static char	**ft_divide_word(char const *s, char **p, int cw, char c)
{
	int	word;
	int	len_word;
	int	i;

	word = 0;
	i = 0;
	len_word = 0;
	while (word < cw)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			len_word++;
			i++;
		}
		p[word] = malloc(len_word + 1);
		if (!p[word])
			return (ft_free(p, word));
		ft_fill_words(p[word], s, i, len_word);
		len_word = 0;
		word++;
	}
	p[word] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	int		cw;
	char	**p;

	if (!s)
		return (NULL);
	cw = ft_count_word(s, c);
	p = malloc(sizeof(p) * (cw + 1));
	if (!p)
		return (NULL);
	p = ft_divide_word(s, p, cw, c);
	return (p);
}
