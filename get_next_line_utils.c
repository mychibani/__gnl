/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:09:20 by ychibani          #+#    #+#             */
/*   Updated: 2021/12/02 17:28:49 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int		ft_is_newline(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}
char	*ft_get_line(char *str)
{
	int i;
	char *final_str;

	i = 0;
	if (!str)
		return (NULL);
	final_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!(final_str))
		return (0);
	while(str[i])
	{
		final_str[i] = str[i];
		i++;
		if (str[i - 1] == '\n')
			break ;
	}
	final_str[i] = 0;
	return (final_str);
}

int		ft_is_line(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (ft_is_newline(str[i]))
			return (1);
		i++;
	}
	return (0);
}


char	*ft_gnl_join(char *s1, char *s2)
{
	int i;
	int j;
	char *final_line;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_get_line("");
	if (!s2)
		return (NULL);
	final_line = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!final_line)
		return (0);
	while (s1[i])
	{
		final_line[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		final_line[i] = s2[j];
		i++;
		j++;
	}
	final_line[i] = 0;
	return (free(s1), final_line);
}