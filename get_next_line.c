/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:09:08 by ychibani          #+#    #+#             */
/*   Updated: 2021/12/02 18:52:13 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char *ft_get_save(char *save)
{
	int i;
	int j;
	char	*new_save;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	while (save[i] && !ft_is_newline(save[i]))
		i++;
	if (!save[i] || !save[i + 1])
	{
		free(save);
		return (0);
	}
	if (save[i])
		i++;
	new_save = (char *)malloc(sizeof(char) * (ft_strlen(save + i) + 1));
	if (!new_save)
		return (0);
	while (save[i])
	{
		new_save[j] = save[i];
		i++;
		j++;
	}
	new_save[j] = 0;
	free(save);
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char *save;
	char 	*buffer;
	char 	*line;
	int ret;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	ret = 1;
	while (ret && !ft_is_line(save))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret <= 0)
			break;
		buffer[ret] = '\0';
		save = ft_gnl_join(save, buffer);
	}
	line = ft_get_line(save);
	save = ft_get_save(save);
	free(buffer);
	return (line);
}