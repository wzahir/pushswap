/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzahir <wzahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:55:53 by wzahir            #+#    #+#             */
/*   Updated: 2024/03/10 13:58:31 by wzahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_rd_line(int fd, char *str)
{
	char	*buff;
	int		count_rd;

	buff = malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	count_rd = 1;
	while (!ft_strchr(str, '\n') && count_rd != 0)
	{
		count_rd = read(fd, buff, BUFFER_SIZE);
		if (count_rd < 0)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		buff[count_rd] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

char	*ft_line(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		s[j++] = str[i++];
	if (str[i] == '\n')
	{
		s[j] = '\n';
		j++;
	}
	s[j] = '\0';
	return (s);
}

char	*ft_rest_line(char *str)
{
	size_t	i;
	size_t	j;
	char	*rest;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free (str);
		return (NULL);
	}
	rest = malloc(ft_strlen(str) - i);
	if (!rest)
		return (NULL);
	if (str[i] == '\n')
		i++;
	while (str[i])
		rest[j++] = str[i++];
	rest[j] = '\0';
	free(str);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = ft_rd_line(fd, str);
	if (!str)
		return (NULL);
	line = ft_line(str);
	str = ft_rest_line(str);
	return (line);
}
